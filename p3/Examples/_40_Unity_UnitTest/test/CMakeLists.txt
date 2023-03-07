add_executable(testMyVectorLibApp testMyVectorLib.c)
 
target_link_libraries(testMyVectorLibApp src unity)
 
# Add a test to the project to be run by ctest(1).
add_test(MyVectorLibTest testMyVectorLibApp)
