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
include test/CMakeFiles/unintialized_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/unintialized_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/unintialized_test.dir/flags.make

test/CMakeFiles/unintialized_test.dir/unintialized_test.cpp.obj: test/CMakeFiles/unintialized_test.dir/flags.make
test/CMakeFiles/unintialized_test.dir/unintialized_test.cpp.obj: ../test/unintialized_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mytinystl\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/unintialized_test.dir/unintialized_test.cpp.obj"
	cd /d D:\mytinystl\cmake-build-debug\test && C:\MinGw\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\unintialized_test.dir\unintialized_test.cpp.obj -c D:\mytinystl\test\unintialized_test.cpp

test/CMakeFiles/unintialized_test.dir/unintialized_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unintialized_test.dir/unintialized_test.cpp.i"
	cd /d D:\mytinystl\cmake-build-debug\test && C:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\mytinystl\test\unintialized_test.cpp > CMakeFiles\unintialized_test.dir\unintialized_test.cpp.i

test/CMakeFiles/unintialized_test.dir/unintialized_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unintialized_test.dir/unintialized_test.cpp.s"
	cd /d D:\mytinystl\cmake-build-debug\test && C:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\mytinystl\test\unintialized_test.cpp -o CMakeFiles\unintialized_test.dir\unintialized_test.cpp.s

# Object files for target unintialized_test
unintialized_test_OBJECTS = \
"CMakeFiles/unintialized_test.dir/unintialized_test.cpp.obj"

# External object files for target unintialized_test
unintialized_test_EXTERNAL_OBJECTS =

../bin/unintialized_test.exe: test/CMakeFiles/unintialized_test.dir/unintialized_test.cpp.obj
../bin/unintialized_test.exe: test/CMakeFiles/unintialized_test.dir/build.make
../bin/unintialized_test.exe: test/CMakeFiles/unintialized_test.dir/linklibs.rsp
../bin/unintialized_test.exe: test/CMakeFiles/unintialized_test.dir/objects1.rsp
../bin/unintialized_test.exe: test/CMakeFiles/unintialized_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\mytinystl\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\..\bin\unintialized_test.exe"
	cd /d D:\mytinystl\cmake-build-debug\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\unintialized_test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/unintialized_test.dir/build: ../bin/unintialized_test.exe

.PHONY : test/CMakeFiles/unintialized_test.dir/build

test/CMakeFiles/unintialized_test.dir/clean:
	cd /d D:\mytinystl\cmake-build-debug\test && $(CMAKE_COMMAND) -P CMakeFiles\unintialized_test.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/unintialized_test.dir/clean

test/CMakeFiles/unintialized_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\mytinystl D:\mytinystl\test D:\mytinystl\cmake-build-debug D:\mytinystl\cmake-build-debug\test D:\mytinystl\cmake-build-debug\test\CMakeFiles\unintialized_test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/unintialized_test.dir/depend

