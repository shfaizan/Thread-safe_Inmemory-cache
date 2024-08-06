# Thread-safe In-Memory Cache with Expiration and Eviction Policies

This project implements a thread-safe in-memory cache with expiration and eviction policies in C++. The cache supports storing key-value pairs, retrieving values, automatic expiration of entries, and eviction based on capacity.

## Features

- **Thread-safe**: Multiple threads can safely interact with the cache concurrently.
- **Expiration**: Entries automatically expire after a specified duration.
- **Eviction**: Least recently used (LRU) entries are evicted when the cache exceeds its capacity.
- **Customizable Expiration**: Each entry can have a custom expiration time.
- **Clear Cache**: Ability to clear all cache entries.

## Project Structure

- `Cache.h`: Header file for the Cache class.
- `Cache.cpp`: Implementation of the Cache class.
- `main.cpp`: Main driver code for the project.
- `Makefile`: Makefile to compile the project.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++)
- Make utility

### Building the Project

1. Clone the repository or download the project files.
2. Navigate to the project directory.
3. Run the following command to compile the project:

    ```sh
    make
    ```

### Running the Project

1. After building the project, run the executable:

    ```sh
    ./ThreadSafeCache
    ```

2. The program will demonstrate basic usage of the cache.

Here's the text formatted in proper markdown:


# ThreadSafeCache

```sh
$ ./ThreadSafeCache
Key1 not found (evicted).
Key2: value2
Key2 not found (expired).
Key3: value3
```

## File Descriptions

* **Cache.h**: Defines the `Cache` class and its member functions for putting, getting, removing, and clearing cache entries.
* **Cache.cpp**: Implements the `Cache` class methods.
* **main.cpp**: Provides a simple interface to demonstrate the functionality of the `Cache` class.
* **Makefile**: A script to compile the project files.

## Classes and Functions

### Cache Class

* **Cache(size_t capacity, std::chrono::seconds defaultExpiration)**: Constructor to initialize the cache with a given capacity and default expiration time.
* **put(const Key& key, const Value& value, std::chrono::seconds expiration = std::chrono::seconds::zero())**: Puts a key-value pair into the cache with an optional expiration time.
* **get(const Key& key, Value& value)**: Retrieves the value associated with the key if it exists and is not expired.
* **remove(const Key& key)**: Removes the key-value pair from the cache.
* **clear()**: Clears all entries in the cache.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

* This project is inspired by the need for efficient in-memory caching mechanisms.
* The implementation demonstrates thread-safe programming and cache management techniques in C++.


This project demonstrates advanced C++ concepts like multi-threading, data structures (u
