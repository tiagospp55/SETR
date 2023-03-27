cmake_minimum_required(VERSION 3.1)
project(Entrega2) 

# Set the output directory (optional))
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Add CTest, which is the CMake test driver program
include(CTest)

# Add directory with the source code to test, Unity and test code
add_subdirectory(src) 
add_subdirectory(unity) 
add_subdirectory(test) 
