# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/d/HSE/2 course/algosi/3 module/kdz/Control_Homework_2_code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/d/HSE/2 course/algosi/3 module/kdz/Control_Homework_2_code/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Control_Homework_2_code.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Control_Homework_2_code.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Control_Homework_2_code.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Control_Homework_2_code.dir/flags.make

CMakeFiles/Control_Homework_2_code.dir/main.cpp.o: CMakeFiles/Control_Homework_2_code.dir/flags.make
CMakeFiles/Control_Homework_2_code.dir/main.cpp.o: ../main.cpp
CMakeFiles/Control_Homework_2_code.dir/main.cpp.o: CMakeFiles/Control_Homework_2_code.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/HSE/2 course/algosi/3 module/kdz/Control_Homework_2_code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Control_Homework_2_code.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Control_Homework_2_code.dir/main.cpp.o -MF CMakeFiles/Control_Homework_2_code.dir/main.cpp.o.d -o CMakeFiles/Control_Homework_2_code.dir/main.cpp.o -c "/mnt/d/HSE/2 course/algosi/3 module/kdz/Control_Homework_2_code/main.cpp"

CMakeFiles/Control_Homework_2_code.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Control_Homework_2_code.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/d/HSE/2 course/algosi/3 module/kdz/Control_Homework_2_code/main.cpp" > CMakeFiles/Control_Homework_2_code.dir/main.cpp.i

CMakeFiles/Control_Homework_2_code.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Control_Homework_2_code.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/d/HSE/2 course/algosi/3 module/kdz/Control_Homework_2_code/main.cpp" -o CMakeFiles/Control_Homework_2_code.dir/main.cpp.s

# Object files for target Control_Homework_2_code
Control_Homework_2_code_OBJECTS = \
"CMakeFiles/Control_Homework_2_code.dir/main.cpp.o"

# External object files for target Control_Homework_2_code
Control_Homework_2_code_EXTERNAL_OBJECTS =

Control_Homework_2_code: CMakeFiles/Control_Homework_2_code.dir/main.cpp.o
Control_Homework_2_code: CMakeFiles/Control_Homework_2_code.dir/build.make
Control_Homework_2_code: CMakeFiles/Control_Homework_2_code.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/d/HSE/2 course/algosi/3 module/kdz/Control_Homework_2_code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Control_Homework_2_code"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Control_Homework_2_code.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Control_Homework_2_code.dir/build: Control_Homework_2_code
.PHONY : CMakeFiles/Control_Homework_2_code.dir/build

CMakeFiles/Control_Homework_2_code.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Control_Homework_2_code.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Control_Homework_2_code.dir/clean

CMakeFiles/Control_Homework_2_code.dir/depend:
	cd "/mnt/d/HSE/2 course/algosi/3 module/kdz/Control_Homework_2_code/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/d/HSE/2 course/algosi/3 module/kdz/Control_Homework_2_code" "/mnt/d/HSE/2 course/algosi/3 module/kdz/Control_Homework_2_code" "/mnt/d/HSE/2 course/algosi/3 module/kdz/Control_Homework_2_code/cmake-build-debug" "/mnt/d/HSE/2 course/algosi/3 module/kdz/Control_Homework_2_code/cmake-build-debug" "/mnt/d/HSE/2 course/algosi/3 module/kdz/Control_Homework_2_code/cmake-build-debug/CMakeFiles/Control_Homework_2_code.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Control_Homework_2_code.dir/depend

