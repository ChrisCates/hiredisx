# hiredisx

![License](https://img.shields.io/badge/license-MIT-blue.svg)
[![Build Status](https://travis-ci.org/ChrisCates/hiredisx.svg?branch=master)](https://travis-ci.org/ChrisCates/hiredisx)
[![codecov](https://codecov.io/gh/ChrisCates/hiredisx/branch/master/graph/badge.svg)](https://codecov.io/gh/ChrisCates/hiredisx)
![C++ Standard](https://img.shields.io/badge/cmake%20standard-C++%2011-blue.svg)
![CMake](https://img.shields.io/badge/cmake%20version-3.7-blue.svg)

The core intention of the hiredisx library is to create an easier to use threadsafe, atomic version of hiredis. Hiredis is very non-prescriptive, making almost no assumptions of your environment. On the otherhand, hiredisx makes assumptions of your workflow, allowing you to run commands through an atomic binded context.

## Requirements

1. [hiredis](https://github.com/redis/hiredis)

2. [CMake and Make](https://cmake.org/) (>=3.7)

## Building and Installing

**1. Make the build directory**

```bash
mkdir build
cd build
```

**2. Run cmake and make:**

```bash
cmake ..
make
```

**3. Install the header libraries**

```bash
make install
```

## Example Usage

**Standard Usage:**

```c++
bool opened = hiredisx::connect();

if (opened) {
    bool set = hiredisx::set("foo", "bar"); // True if set

    std::string foo = hiredisx::get("foo"); // "bar" if correct

    bool deleted = hiredisx::del("foo"); // True if deleted

    bool pushed = hiredisx::push("list", "yo", "R"); // True if pushed to list. Note that "R" means Right append, "L" means Left append.

    std::vector<std::string> list = hiredisx::getList("list");
} else {
    std::cout << "Error" << std::endl;
}
```

*If for whatever reason you need to access the context object, say, for debugging purposes. You can always access it atomically by doing:*

```c++
redisContext* context = hiredisx::context.load(std::memory_order_acquire);
```

## Additional Resources

- If you are interested in contributing or want to get in contact. Email me at :mailbox: hello@chriscates.ca
