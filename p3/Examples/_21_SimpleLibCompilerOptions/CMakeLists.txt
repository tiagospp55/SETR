# CMakeLists.txt: example for developing modular SW
# Paulo Pedreiras, 2023/Apr
#     Example where compile options are used.
#     Compiler options can be set at module/target level (as in this case) or
#       at a global level (to all modules/target) that are part of the application
#     This is preferable to assure consistency e..g in ABI, error detection, ... 
#     E.g. the following excerpt can be added at the top of the CMakeLists.txt 
#       (after the project() command)  
#		-------------------------------------------
#		if(MSVC)
#			add_compile_options(/W3 /WX)
#		else()
#			add_compile_options(-W -Wall -Werror)
#		endif()
#		-------------------------------------------
#

# Set CMAKE minimum required version 
cmake_minimum_required(VERSION 3.10)

# set the project name
project(LibExample VERSION 1.0
                  DESCRIPTION "Showing how to develop modular software "
                  LANGUAGES C)

# Add the MovAvgLib folder to the build
# CMake will look for a CMakeLists.txt in that folder and will process it
add_subdirectory(MovAvgLibFolder)

# Generate executable "libdemo" from source file "main.c"
add_executable(libdemo src/main.c)

# Generate variables with set of libs and include folders
# Dependencies for libraries files are automatically set 
list(APPEND EXTRA_LIBS MovAvgLib)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MovAvgLibFolder")

# Specify libraries or flags to use when linking a given target 
# and/or its dependents
target_link_libraries(libdemo PRIVATE ${EXTRA_LIBS})

# Specifies include directories to use when compiling a given target
target_include_directories(libdemo PRIVATE ${EXTRA_INCLUDES})

# Set compiler options for module
target_compile_options(libdemo
	PRIVATE
    -Wall
    -Wextra
)
	
