# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/kajetan/CLionProjects/minesweeper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kajetan/CLionProjects/minesweeper/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/minesweeper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minesweeper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minesweeper.dir/flags.make

CMakeFiles/minesweeper.dir/main.cpp.o: CMakeFiles/minesweeper.dir/flags.make
CMakeFiles/minesweeper.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kajetan/CLionProjects/minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/minesweeper.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minesweeper.dir/main.cpp.o -c /home/kajetan/CLionProjects/minesweeper/main.cpp

CMakeFiles/minesweeper.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minesweeper.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kajetan/CLionProjects/minesweeper/main.cpp > CMakeFiles/minesweeper.dir/main.cpp.i

CMakeFiles/minesweeper.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minesweeper.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kajetan/CLionProjects/minesweeper/main.cpp -o CMakeFiles/minesweeper.dir/main.cpp.s

CMakeFiles/minesweeper.dir/minesBoard.cpp.o: CMakeFiles/minesweeper.dir/flags.make
CMakeFiles/minesweeper.dir/minesBoard.cpp.o: ../minesBoard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kajetan/CLionProjects/minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/minesweeper.dir/minesBoard.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minesweeper.dir/minesBoard.cpp.o -c /home/kajetan/CLionProjects/minesweeper/minesBoard.cpp

CMakeFiles/minesweeper.dir/minesBoard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minesweeper.dir/minesBoard.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kajetan/CLionProjects/minesweeper/minesBoard.cpp > CMakeFiles/minesweeper.dir/minesBoard.cpp.i

CMakeFiles/minesweeper.dir/minesBoard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minesweeper.dir/minesBoard.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kajetan/CLionProjects/minesweeper/minesBoard.cpp -o CMakeFiles/minesweeper.dir/minesBoard.cpp.s

# Object files for target minesweeper
minesweeper_OBJECTS = \
"CMakeFiles/minesweeper.dir/main.cpp.o" \
"CMakeFiles/minesweeper.dir/minesBoard.cpp.o"

# External object files for target minesweeper
minesweeper_EXTERNAL_OBJECTS =

minesweeper: CMakeFiles/minesweeper.dir/main.cpp.o
minesweeper: CMakeFiles/minesweeper.dir/minesBoard.cpp.o
minesweeper: CMakeFiles/minesweeper.dir/build.make
minesweeper: CMakeFiles/minesweeper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kajetan/CLionProjects/minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable minesweeper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minesweeper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minesweeper.dir/build: minesweeper

.PHONY : CMakeFiles/minesweeper.dir/build

CMakeFiles/minesweeper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minesweeper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minesweeper.dir/clean

CMakeFiles/minesweeper.dir/depend:
	cd /home/kajetan/CLionProjects/minesweeper/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kajetan/CLionProjects/minesweeper /home/kajetan/CLionProjects/minesweeper /home/kajetan/CLionProjects/minesweeper/cmake-build-debug /home/kajetan/CLionProjects/minesweeper/cmake-build-debug /home/kajetan/CLionProjects/minesweeper/cmake-build-debug/CMakeFiles/minesweeper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minesweeper.dir/depend
