# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/francis/Escritorio/Programacion/Algoritmica/P5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/francis/Escritorio/Programacion/Algoritmica/P5

# Include any dependencies generated for this target.
include CMakeFiles/NReinas.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NReinas.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NReinas.dir/flags.make

CMakeFiles/NReinas.dir/main.cpp.o: CMakeFiles/NReinas.dir/flags.make
CMakeFiles/NReinas.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francis/Escritorio/Programacion/Algoritmica/P5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NReinas.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NReinas.dir/main.cpp.o -c /home/francis/Escritorio/Programacion/Algoritmica/P5/main.cpp

CMakeFiles/NReinas.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NReinas.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francis/Escritorio/Programacion/Algoritmica/P5/main.cpp > CMakeFiles/NReinas.dir/main.cpp.i

CMakeFiles/NReinas.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NReinas.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francis/Escritorio/Programacion/Algoritmica/P5/main.cpp -o CMakeFiles/NReinas.dir/main.cpp.s

CMakeFiles/NReinas.dir/funciones.cpp.o: CMakeFiles/NReinas.dir/flags.make
CMakeFiles/NReinas.dir/funciones.cpp.o: funciones.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francis/Escritorio/Programacion/Algoritmica/P5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NReinas.dir/funciones.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NReinas.dir/funciones.cpp.o -c /home/francis/Escritorio/Programacion/Algoritmica/P5/funciones.cpp

CMakeFiles/NReinas.dir/funciones.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NReinas.dir/funciones.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francis/Escritorio/Programacion/Algoritmica/P5/funciones.cpp > CMakeFiles/NReinas.dir/funciones.cpp.i

CMakeFiles/NReinas.dir/funciones.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NReinas.dir/funciones.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francis/Escritorio/Programacion/Algoritmica/P5/funciones.cpp -o CMakeFiles/NReinas.dir/funciones.cpp.s

# Object files for target NReinas
NReinas_OBJECTS = \
"CMakeFiles/NReinas.dir/main.cpp.o" \
"CMakeFiles/NReinas.dir/funciones.cpp.o"

# External object files for target NReinas
NReinas_EXTERNAL_OBJECTS =

NReinas: CMakeFiles/NReinas.dir/main.cpp.o
NReinas: CMakeFiles/NReinas.dir/funciones.cpp.o
NReinas: CMakeFiles/NReinas.dir/build.make
NReinas: CMakeFiles/NReinas.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/francis/Escritorio/Programacion/Algoritmica/P5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable NReinas"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NReinas.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NReinas.dir/build: NReinas

.PHONY : CMakeFiles/NReinas.dir/build

CMakeFiles/NReinas.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NReinas.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NReinas.dir/clean

CMakeFiles/NReinas.dir/depend:
	cd /home/francis/Escritorio/Programacion/Algoritmica/P5 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/francis/Escritorio/Programacion/Algoritmica/P5 /home/francis/Escritorio/Programacion/Algoritmica/P5 /home/francis/Escritorio/Programacion/Algoritmica/P5 /home/francis/Escritorio/Programacion/Algoritmica/P5 /home/francis/Escritorio/Programacion/Algoritmica/P5/CMakeFiles/NReinas.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NReinas.dir/depend
