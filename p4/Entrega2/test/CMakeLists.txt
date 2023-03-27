add_executable(testApp test.c)
 
target_link_libraries(testApp src unity)
 
# Add a test to the project to be run by ctest(1).
add_test(LibTest testApp)
