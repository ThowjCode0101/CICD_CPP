include(FetchContent)
set(CMAKE_POLICY_DEFAULT_CMP0135 NEW)
FetchContent_Declare(gtest
  QUIET
  URL https://github.com/google/googletest/releases/download/v1.16.0/googletest-1.16.0.tar.gz
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# configure build of googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)

add_executable(
    unit_tests
    example_add.cpp
    example_subtract.cpp
    GTest_example.cpp
    example_test.cpp
    )

target_link_libraries(unit_tests
  PRIVATE
    example
    gtest_main
  )

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(unit_tests
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
    240
  )
