# doxygen_add_docs adds a target for generating documentation with Doxygen. 
# It provides reasonable defaults so that users can generally just 
#     provide the input files and directories.
# But the function supports the ability to customize the Doxygen configuration
#     used to build the documentation.
# See documentation in:
# https://cmake.org/cmake/help/latest/module/FindDoxygen.html?highlight=doxygen_add_docs#command:doxygen_add_docs

# set a few options 
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

# set the documentation target name and files to include
doxygen_add_docs(LibDemoDoc "${PROJECT_SOURCE_DIR}/docs/mainpage.md"
                 "${PROJECT_SOURCE_DIR}/MovAvgLibFolder")

