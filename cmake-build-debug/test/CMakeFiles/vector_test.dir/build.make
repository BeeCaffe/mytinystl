# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/92/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/92/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/caffe/CLionProjects/mytinystl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/caffe/CLionProjects/mytinystl/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/vector_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/vector_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/vector_test.dir/flags.make

test/CMakeFiles/vector_test.dir/vector_test.cpp.o: test/CMakeFiles/vector_test.dir/flags.make
test/CMakeFiles/vector_test.dir/vector_test.cpp.o: ../test/vector_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caffe/CLionProjects/mytinystl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/vector_test.dir/vector_test.cpp.o"
	cd /home/caffe/CLionProjects/mytinystl/cmake-build-debug/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vector_test.dir/vector_test.cpp.o -c /home/caffe/CLionProjects/mytinystl/test/vector_test.cpp

test/CMakeFiles/vector_test.dir/vector_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vector_test.dir/vector_test.cpp.i"
	cd /home/caffe/CLionProjects/mytinystl/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caffe/CLionProjects/mytinystl/test/vector_test.cpp > CMakeFiles/vector_test.dir/vector_test.cpp.i

test/CMakeFiles/vector_test.dir/vector_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vector_test.dir/vector_test.cpp.s"
	cd /home/caffe/CLionProjects/mytinystl/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caffe/CLionProjects/mytinystl/test/vector_test.cpp -o CMakeFiles/vector_test.dir/vector_test.cpp.s

# Object files for target vector_test
vector_test_OBJECTS = \
"CMakeFiles/vector_test.dir/vector_test.cpp.o"

# External object files for target vector_test
vector_test_EXTERNAL_OBJECTS =

../bin/vector_test: test/CMakeFiles/vector_test.dir/vector_test.cpp.o
../bin/vector_test: test/CMakeFiles/vector_test.dir/build.make
../bin/vector_test: test/CMakeFiles/vector_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caffe/CLionProjects/mytinystl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/vector_test"
	cd /home/caffe/CLionProjects/mytinystl/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vector_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/vector_test.dir/build: ../bin/vector_test

.PHONY : test/CMakeFiles/vector_test.dir/build

test/CMakeFiles/vector_test.dir/clean:
	cd /home/caffe/CLionProjects/mytinystl/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/vector_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/vector_test.dir/clean

test/CMakeFiles/vector_test.dir/depend:
	cd /home/caffe/CLionProjects/mytinystl/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caffe/CLionProjects/mytinystl /home/caffe/CLionProjects/mytinystl/test /home/caffe/CLionProjects/mytinystl/cmake-build-debug /home/caffe/CLionProjects/mytinystl/cmake-build-debug/test /home/caffe/CLionProjects/mytinystl/cmake-build-debug/test/CMakeFiles/vector_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/vector_test.dir/depend

