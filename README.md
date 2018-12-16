# hiredisx

![License](https://img.shields.io/badge/license-MIT-blue.svg)
[![Build Status](https://travis-ci.org/ChrisCates/hiredisx.svg?branch=master)](https://travis-ci.org/ChrisCates/hiredisx)
[![codecov](https://codecov.io/gh/ChrisCates/hiredisx/branch/master/graph/badge.svg)](https://codecov.io/gh/ChrisCates/hiredisx)
![C++ Standard](https://img.shields.io/badge/cmake%20standard-C++%2011-blue.svg)
![CMake](https://img.shields.io/badge/cmake%20version-3.7-blue.svg)

The core intention of the hiredisx library is to create an easier to use threadsafe version of hiredis. Hiredis is very non-prescriptive, making almost no assumptions of your environment. On the otherhand, hiredisx provides some nice easy to use functions for interacting with hiredis that are completely threadsafe and allow for parallel computing... While, also allowing you to interact with redis through the `redisx::op::command` function.

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

## Example usage with CMake

You can pop this into your existing `.cmake` or `CMakeLists.txt`:

```cmake
IF (NOT HIREDISX_INCLUDE_DIRS)
  MESSAGE("-- Setting default HiredisX Include Directory")
  SET(HIREDISX_INCLUDE_DIRS "/usr/local/include/hiredisx")
ENDIF (NOT HIREDISX_INCLUDE_DIRS)

MESSAGE("-- HIREDISX_INCLUDE_DIRS\t" ${HIREDISX_INCLUDE_DIRS})

INCLUDE_DIRECTORIES(${HIREDISX_INCLUDE_DIRS})
LINK_DIRECTORIES(${HIREDISX_INCLUDE_DIRS})
```

Then interacting with hiredisx is as simple as just adding:

```c++
#include "hiredisx.hpp"
```

## Example Usage

**Standard Usage:**

```c++
bool validConnection = hiredisx::canConnect();

if (validConnection) {
    bool set = hiredisx::set("foo", "bar"); // True if set

    std::string foo = hiredisx::get("foo"); // "bar" if correct

    bool deleted = hiredisx::del("foo"); // True if deleted

    bool pushed = hiredisx::push("list", "yo", "R"); // True if pushed to list. Note that "R" means Right append, "L" means Left append.

    std::vector<std::string> list = hiredisx::getList("list");
}
```

**Modifying Connection Options:**

You can modify the connection options by changing the `hiredisx::options` struct.

```c++
// Below are default and modifyable options for hiredisx
hiredisx::options.host = "localhost";
hiredisx::options.port = 6379;
hiredisx::options.timeoutS = 5; // Timeout in seconds
hiredisx::options.timeoutNS = 0; // Timeout in nanoseconds
```

## Additional Resources

- If you are interested in contributing or want to get in contact. Email me at :mailbox: hello@chriscates.ca
