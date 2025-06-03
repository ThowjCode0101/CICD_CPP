cmake_minimum_required(VERSION 3.10)
project(HelloWorld VERSION 1.0)

# Force MinGW compiler
set(CMAKE_C_COMPILER "C:/msys64/ucrt64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")

# Enable testing for the project
enable_testing()

# Set CMake module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)