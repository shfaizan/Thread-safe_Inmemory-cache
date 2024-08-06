#ifndef CACHE_H
#define CACHE_H

#include <unordered_map>
#include <list>
#include <mutex>
#include <chrono>
#include <functional>

template <typename Key, typename Value>
class Cache {
public:
    using Clock = std::chrono::steady_clock;
    using TimePoint = Clock::time_point;

    struct CacheEntry {
        Key key;
        Value value;
        TimePoint expiration;
    };

    Cache(size_t capacity, std::chrono::seconds defaultExpiration);
    ~Cache() = default;

    void put(const Key& key, const Value& value, std::chrono::seconds expiration = std::chrono::seconds::zero());
    bool get(const Key& key, Value& value);
    void remove(const Key& key);
    void clear();

private:
    size_t capacity_;
    std::chrono::seconds defaultExpiration_;
    std::unordered_map<Key, typename std::list<CacheEntry>::iterator> cacheMap_;
    std::list<CacheEntry> cacheList_;
    std::mutex cacheMutex_;

    void evictExpired();
    void evictIfNecessary();
};

#include "Cache.tpp" // Template implementation
#endif // CACHE_H
