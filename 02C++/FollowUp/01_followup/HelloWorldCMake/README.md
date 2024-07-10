# CMake Readme

## Basics
- CMake is an open-source, cross-platform family of tools designed to build, test, and package software. 
- Here, we'll explore various aspects of CMake, providing small examples for each topic.

### Basic CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)
add_executable(HelloWorld main.cpp)
```
### main.cpp:

```cpp
#include <iostream>
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```
- for building 
```bash
mkdir build
cd build
cmake ..
make
```

## Include Directories
- Specify directories to be searched for header files during compilation.

```cmake
include_directories(include)

add_executable(HelloWorld main.cpp)
```

## Message, Set, and If
- Display messages, set variables, and use conditional statements.

```cmake
set(MY_VAR "Hello")

if(MY_VAR STREQUAL "Hello")
    message(STATUS "MY_VAR is Hello")
endif()
```

## add_library
Create a library from source files.

```cmake
add_library(MyLib STATIC mylib.cpp)
add_executable(HelloWorld main.cpp)
target_link_libraries(HelloWorld MyLib)
```

## add_subdirectory
- Include another CMake project.

```cmake
add_subdirectory(subdir)
```

## target_link_libraries
- Link libraries to your target.

```cmake
add_executable(HelloWorld main.cpp)
target_link_libraries(HelloWorld MyLib)
```
## Built-in Variables
- Commonly used CMake built-in variables.
 
```cmake
message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "Project source dir: ${PROJECT_SOURCE_DIR}")
```
## configure_file
- Generate files during the build process.

```cmake
configure_file(config.h.in config.h)
```
## config.h.in:

```cpp
#define PROJECT_VERSION_MAJOR @PROJECT_VERSION_MAJOR@
#define PROJECT_VERSION_MINOR @PROJECT_VERSION_MINOR@
```

## foreach
- Iterate over a list of values.

```cmake
set(SOURCES main.cpp mylib.cpp)
foreach(source ${SOURCES})
    message(STATUS "Source file: ${source}")
endforeach()
```

## function
- Define reusable functions.

```cmake
function(print_message MESSAGE)
    message(STATUS ${MESSAGE})
endfunction()
print_message("Hello from function")
```

## CMakeCache.txt
- The CMake cache stores configuration options.

## compile_options
- Set compile options for a target.

```cmake
add_executable(HelloWorld main.cpp)
target_compile_options(HelloWorld PRIVATE -Wall -Wextra)
```

## install
- Specify installation rules.

```cmake
install(TARGETS HelloWorld DESTINATION bin)
```
## FILE, STRING, execute_process
- Perform file operations, string manipulations, and execute commands.

```cmake
file(WRITE myfile.txt "Hello, World!")
string(TOUPPER "hello" UPPER_HELLO)
execute_process(COMMAND echo "Hello from command")
```

## find_package
- Locate and configure external dependencies.

```cmake
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(HelloWorld ${OpenCV_LIBS})
```

## CMake with ATmega32 Example
```cmake
cmake_minimum_required(VERSION 3.10)
project(ATmega32Project)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_C_FLAGS "-mmcu=atmega32 -Os")

add_executable(ATmega32Project main.c)
```

## CMake with Raspberry Pi 4 Example
```cmake
cmake_minimum_required(VERSION 3.10)
project(RPi4Project)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

add_executable(RPi4Project main.cpp)
```
## CMake with Doxygen
G- enerate documentation with Doxygen.

```cmake
find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_custom_target(doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM)
endif()
```

## CMake with GTest
- Integrate Google Test for unit testing.

```cmake
find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS})

add_executable(HelloWorldTest test.cpp)
target_link_libraries(HelloWorldTest ${GTest_LIBRARIES} pthread)
```

## List
- Manipulate lists in CMake.

```cmake
set(MY_LIST a b c)
list(APPEND MY_LIST d)
message(STATUS "List contents: ${MY_LIST}")
```
## pkg_search_module
- Find and configure packages.

```cmake
pkg_search_module(GLIB REQUIRED glib-2.0)
include_directories(${GLIB_INCLUDE_DIRS})
target_link_libraries(HelloWorld ${GLIB_LIBRARIES})
```
## CMake Toolchain
- Specify a toolchain file for cross-compilation.

```cmake
set(CMAKE_TOOLCHAIN_FILE toolchain.cmake)
```

### toolchain.cmake:

```cmake
set(CMAKE_SYSTEM_NAME Linux)
Copy code
set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
```
## CMake Create Package
- Package your project for distribution.

```cmake
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "HelloWorld")
set(CPACK_PACKAGE_VERSION "1.0.0")
include(CPack)
```

## CMake Yocto Package
- Integrate CMake with Yocto for embedded Linux development.

```cmake
set(YOCTO_SDK_ROOT /opt/poky)
set(CMAKE_TOOLCHAIN_FILE ${YOCTO_SDK_ROOT}/environment-setup-cortexa9hf-vfp-neon-poky-linux-gnueabi)
```