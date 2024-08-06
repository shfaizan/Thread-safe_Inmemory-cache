#include "Cache.h"

template <typename Key, typename Value>
Cache<Key, Value>::Cache(size_t capacity, std::chrono::seconds defaultExpiration)
    : capacity_(capacity), defaultExpiration_(defaultExpiration) {}

template <typename Key, typename Value>
void Cache<Key, Value>::put(const Key& key, const Value& value, std::chrono::seconds expiration) {
    std::lock_guard<std::mutex> lock(cacheMutex_);
    evictExpired();

    auto now = Clock::now();
    auto exp = (expiration == std::chrono::seconds::zero()) ? now + defaultExpiration_ : now + expiration;

    if (cacheMap_.find(key) != cacheMap_.end()) {
        cacheList_.erase(cacheMap_[key]);
    }

    cacheList_.push_front({key, value, exp});
    cacheMap_[key] = cacheList_.begin();

    evictIfNecessary();
}

template <typename Key, typename Value>
bool Cache<Key, Value>::get(const Key& key, Value& value) {
    std::lock_guard<std::mutex> lock(cacheMutex_);
    evictExpired();

    if (cacheMap_.find(key) == cacheMap_.end()) {
        return false;
    }

    auto entry = cacheMap_[key];
    value = entry->value;

    // Move the accessed entry to the front
    cacheList_.splice(cacheList_.begin(), cacheList_, entry);
    return true;
}

template <typename Key, typename Value>
void Cache<Key, Value>::remove(const Key& key) {
    std::lock_guard<std::mutex> lock(cacheMutex_);
    if (cacheMap_.find(key) != cacheMap_.end()) {
        cacheList_.erase(cacheMap_[key]);
        cacheMap_.erase(key);
    }
}

template <typename Key, typename Value>
void Cache<Key, Value>::clear() {
    std::lock_guard<std::mutex> lock(cacheMutex_);
    cacheList_.clear();
    cacheMap_.clear();
}

template <typename Key, typename Value>
void Cache<Key, Value>::evictExpired() {
    auto now = Clock::now();
    while (!cacheList_.empty() && cacheList_.back().expiration <= now) {
        cacheMap_.erase(cacheList_.back().key);
        cacheList_.pop_back();
    }
}

template <typename Key, typename Value>
void Cache<Key, Value>::evictIfNecessary() {
    while (cacheList_.size() > capacity_) {
        cacheMap_.erase(cacheList_.back().key);
        cacheList_.pop_back();
    }
}
