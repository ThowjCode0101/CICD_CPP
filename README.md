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

### Windows Setup

1. Install MSYS2:
```cmd
choco install -y msys2
```

2. Install required packages:
```cmd
C:\msys64\usr\bin\pacman.exe -Syu --noconfirm
C:\msys64\usr\bin\pacman.exe -S --noconfirm mingw-w64-ucrt-x86_64-gcc
C:\msys64\usr\bin\pacman.exe -S --noconfirm mingw-w64-ucrt-x86_64-cppunit
```

3. Add MinGW to PATH:
```cmd
set PATH=C:\msys64\ucrt64\bin;%PATH%
```

### Linux Setup
```bash
# Update package list and install required packages
sudo apt-get update
sudo apt-get install -y build-essential cmake libcppunit-dev
```

## Building the Project

### Windows (Command Prompt)

1. Configure CMake:
```cmd
if exist build rd /s /q build
cmake -G "MinGW Makefiles" -B build -DCMAKE_BUILD_TYPE=Release
```

2. Build:
```cmd
cmake --build build --config Release
```

### Linux

1. Configure CMake:
```bash
rm -rf build
cmake -B build -DCMAKE_BUILD_TYPE=Release
```

2. Build:
```bash
cmake --build build --config Release
```

## Running Tests

### Windows (Command Prompt)
```cmd
cd build
ctest --output-on-failure -C Release
cd ..
```

### Linux
```bash
cd build
ctest --output-on-failure -C Release
cd ..
```

## Continuous Integration

This project uses GitHub Actions for CI/CD with separate workflows for Windows and Linux:

### Windows Workflow
- Uses MSYS2 and MinGW-w64 toolchain
- Builds the project on Windows
- Runs the test suite
- Located in `.github/workflows/windows.yml`

### Linux Workflow
- Uses GCC and APT package manager
- Builds the project on Ubuntu Linux
- Runs the test suite
- Located in `.github/workflows/linux.yml`

Triggers for both workflows:
- Push to main branch
- Pull requests to main branch
- Manual trigger (workflow_dispatch)

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
