# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/codemao/Panda/Projects/Learning/C++_Stand

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/codemao/Panda/Projects/Learning/C++_Stand/build

# Include any dependencies generated for this target.
include chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/depend.make

# Include the progress variables for this target.
include chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/progress.make

# Include the compile flags for this target's objects.
include chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/flags.make

chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/stdProducerAndCostomerLearning.cpp.o: chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/flags.make
chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/stdProducerAndCostomerLearning.cpp.o: ../chapter_07/stdProducerAndCostomerLearning.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/codemao/Panda/Projects/Learning/C++_Stand/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/stdProducerAndCostomerLearning.cpp.o"
	cd /home/codemao/Panda/Projects/Learning/C++_Stand/build/chapter_07 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stdProducerAndCostomerLearning.dir/stdProducerAndCostomerLearning.cpp.o -c /home/codemao/Panda/Projects/Learning/C++_Stand/chapter_07/stdProducerAndCostomerLearning.cpp

chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/stdProducerAndCostomerLearning.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stdProducerAndCostomerLearning.dir/stdProducerAndCostomerLearning.cpp.i"
	cd /home/codemao/Panda/Projects/Learning/C++_Stand/build/chapter_07 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/codemao/Panda/Projects/Learning/C++_Stand/chapter_07/stdProducerAndCostomerLearning.cpp > CMakeFiles/stdProducerAndCostomerLearning.dir/stdProducerAndCostomerLearning.cpp.i

chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/stdProducerAndCostomerLearning.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stdProducerAndCostomerLearning.dir/stdProducerAndCostomerLearning.cpp.s"
	cd /home/codemao/Panda/Projects/Learning/C++_Stand/build/chapter_07 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/codemao/Panda/Projects/Learning/C++_Stand/chapter_07/stdProducerAndCostomerLearning.cpp -o CMakeFiles/stdProducerAndCostomerLearning.dir/stdProducerAndCostomerLearning.cpp.s

# Object files for target stdProducerAndCostomerLearning
stdProducerAndCostomerLearning_OBJECTS = \
"CMakeFiles/stdProducerAndCostomerLearning.dir/stdProducerAndCostomerLearning.cpp.o"

# External object files for target stdProducerAndCostomerLearning
stdProducerAndCostomerLearning_EXTERNAL_OBJECTS =

chapter_07/stdProducerAndCostomerLearning: chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/stdProducerAndCostomerLearning.cpp.o
chapter_07/stdProducerAndCostomerLearning: chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/build.make
chapter_07/stdProducerAndCostomerLearning: chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/codemao/Panda/Projects/Learning/C++_Stand/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stdProducerAndCostomerLearning"
	cd /home/codemao/Panda/Projects/Learning/C++_Stand/build/chapter_07 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stdProducerAndCostomerLearning.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/build: chapter_07/stdProducerAndCostomerLearning

.PHONY : chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/build

chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/clean:
	cd /home/codemao/Panda/Projects/Learning/C++_Stand/build/chapter_07 && $(CMAKE_COMMAND) -P CMakeFiles/stdProducerAndCostomerLearning.dir/cmake_clean.cmake
.PHONY : chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/clean

chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/depend:
	cd /home/codemao/Panda/Projects/Learning/C++_Stand/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/codemao/Panda/Projects/Learning/C++_Stand /home/codemao/Panda/Projects/Learning/C++_Stand/chapter_07 /home/codemao/Panda/Projects/Learning/C++_Stand/build /home/codemao/Panda/Projects/Learning/C++_Stand/build/chapter_07 /home/codemao/Panda/Projects/Learning/C++_Stand/build/chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : chapter_07/CMakeFiles/stdProducerAndCostomerLearning.dir/depend

