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

# Include any dependencies generated for this target.
include CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/flags.make

CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/main.cpp.obj: CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/flags.make
CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/main.cpp.obj: CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/includes_CXX.rsp
CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Task_30_4_3_Requests_with_arguments.dir\main.cpp.obj -c C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\main.cpp

CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\main.cpp > CMakeFiles\Task_30_4_3_Requests_with_arguments.dir\main.cpp.i

CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\main.cpp -o CMakeFiles\Task_30_4_3_Requests_with_arguments.dir\main.cpp.s

# Object files for target Task_30_4_3_Requests_with_arguments
Task_30_4_3_Requests_with_arguments_OBJECTS = \
"CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/main.cpp.obj"

# External object files for target Task_30_4_3_Requests_with_arguments
Task_30_4_3_Requests_with_arguments_EXTERNAL_OBJECTS =

Task_30_4_3_Requests_with_arguments.exe: CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/main.cpp.obj
Task_30_4_3_Requests_with_arguments.exe: CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/build.make
Task_30_4_3_Requests_with_arguments.exe: _deps/cpr-build/cpr/libcpr.dll.a
Task_30_4_3_Requests_with_arguments.exe: _deps/curl-build/lib/libcurl-d.dll.a
Task_30_4_3_Requests_with_arguments.exe: CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/linklibs.rsp
Task_30_4_3_Requests_with_arguments.exe: CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/objects1.rsp
Task_30_4_3_Requests_with_arguments.exe: CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task_30_4_3_Requests_with_arguments.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Task_30_4_3_Requests_with_arguments.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/build: Task_30_4_3_Requests_with_arguments.exe
.PHONY : CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/build

CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Task_30_4_3_Requests_with_arguments.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/clean

CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\cmake-build-debug C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\cmake-build-debug C:\Users\Iurii\CLionProjects\Task_30_4_3_Requests_with_arguments\cmake-build-debug\CMakeFiles\Task_30_4_3_Requests_with_arguments.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Task_30_4_3_Requests_with_arguments.dir/depend

