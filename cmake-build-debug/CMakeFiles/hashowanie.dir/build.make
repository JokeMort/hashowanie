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
CMAKE_COMMAND = /snap/clion/190/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/190/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/epsilion/CLionProjects/projekt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/epsilion/CLionProjects/projekt/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hashowanie.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hashowanie.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hashowanie.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hashowanie.dir/flags.make

CMakeFiles/hashowanie.dir/main.cpp.o: CMakeFiles/hashowanie.dir/flags.make
CMakeFiles/hashowanie.dir/main.cpp.o: ../main.cpp
CMakeFiles/hashowanie.dir/main.cpp.o: CMakeFiles/hashowanie.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/epsilion/CLionProjects/projekt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hashowanie.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hashowanie.dir/main.cpp.o -MF CMakeFiles/hashowanie.dir/main.cpp.o.d -o CMakeFiles/hashowanie.dir/main.cpp.o -c /home/epsilion/CLionProjects/projekt/main.cpp

CMakeFiles/hashowanie.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hashowanie.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/epsilion/CLionProjects/projekt/main.cpp > CMakeFiles/hashowanie.dir/main.cpp.i

CMakeFiles/hashowanie.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hashowanie.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/epsilion/CLionProjects/projekt/main.cpp -o CMakeFiles/hashowanie.dir/main.cpp.s

CMakeFiles/hashowanie.dir/hash.cpp.o: CMakeFiles/hashowanie.dir/flags.make
CMakeFiles/hashowanie.dir/hash.cpp.o: ../hash.cpp
CMakeFiles/hashowanie.dir/hash.cpp.o: CMakeFiles/hashowanie.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/epsilion/CLionProjects/projekt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hashowanie.dir/hash.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hashowanie.dir/hash.cpp.o -MF CMakeFiles/hashowanie.dir/hash.cpp.o.d -o CMakeFiles/hashowanie.dir/hash.cpp.o -c /home/epsilion/CLionProjects/projekt/hash.cpp

CMakeFiles/hashowanie.dir/hash.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hashowanie.dir/hash.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/epsilion/CLionProjects/projekt/hash.cpp > CMakeFiles/hashowanie.dir/hash.cpp.i

CMakeFiles/hashowanie.dir/hash.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hashowanie.dir/hash.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/epsilion/CLionProjects/projekt/hash.cpp -o CMakeFiles/hashowanie.dir/hash.cpp.s

# Object files for target hashowanie
hashowanie_OBJECTS = \
"CMakeFiles/hashowanie.dir/main.cpp.o" \
"CMakeFiles/hashowanie.dir/hash.cpp.o"

# External object files for target hashowanie
hashowanie_EXTERNAL_OBJECTS =

hashowanie: CMakeFiles/hashowanie.dir/main.cpp.o
hashowanie: CMakeFiles/hashowanie.dir/hash.cpp.o
hashowanie: CMakeFiles/hashowanie.dir/build.make
hashowanie: CMakeFiles/hashowanie.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/epsilion/CLionProjects/projekt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable hashowanie"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hashowanie.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hashowanie.dir/build: hashowanie
.PHONY : CMakeFiles/hashowanie.dir/build

CMakeFiles/hashowanie.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hashowanie.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hashowanie.dir/clean

CMakeFiles/hashowanie.dir/depend:
	cd /home/epsilion/CLionProjects/projekt/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/epsilion/CLionProjects/projekt /home/epsilion/CLionProjects/projekt /home/epsilion/CLionProjects/projekt/cmake-build-debug /home/epsilion/CLionProjects/projekt/cmake-build-debug /home/epsilion/CLionProjects/projekt/cmake-build-debug/CMakeFiles/hashowanie.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hashowanie.dir/depend

