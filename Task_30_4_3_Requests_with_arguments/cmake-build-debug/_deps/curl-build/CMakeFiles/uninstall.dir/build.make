# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\cmake-build-debug

# Utility rule file for uninstall.

# Include any custom commands dependencies for this target.
include _deps/curl-build/CMakeFiles/uninstall.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/curl-build/CMakeFiles/uninstall.dir/progress.make

_deps/curl-build/CMakeFiles/uninstall:
	cd /d C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\cmake-build-debug\_deps\curl-build && "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -P C:/Users/Iurii/CLionProjects/Task_30_4_3_Requests_with_arguments/cmake-build-debug/_deps/curl-build/CMake/cmake_uninstall.cmake

uninstall: _deps/curl-build/CMakeFiles/uninstall
uninstall: _deps/curl-build/CMakeFiles/uninstall.dir/build.make
.PHONY : uninstall

# Rule to build all files generated by this target.
_deps/curl-build/CMakeFiles/uninstall.dir/build: uninstall
.PHONY : _deps/curl-build/CMakeFiles/uninstall.dir/build

_deps/curl-build/CMakeFiles/uninstall.dir/clean:
	cd /d C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\cmake-build-debug\_deps\curl-build && $(CMAKE_COMMAND) -P CMakeFiles\uninstall.dir\cmake_clean.cmake
.PHONY : _deps/curl-build/CMakeFiles/uninstall.dir/clean

_deps/curl-build/CMakeFiles/uninstall.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\cmake-build-debug\_deps\curl-src C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\cmake-build-debug C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\cmake-build-debug\_deps\curl-build C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\cmake-build-debug\_deps\curl-build\CMakeFiles\uninstall.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/curl-build/CMakeFiles/uninstall.dir/depend

