enable_testing()

# Find CppUnit package
find_package(CppUnit REQUIRED)

# Add the test executable
add_executable(hello_test helloTest.cpp)

# Link against the main library and CppUnit
target_link_libraries(hello_test 
    PRIVATE 
    hello_lib
    CppUnit::CppUnit
)

# Add the test
add_test(
    NAME HelloTest 
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/hello_test${CMAKE_EXECUTABLE_SUFFIX}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)