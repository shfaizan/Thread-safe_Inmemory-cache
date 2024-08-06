#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Cache.h"

void testCache() {
    Cache<std::string, std::string> cache(3, std::chrono::seconds(5));

    cache.put("key1", "value1");
    cache.put("key2", "value2");
    cache.put("key3", "value3");

    std::this_thread::sleep_for(std::chrono::seconds(2));
    cache.put("key4", "value4"); // This should evict key1

    std::string value;
    if (cache.get("key1", value)) {
        std::cout << "Key1: " << value << std::endl;
    } else {
        std::cout << "Key1 not found (evicted)." << std::endl;
    }

    if (cache.get("key2", value)) {
        std::cout << "Key2: " << value << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(4));
    if (cache.get("key2", value)) {
        std::cout << "Key2: " << value << std::endl;
    } else {
        std::cout << "Key2 not found (expired)." << std::endl;
    }

    if (cache.get("key3", value)) {
        std::cout << "Key3: " << value << std::endl;
    }
}

int main() {
    testCache();
    return 0;
}
