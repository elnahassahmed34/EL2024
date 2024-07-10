cmake_minimum_required(VERSION 3.10)

# Project name and version
project(HelloWorld VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable target
add_executable(a.out main.cpp)

