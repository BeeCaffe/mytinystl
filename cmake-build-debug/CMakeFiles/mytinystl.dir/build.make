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
include CMakeFiles/mytinystl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mytinystl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mytinystl.dir/flags.make

CMakeFiles/mytinystl.dir/main.cpp.o: CMakeFiles/mytinystl.dir/flags.make
CMakeFiles/mytinystl.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caffe/CLionProjects/mytinystl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mytinystl.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mytinystl.dir/main.cpp.o -c /home/caffe/CLionProjects/mytinystl/main.cpp

CMakeFiles/mytinystl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mytinystl.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caffe/CLionProjects/mytinystl/main.cpp > CMakeFiles/mytinystl.dir/main.cpp.i

CMakeFiles/mytinystl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mytinystl.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caffe/CLionProjects/mytinystl/main.cpp -o CMakeFiles/mytinystl.dir/main.cpp.s

# Object files for target mytinystl
mytinystl_OBJECTS = \
"CMakeFiles/mytinystl.dir/main.cpp.o"

# External object files for target mytinystl
mytinystl_EXTERNAL_OBJECTS =

mytinystl: CMakeFiles/mytinystl.dir/main.cpp.o
mytinystl: CMakeFiles/mytinystl.dir/build.make
mytinystl: CMakeFiles/mytinystl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caffe/CLionProjects/mytinystl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mytinystl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mytinystl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mytinystl.dir/build: mytinystl

.PHONY : CMakeFiles/mytinystl.dir/build

CMakeFiles/mytinystl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mytinystl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mytinystl.dir/clean

CMakeFiles/mytinystl.dir/depend:
	cd /home/caffe/CLionProjects/mytinystl/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caffe/CLionProjects/mytinystl /home/caffe/CLionProjects/mytinystl /home/caffe/CLionProjects/mytinystl/cmake-build-debug /home/caffe/CLionProjects/mytinystl/cmake-build-debug /home/caffe/CLionProjects/mytinystl/cmake-build-debug/CMakeFiles/mytinystl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mytinystl.dir/depend

