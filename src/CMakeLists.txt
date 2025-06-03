# Add the library
add_library(hello_lib STATIC hello.cpp)
target_include_directories(hello_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add the executable
add_executable(hello_app hello.cpp)
target_link_libraries(hello_app PRIVATE hello_lib)