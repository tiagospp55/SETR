# file is a command decicate to file and path manipulations 
#   GLOB: Generate a list of files that match the expression (./*.c) 
#   and store it into a variable (SOURCES)
file(GLOB SOURCES ./*.c)

add_library(src STATIC ${SOURCES})
 
target_include_directories(src PUBLIC .)
