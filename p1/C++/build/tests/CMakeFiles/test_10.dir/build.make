# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /ece566/projects/p1/c++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /ece566/projects/p1/c++/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_10.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/test_10.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_10.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_10.dir/flags.make

tests/test_10.bc.o: tests/test_10.bc
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/ece566/projects/p1/c++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating test_10.bc.o"
	cd /ece566/projects/p1/c++/build/tests && clang-17 -c -o /ece566/projects/p1/c++/build/tests/test_10.bc.o /ece566/projects/p1/c++/build/tests/test_10.bc

tests/test_10.bc: p1
tests/test_10.bc: /ece566/projects/p1/c++/tests/test_10.p1
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/ece566/projects/p1/c++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating test_10.bc"
	cd /ece566/projects/p1/c++/build/tests && ../p1 /ece566/projects/p1/c++/tests/test_10.p1 /ece566/projects/p1/c++/build/tests/test_10.bc

tests/CMakeFiles/test_10.dir/test_10.c.o: tests/CMakeFiles/test_10.dir/flags.make
tests/CMakeFiles/test_10.dir/test_10.c.o: /ece566/projects/p1/c++/tests/test_10.c
tests/CMakeFiles/test_10.dir/test_10.c.o: tests/CMakeFiles/test_10.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/ece566/projects/p1/c++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/CMakeFiles/test_10.dir/test_10.c.o"
	cd /ece566/projects/p1/c++/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/test_10.dir/test_10.c.o -MF CMakeFiles/test_10.dir/test_10.c.o.d -o CMakeFiles/test_10.dir/test_10.c.o -c /ece566/projects/p1/c++/tests/test_10.c

tests/CMakeFiles/test_10.dir/test_10.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_10.dir/test_10.c.i"
	cd /ece566/projects/p1/c++/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /ece566/projects/p1/c++/tests/test_10.c > CMakeFiles/test_10.dir/test_10.c.i

tests/CMakeFiles/test_10.dir/test_10.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_10.dir/test_10.c.s"
	cd /ece566/projects/p1/c++/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /ece566/projects/p1/c++/tests/test_10.c -o CMakeFiles/test_10.dir/test_10.c.s

# Object files for target test_10
test_10_OBJECTS = \
"CMakeFiles/test_10.dir/test_10.c.o"

# External object files for target test_10
test_10_EXTERNAL_OBJECTS = \
"/ece566/projects/p1/c++/build/tests/test_10.bc.o"

tests/test_10: tests/CMakeFiles/test_10.dir/test_10.c.o
tests/test_10: tests/test_10.bc.o
tests/test_10: tests/CMakeFiles/test_10.dir/build.make
tests/test_10: tests/CMakeFiles/test_10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/ece566/projects/p1/c++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable test_10"
	cd /ece566/projects/p1/c++/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_10.dir/build: tests/test_10
.PHONY : tests/CMakeFiles/test_10.dir/build

tests/CMakeFiles/test_10.dir/clean:
	cd /ece566/projects/p1/c++/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_10.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_10.dir/clean

tests/CMakeFiles/test_10.dir/depend: tests/test_10.bc
tests/CMakeFiles/test_10.dir/depend: tests/test_10.bc.o
	cd /ece566/projects/p1/c++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /ece566/projects/p1/c++ /ece566/projects/p1/c++/tests /ece566/projects/p1/c++/build /ece566/projects/p1/c++/build/tests /ece566/projects/p1/c++/build/tests/CMakeFiles/test_10.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/test_10.dir/depend

