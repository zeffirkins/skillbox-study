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
CMAKE_SOURCE_DIR = C:\Users\Iurii\CLionProjects\Task_35_6_3_FileSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Iurii\CLionProjects\Task_35_6_3_FileSystem\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Task_35_6_3_FileSystem.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Task_35_6_3_FileSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task_35_6_3_FileSystem.dir/flags.make

CMakeFiles/Task_35_6_3_FileSystem.dir/main.cpp.obj: CMakeFiles/Task_35_6_3_FileSystem.dir/flags.make
CMakeFiles/Task_35_6_3_FileSystem.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Iurii\CLionProjects\Task_35_6_3_FileSystem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task_35_6_3_FileSystem.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Task_35_6_3_FileSystem.dir\main.cpp.obj -c C:\Users\Iurii\CLionProjects\Task_35_6_3_FileSystem\main.cpp

CMakeFiles/Task_35_6_3_FileSystem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task_35_6_3_FileSystem.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Iurii\CLionProjects\Task_35_6_3_FileSystem\main.cpp > CMakeFiles\Task_35_6_3_FileSystem.dir\main.cpp.i

CMakeFiles/Task_35_6_3_FileSystem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task_35_6_3_FileSystem.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Iurii\CLionProjects\Task_35_6_3_FileSystem\main.cpp -o CMakeFiles\Task_35_6_3_FileSystem.dir\main.cpp.s

# Object files for target Task_35_6_3_FileSystem
Task_35_6_3_FileSystem_OBJECTS = \
"CMakeFiles/Task_35_6_3_FileSystem.dir/main.cpp.obj"

# External object files for target Task_35_6_3_FileSystem
Task_35_6_3_FileSystem_EXTERNAL_OBJECTS =

Task_35_6_3_FileSystem.exe: CMakeFiles/Task_35_6_3_FileSystem.dir/main.cpp.obj
Task_35_6_3_FileSystem.exe: CMakeFiles/Task_35_6_3_FileSystem.dir/build.make
Task_35_6_3_FileSystem.exe: CMakeFiles/Task_35_6_3_FileSystem.dir/linklibs.rsp
Task_35_6_3_FileSystem.exe: CMakeFiles/Task_35_6_3_FileSystem.dir/objects1.rsp
Task_35_6_3_FileSystem.exe: CMakeFiles/Task_35_6_3_FileSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Iurii\CLionProjects\Task_35_6_3_FileSystem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task_35_6_3_FileSystem.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Task_35_6_3_FileSystem.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task_35_6_3_FileSystem.dir/build: Task_35_6_3_FileSystem.exe
.PHONY : CMakeFiles/Task_35_6_3_FileSystem.dir/build

CMakeFiles/Task_35_6_3_FileSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Task_35_6_3_FileSystem.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Task_35_6_3_FileSystem.dir/clean

CMakeFiles/Task_35_6_3_FileSystem.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Iurii\CLionProjects\Task_35_6_3_FileSystem C:\Users\Iurii\CLionProjects\Task_35_6_3_FileSystem C:\Users\Iurii\CLionProjects\Task_35_6_3_FileSystem\cmake-build-debug C:\Users\Iurii\CLionProjects\Task_35_6_3_FileSystem\cmake-build-debug C:\Users\Iurii\CLionProjects\Task_35_6_3_FileSystem\cmake-build-debug\CMakeFiles\Task_35_6_3_FileSystem.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Task_35_6_3_FileSystem.dir/depend
