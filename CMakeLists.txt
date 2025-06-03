cmake_minimum_required(VERSION 3.10)
project(HelloWorld VERSION 1.0)

# Enable testing for the project
enable_testing()

# Set CMake module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

# Set compiler based on platform
if(WIN32)
    # For Windows with MinGW
    find_program(MINGW_GCC "gcc.exe" PATHS "C:/msys64/ucrt64/bin" REQUIRED)
    find_program(MINGW_GPP "g++.exe" PATHS "C:/msys64/ucrt64/bin" REQUIRED)
    if(MINGW_GCC AND MINGW_GPP)
        set(CMAKE_C_COMPILER ${MINGW_GCC})
        set(CMAKE_CXX_COMPILER ${MINGW_GPP})
    endif()
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)