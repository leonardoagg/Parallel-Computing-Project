# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/leonardo/Scrivania/clion-2021.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/leonardo/Scrivania/clion-2021.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/leonardo/Parallel-Computing-Project/parallel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leonardo/Parallel-Computing-Project/parallel/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/parallelComputing.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/parallelComputing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parallelComputing.dir/flags.make

CMakeFiles/parallelComputing.dir/main.cpp.o: CMakeFiles/parallelComputing.dir/flags.make
CMakeFiles/parallelComputing.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/Parallel-Computing-Project/parallel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/parallelComputing.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/parallelComputing.dir/main.cpp.o -c /home/leonardo/Parallel-Computing-Project/parallel/main.cpp

CMakeFiles/parallelComputing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parallelComputing.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leonardo/Parallel-Computing-Project/parallel/main.cpp > CMakeFiles/parallelComputing.dir/main.cpp.i

CMakeFiles/parallelComputing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parallelComputing.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leonardo/Parallel-Computing-Project/parallel/main.cpp -o CMakeFiles/parallelComputing.dir/main.cpp.s

# Object files for target parallelComputing
parallelComputing_OBJECTS = \
"CMakeFiles/parallelComputing.dir/main.cpp.o"

# External object files for target parallelComputing
parallelComputing_EXTERNAL_OBJECTS =

parallelComputing: CMakeFiles/parallelComputing.dir/main.cpp.o
parallelComputing: CMakeFiles/parallelComputing.dir/build.make
parallelComputing: CMakeFiles/parallelComputing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leonardo/Parallel-Computing-Project/parallel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable parallelComputing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parallelComputing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parallelComputing.dir/build: parallelComputing
.PHONY : CMakeFiles/parallelComputing.dir/build

CMakeFiles/parallelComputing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parallelComputing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parallelComputing.dir/clean

CMakeFiles/parallelComputing.dir/depend:
	cd /home/leonardo/Parallel-Computing-Project/parallel/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leonardo/Parallel-Computing-Project/parallel /home/leonardo/Parallel-Computing-Project/parallel /home/leonardo/Parallel-Computing-Project/parallel/cmake-build-debug /home/leonardo/Parallel-Computing-Project/parallel/cmake-build-debug /home/leonardo/Parallel-Computing-Project/parallel/cmake-build-debug/CMakeFiles/parallelComputing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parallelComputing.dir/depend

