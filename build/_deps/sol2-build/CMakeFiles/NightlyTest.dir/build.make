# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/charles/Cpp/StateStack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/charles/Cpp/StateStack/build

# Utility rule file for NightlyTest.

# Include the progress variables for this target.
include _deps/sol2-build/CMakeFiles/NightlyTest.dir/progress.make

_deps/sol2-build/CMakeFiles/NightlyTest:
	cd /home/charles/Cpp/StateStack/build/_deps/sol2-build && /usr/bin/ctest -D NightlyTest

NightlyTest: _deps/sol2-build/CMakeFiles/NightlyTest
NightlyTest: _deps/sol2-build/CMakeFiles/NightlyTest.dir/build.make

.PHONY : NightlyTest

# Rule to build all files generated by this target.
_deps/sol2-build/CMakeFiles/NightlyTest.dir/build: NightlyTest

.PHONY : _deps/sol2-build/CMakeFiles/NightlyTest.dir/build

_deps/sol2-build/CMakeFiles/NightlyTest.dir/clean:
	cd /home/charles/Cpp/StateStack/build/_deps/sol2-build && $(CMAKE_COMMAND) -P CMakeFiles/NightlyTest.dir/cmake_clean.cmake
.PHONY : _deps/sol2-build/CMakeFiles/NightlyTest.dir/clean

_deps/sol2-build/CMakeFiles/NightlyTest.dir/depend:
	cd /home/charles/Cpp/StateStack/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/charles/Cpp/StateStack /home/charles/Cpp/StateStack/build/_deps/sol2-src /home/charles/Cpp/StateStack/build /home/charles/Cpp/StateStack/build/_deps/sol2-build /home/charles/Cpp/StateStack/build/_deps/sol2-build/CMakeFiles/NightlyTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/sol2-build/CMakeFiles/NightlyTest.dir/depend

