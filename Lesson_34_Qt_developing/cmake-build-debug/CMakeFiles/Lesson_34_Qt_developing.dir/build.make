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
CMAKE_SOURCE_DIR = C:\Users\Iurii\CLionProjects\Lesson_34_Qt_developing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Iurii\CLionProjects\Lesson_34_Qt_developing\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lesson_34_Qt_developing.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Lesson_34_Qt_developing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lesson_34_Qt_developing.dir/flags.make

CMakeFiles/Lesson_34_Qt_developing.dir/main.cpp.obj: CMakeFiles/Lesson_34_Qt_developing.dir/flags.make
CMakeFiles/Lesson_34_Qt_developing.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Iurii\CLionProjects\Lesson_34_Qt_developing\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lesson_34_Qt_developing.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lesson_34_Qt_developing.dir\main.cpp.obj -c C:\Users\Iurii\CLionProjects\Lesson_34_Qt_developing\main.cpp

CMakeFiles/Lesson_34_Qt_developing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lesson_34_Qt_developing.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Iurii\CLionProjects\Lesson_34_Qt_developing\main.cpp > CMakeFiles\Lesson_34_Qt_developing.dir\main.cpp.i

CMakeFiles/Lesson_34_Qt_developing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lesson_34_Qt_developing.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Iurii\CLionProjects\Lesson_34_Qt_developing\main.cpp -o CMakeFiles\Lesson_34_Qt_developing.dir\main.cpp.s

# Object files for target Lesson_34_Qt_developing
Lesson_34_Qt_developing_OBJECTS = \
"CMakeFiles/Lesson_34_Qt_developing.dir/main.cpp.obj"

# External object files for target Lesson_34_Qt_developing
Lesson_34_Qt_developing_EXTERNAL_OBJECTS =

Lesson_34_Qt_developing.exe: CMakeFiles/Lesson_34_Qt_developing.dir/main.cpp.obj
Lesson_34_Qt_developing.exe: CMakeFiles/Lesson_34_Qt_developing.dir/build.make
Lesson_34_Qt_developing.exe: CMakeFiles/Lesson_34_Qt_developing.dir/linklibs.rsp
Lesson_34_Qt_developing.exe: CMakeFiles/Lesson_34_Qt_developing.dir/objects1.rsp
Lesson_34_Qt_developing.exe: CMakeFiles/Lesson_34_Qt_developing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Iurii\CLionProjects\Lesson_34_Qt_developing\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lesson_34_Qt_developing.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lesson_34_Qt_developing.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lesson_34_Qt_developing.dir/build: Lesson_34_Qt_developing.exe
.PHONY : CMakeFiles/Lesson_34_Qt_developing.dir/build

CMakeFiles/Lesson_34_Qt_developing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lesson_34_Qt_developing.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lesson_34_Qt_developing.dir/clean

CMakeFiles/Lesson_34_Qt_developing.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Iurii\CLionProjects\Lesson_34_Qt_developing C:\Users\Iurii\CLionProjects\Lesson_34_Qt_developing C:\Users\Iurii\CLionProjects\Lesson_34_Qt_developing\cmake-build-debug C:\Users\Iurii\CLionProjects\Lesson_34_Qt_developing\cmake-build-debug C:\Users\Iurii\CLionProjects\Lesson_34_Qt_developing\cmake-build-debug\CMakeFiles\Lesson_34_Qt_developing.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lesson_34_Qt_developing.dir/depend

