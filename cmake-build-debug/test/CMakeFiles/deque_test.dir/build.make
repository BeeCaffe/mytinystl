# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\mytinystl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\mytinystl\cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/deque_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/deque_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/deque_test.dir/flags.make

test/CMakeFiles/deque_test.dir/deque_test.cpp.obj: test/CMakeFiles/deque_test.dir/flags.make
test/CMakeFiles/deque_test.dir/deque_test.cpp.obj: ../test/deque_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mytinystl\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/deque_test.dir/deque_test.cpp.obj"
	cd /d D:\mytinystl\cmake-build-debug\test && C:\MinGw\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\deque_test.dir\deque_test.cpp.obj -c D:\mytinystl\test\deque_test.cpp

test/CMakeFiles/deque_test.dir/deque_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/deque_test.dir/deque_test.cpp.i"
	cd /d D:\mytinystl\cmake-build-debug\test && C:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\mytinystl\test\deque_test.cpp > CMakeFiles\deque_test.dir\deque_test.cpp.i

test/CMakeFiles/deque_test.dir/deque_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/deque_test.dir/deque_test.cpp.s"
	cd /d D:\mytinystl\cmake-build-debug\test && C:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\mytinystl\test\deque_test.cpp -o CMakeFiles\deque_test.dir\deque_test.cpp.s

# Object files for target deque_test
deque_test_OBJECTS = \
"CMakeFiles/deque_test.dir/deque_test.cpp.obj"

# External object files for target deque_test
deque_test_EXTERNAL_OBJECTS =

../bin/deque_test.exe: test/CMakeFiles/deque_test.dir/deque_test.cpp.obj
../bin/deque_test.exe: test/CMakeFiles/deque_test.dir/build.make
../bin/deque_test.exe: test/CMakeFiles/deque_test.dir/linklibs.rsp
../bin/deque_test.exe: test/CMakeFiles/deque_test.dir/objects1.rsp
../bin/deque_test.exe: test/CMakeFiles/deque_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\mytinystl\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\..\bin\deque_test.exe"
	cd /d D:\mytinystl\cmake-build-debug\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\deque_test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/deque_test.dir/build: ../bin/deque_test.exe

.PHONY : test/CMakeFiles/deque_test.dir/build

test/CMakeFiles/deque_test.dir/clean:
	cd /d D:\mytinystl\cmake-build-debug\test && $(CMAKE_COMMAND) -P CMakeFiles\deque_test.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/deque_test.dir/clean

test/CMakeFiles/deque_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\mytinystl D:\mytinystl\test D:\mytinystl\cmake-build-debug D:\mytinystl\cmake-build-debug\test D:\mytinystl\cmake-build-debug\test\CMakeFiles\deque_test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/deque_test.dir/depend

