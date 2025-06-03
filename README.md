# C++ Project with CMake and CppUnit

This project demonstrates a simple C++ application with CMake build system and CppUnit testing framework integration.

## Project Structure

```
CICD_CPP/
├── CMakeLists.txt           # Root CMake configuration
├── cmake/
│   └── modules/
│       └── FindCppUnit.cmake  # Custom CMake module for CppUnit
├── src/
│   ├── CMakeLists.txt      # Source build configuration
│   └── hello.cpp           # Main application source
├── tests/
│   ├── CMakeLists.txt      # Test build configuration
│   └── helloTest.cpp       # Test source code
└── build/                  # Build output directory
```

## Prerequisites

- CMake (3.10 or higher)
- C++ Compiler (GCC/MinGW)
- CppUnit library

### Windows with MSYS2
```powershell
# Install CppUnit using MSYS2
pacman -S mingw-w64-ucrt-x86_64-cppunit
```

### Linux
```bash
# Install CppUnit
sudo apt-get update
sudo apt-get install -y libcppunit-dev
```

## Building the Project

1. Configure CMake:
```powershell
# For Windows with MinGW
cmake -G "MinGW Makefiles" -B build -DCMAKE_BUILD_TYPE=Release

# For Linux
cmake -B build -DCMAKE_BUILD_TYPE=Release
```

2. Build the project:
```powershell
cmake --build build
```

## Running Tests

From the project root directory:
```powershell
cd build
ctest --output-on-failure
```

## Continuous Integration

This project uses GitHub Actions for CI/CD. The workflow:
- Builds the project on Ubuntu Linux
- Runs the test suite
- Triggers on:
  - Push to main branch
  - Pull requests to main branch

See `.github/workflows/cmake.yml` for the complete workflow configuration.

## Project Components

### Main Application
- Located in `src/hello.cpp`
- Simple "Hello, World!" application
- Built as both a library and executable

### Tests
- Located in `tests/helloTest.cpp`
- Uses CppUnit testing framework
- Verifies basic application functionality

### CMake Configuration
- Modular CMake setup
- Custom FindCppUnit module
- Separate build configurations for source and tests

## License

This project is open source and available under the MIT License.
