# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/botondhergyo/comp4300/lecture4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/botondhergyo/comp4300/lecture4/build

# Include any dependencies generated for this target.
include CMakeFiles/sfml_game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sfml_game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sfml_game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sfml_game.dir/flags.make

CMakeFiles/sfml_game.dir/src/main.cpp.o: CMakeFiles/sfml_game.dir/flags.make
CMakeFiles/sfml_game.dir/src/main.cpp.o: /home/botondhergyo/comp4300/lecture4/src/main.cpp
CMakeFiles/sfml_game.dir/src/main.cpp.o: CMakeFiles/sfml_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/botondhergyo/comp4300/lecture4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sfml_game.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml_game.dir/src/main.cpp.o -MF CMakeFiles/sfml_game.dir/src/main.cpp.o.d -o CMakeFiles/sfml_game.dir/src/main.cpp.o -c /home/botondhergyo/comp4300/lecture4/src/main.cpp

CMakeFiles/sfml_game.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sfml_game.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/botondhergyo/comp4300/lecture4/src/main.cpp > CMakeFiles/sfml_game.dir/src/main.cpp.i

CMakeFiles/sfml_game.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sfml_game.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/botondhergyo/comp4300/lecture4/src/main.cpp -o CMakeFiles/sfml_game.dir/src/main.cpp.s

# Object files for target sfml_game
sfml_game_OBJECTS = \
"CMakeFiles/sfml_game.dir/src/main.cpp.o"

# External object files for target sfml_game
sfml_game_EXTERNAL_OBJECTS =

sfml_game: CMakeFiles/sfml_game.dir/src/main.cpp.o
sfml_game: CMakeFiles/sfml_game.dir/build.make
sfml_game: /home/botondhergyo/sfml/SFML-2.6.1/lib/libsfml-network-d.so.2.6.1
sfml_game: /home/botondhergyo/sfml/SFML-2.6.1/lib/libsfml-audio-d.so.2.6.1
sfml_game: /home/botondhergyo/sfml/SFML-2.6.1/lib/libsfml-graphics-d.so.2.6.1
sfml_game: /home/botondhergyo/sfml/SFML-2.6.1/lib/libsfml-window-d.so.2.6.1
sfml_game: /home/botondhergyo/sfml/SFML-2.6.1/lib/libsfml-system-d.so.2.6.1
sfml_game: CMakeFiles/sfml_game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/botondhergyo/comp4300/lecture4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sfml_game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfml_game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sfml_game.dir/build: sfml_game
.PHONY : CMakeFiles/sfml_game.dir/build

CMakeFiles/sfml_game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sfml_game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sfml_game.dir/clean

CMakeFiles/sfml_game.dir/depend:
	cd /home/botondhergyo/comp4300/lecture4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/botondhergyo/comp4300/lecture4 /home/botondhergyo/comp4300/lecture4 /home/botondhergyo/comp4300/lecture4/build /home/botondhergyo/comp4300/lecture4/build /home/botondhergyo/comp4300/lecture4/build/CMakeFiles/sfml_game.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sfml_game.dir/depend
