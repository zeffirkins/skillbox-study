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
CMAKE_SOURCE_DIR = C:\Users\Iurii\CLionProjects\Experiment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Iurii\CLionProjects\Experiment\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Experiment.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Experiment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Experiment.dir/flags.make

CMakeFiles/Experiment.dir/main.cpp.obj: CMakeFiles/Experiment.dir/flags.make
CMakeFiles/Experiment.dir/main.cpp.obj: CMakeFiles/Experiment.dir/includes_CXX.rsp
CMakeFiles/Experiment.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Iurii\CLionProjects\Experiment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Experiment.dir/main.cpp.obj"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Experiment.dir\main.cpp.obj -c C:\Users\Iurii\CLionProjects\Experiment\main.cpp

CMakeFiles/Experiment.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Experiment.dir/main.cpp.i"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Iurii\CLionProjects\Experiment\main.cpp > CMakeFiles\Experiment.dir\main.cpp.i

CMakeFiles/Experiment.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Experiment.dir/main.cpp.s"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Iurii\CLionProjects\Experiment\main.cpp -o CMakeFiles\Experiment.dir\main.cpp.s

# Object files for target Experiment
Experiment_OBJECTS = \
"CMakeFiles/Experiment.dir/main.cpp.obj"

# External object files for target Experiment
Experiment_EXTERNAL_OBJECTS =

Experiment.exe: CMakeFiles/Experiment.dir/main.cpp.obj
Experiment.exe: CMakeFiles/Experiment.dir/build.make
Experiment.exe: _deps/cpr-build/cpr/libcpr.dll.a
Experiment.exe: _deps/curl-build/lib/libcurl-d.dll.a
Experiment.exe: CMakeFiles/Experiment.dir/linklibs.rsp
Experiment.exe: CMakeFiles/Experiment.dir/objects1.rsp
Experiment.exe: CMakeFiles/Experiment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Iurii\CLionProjects\Experiment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Experiment.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Experiment.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Experiment.dir/build: Experiment.exe
.PHONY : CMakeFiles/Experiment.dir/build

CMakeFiles/Experiment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Experiment.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Experiment.dir/clean

CMakeFiles/Experiment.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Iurii\CLionProjects\Experiment C:\Users\Iurii\CLionProjects\Experiment C:\Users\Iurii\CLionProjects\Experiment\cmake-build-debug C:\Users\Iurii\CLionProjects\Experiment\cmake-build-debug C:\Users\Iurii\CLionProjects\Experiment\cmake-build-debug\CMakeFiles\Experiment.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Experiment.dir/depend

