# FindCppUnit.cmake

# Find the CppUnit includes
find_path(CPPUNIT_INCLUDE_DIR 
    NAMES cppunit/TestCase.h
    PATHS
    C:/msys64/ucrt64/include
    /usr/include
    /usr/local/include
)

# Find the CppUnit libraries
find_library(CPPUNIT_LIBRARY
    NAMES cppunit libcppunit
    PATHS
    C:/msys64/ucrt64/lib
    /usr/lib
    /usr/lib/x86_64-linux-gnu
    /usr/local/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CppUnit
    FOUND_VAR CPPUNIT_FOUND
    REQUIRED_VARS
        CPPUNIT_LIBRARY
        CPPUNIT_INCLUDE_DIR
)

if(CPPUNIT_FOUND AND NOT TARGET CppUnit::CppUnit)
    add_library(CppUnit::CppUnit UNKNOWN IMPORTED)
    set_target_properties(CppUnit::CppUnit PROPERTIES
        IMPORTED_LOCATION "${CPPUNIT_LIBRARY}"
        INTERFACE_INCLUDE_DIRECTORIES "${CPPUNIT_INCLUDE_DIR}"
    )
endif()
