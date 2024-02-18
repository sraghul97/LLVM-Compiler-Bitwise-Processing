# CMake generated Testfile for 
# Source directory: /ece566/projects/p1/c++
# Build directory: /ece566/projects/p1/c++/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Usage "/ece566/projects/p1/c++/build/p1")
set_tests_properties(Usage PROPERTIES  PASS_REGULAR_EXPRESSION "Usage:" _BACKTRACE_TRIPLES "/ece566/projects/p1/c++/CMakeLists.txt;34;add_test;/ece566/projects/p1/c++/CMakeLists.txt;0;")
subdirs("tests")
