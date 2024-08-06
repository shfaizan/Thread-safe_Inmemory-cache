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

### Example

```sh
$ ./ThreadSafeCache
Key1 not found (evicted).
Key2: value2
Key2 not found (expired).
Key3: value3
