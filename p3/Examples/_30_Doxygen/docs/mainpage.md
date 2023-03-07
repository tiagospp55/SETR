CMake Doxygen documentation generation example

Paulo Pedreiras (pbrp@ua.pt), 2022/04

DETI/UA/IT

# How to generate the documentation

Assuming that build directory is "build" and that it already exists

1. cmake -S . -B build -DGENERATE_DOC=ON 

>S: source files; -B build directory; GENERATE_DOCS={ON,OFF})

2. cd build
3. make LibDemoDoc

Doc files are placed in "build/docs"


Step 1 can be replaced by the use of cmake-gui or ccmake

