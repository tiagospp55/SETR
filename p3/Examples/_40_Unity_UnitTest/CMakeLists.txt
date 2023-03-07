cmake_minimum_required(VERSION 3.1)
project(UnitTestDemo) 

# Set the output directory (optional))
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Add CTest, which is the CMake test driver program
include(CTest)

# Add directory with the source code to test, Unity and test code
add_subdirectory(src) 
add_subdirectory(unity_src) 
add_subdirectory(test) 
