# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
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
CMAKE_SOURCE_DIR = C:\Users\Iurii\CLionProjects\Task_16_4_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Iurii\CLionProjects\Task_16_4_5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Task_16_4_5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task_16_4_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task_16_4_5.dir/flags.make

CMakeFiles/Task_16_4_5.dir/main.cpp.obj: CMakeFiles/Task_16_4_5.dir/flags.make
CMakeFiles/Task_16_4_5.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Iurii\CLionProjects\Task_16_4_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task_16_4_5.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Task_16_4_5.dir\main.cpp.obj -c C:\Users\Iurii\CLionProjects\Task_16_4_5\main.cpp

CMakeFiles/Task_16_4_5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task_16_4_5.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Iurii\CLionProjects\Task_16_4_5\main.cpp > CMakeFiles\Task_16_4_5.dir\main.cpp.i

CMakeFiles/Task_16_4_5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task_16_4_5.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Iurii\CLionProjects\Task_16_4_5\main.cpp -o CMakeFiles\Task_16_4_5.dir\main.cpp.s

# Object files for target Task_16_4_5
Task_16_4_5_OBJECTS = \
"CMakeFiles/Task_16_4_5.dir/main.cpp.obj"

# External object files for target Task_16_4_5
Task_16_4_5_EXTERNAL_OBJECTS =

Task_16_4_5.exe: CMakeFiles/Task_16_4_5.dir/main.cpp.obj
Task_16_4_5.exe: CMakeFiles/Task_16_4_5.dir/build.make
Task_16_4_5.exe: CMakeFiles/Task_16_4_5.dir/linklibs.rsp
Task_16_4_5.exe: CMakeFiles/Task_16_4_5.dir/objects1.rsp
Task_16_4_5.exe: CMakeFiles/Task_16_4_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Iurii\CLionProjects\Task_16_4_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task_16_4_5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Task_16_4_5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task_16_4_5.dir/build: Task_16_4_5.exe

.PHONY : CMakeFiles/Task_16_4_5.dir/build

CMakeFiles/Task_16_4_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Task_16_4_5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Task_16_4_5.dir/clean

CMakeFiles/Task_16_4_5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Iurii\CLionProjects\Task_16_4_5 C:\Users\Iurii\CLionProjects\Task_16_4_5 C:\Users\Iurii\CLionProjects\Task_16_4_5\cmake-build-debug C:\Users\Iurii\CLionProjects\Task_16_4_5\cmake-build-debug C:\Users\Iurii\CLionProjects\Task_16_4_5\cmake-build-debug\CMakeFiles\Task_16_4_5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Task_16_4_5.dir/depend

