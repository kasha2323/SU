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
CMAKE_SOURCE_DIR = /home/sammy/workspace/SU/Kode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sammy/workspace/SU/Kode/build

# Include any dependencies generated for this target.
include CMakeFiles/Kode.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Kode.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Kode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Kode.dir/flags.make

CMakeFiles/Kode.dir/main.cpp.o: CMakeFiles/Kode.dir/flags.make
CMakeFiles/Kode.dir/main.cpp.o: ../main.cpp
CMakeFiles/Kode.dir/main.cpp.o: CMakeFiles/Kode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sammy/workspace/SU/Kode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Kode.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Kode.dir/main.cpp.o -MF CMakeFiles/Kode.dir/main.cpp.o.d -o CMakeFiles/Kode.dir/main.cpp.o -c /home/sammy/workspace/SU/Kode/main.cpp

CMakeFiles/Kode.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kode.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sammy/workspace/SU/Kode/main.cpp > CMakeFiles/Kode.dir/main.cpp.i

CMakeFiles/Kode.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kode.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sammy/workspace/SU/Kode/main.cpp -o CMakeFiles/Kode.dir/main.cpp.s

CMakeFiles/Kode.dir/hero.cpp.o: CMakeFiles/Kode.dir/flags.make
CMakeFiles/Kode.dir/hero.cpp.o: ../hero.cpp
CMakeFiles/Kode.dir/hero.cpp.o: CMakeFiles/Kode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sammy/workspace/SU/Kode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Kode.dir/hero.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Kode.dir/hero.cpp.o -MF CMakeFiles/Kode.dir/hero.cpp.o.d -o CMakeFiles/Kode.dir/hero.cpp.o -c /home/sammy/workspace/SU/Kode/hero.cpp

CMakeFiles/Kode.dir/hero.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kode.dir/hero.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sammy/workspace/SU/Kode/hero.cpp > CMakeFiles/Kode.dir/hero.cpp.i

CMakeFiles/Kode.dir/hero.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kode.dir/hero.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sammy/workspace/SU/Kode/hero.cpp -o CMakeFiles/Kode.dir/hero.cpp.s

CMakeFiles/Kode.dir/enemy.cpp.o: CMakeFiles/Kode.dir/flags.make
CMakeFiles/Kode.dir/enemy.cpp.o: ../enemy.cpp
CMakeFiles/Kode.dir/enemy.cpp.o: CMakeFiles/Kode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sammy/workspace/SU/Kode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Kode.dir/enemy.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Kode.dir/enemy.cpp.o -MF CMakeFiles/Kode.dir/enemy.cpp.o.d -o CMakeFiles/Kode.dir/enemy.cpp.o -c /home/sammy/workspace/SU/Kode/enemy.cpp

CMakeFiles/Kode.dir/enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kode.dir/enemy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sammy/workspace/SU/Kode/enemy.cpp > CMakeFiles/Kode.dir/enemy.cpp.i

CMakeFiles/Kode.dir/enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kode.dir/enemy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sammy/workspace/SU/Kode/enemy.cpp -o CMakeFiles/Kode.dir/enemy.cpp.s

CMakeFiles/Kode.dir/diverse.cpp.o: CMakeFiles/Kode.dir/flags.make
CMakeFiles/Kode.dir/diverse.cpp.o: ../diverse.cpp
CMakeFiles/Kode.dir/diverse.cpp.o: CMakeFiles/Kode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sammy/workspace/SU/Kode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Kode.dir/diverse.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Kode.dir/diverse.cpp.o -MF CMakeFiles/Kode.dir/diverse.cpp.o.d -o CMakeFiles/Kode.dir/diverse.cpp.o -c /home/sammy/workspace/SU/Kode/diverse.cpp

CMakeFiles/Kode.dir/diverse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kode.dir/diverse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sammy/workspace/SU/Kode/diverse.cpp > CMakeFiles/Kode.dir/diverse.cpp.i

CMakeFiles/Kode.dir/diverse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kode.dir/diverse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sammy/workspace/SU/Kode/diverse.cpp -o CMakeFiles/Kode.dir/diverse.cpp.s

CMakeFiles/Kode.dir/cave.cpp.o: CMakeFiles/Kode.dir/flags.make
CMakeFiles/Kode.dir/cave.cpp.o: ../cave.cpp
CMakeFiles/Kode.dir/cave.cpp.o: CMakeFiles/Kode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sammy/workspace/SU/Kode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Kode.dir/cave.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Kode.dir/cave.cpp.o -MF CMakeFiles/Kode.dir/cave.cpp.o.d -o CMakeFiles/Kode.dir/cave.cpp.o -c /home/sammy/workspace/SU/Kode/cave.cpp

CMakeFiles/Kode.dir/cave.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kode.dir/cave.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sammy/workspace/SU/Kode/cave.cpp > CMakeFiles/Kode.dir/cave.cpp.i

CMakeFiles/Kode.dir/cave.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kode.dir/cave.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sammy/workspace/SU/Kode/cave.cpp -o CMakeFiles/Kode.dir/cave.cpp.s

# Object files for target Kode
Kode_OBJECTS = \
"CMakeFiles/Kode.dir/main.cpp.o" \
"CMakeFiles/Kode.dir/hero.cpp.o" \
"CMakeFiles/Kode.dir/enemy.cpp.o" \
"CMakeFiles/Kode.dir/diverse.cpp.o" \
"CMakeFiles/Kode.dir/cave.cpp.o"

# External object files for target Kode
Kode_EXTERNAL_OBJECTS =

Kode: CMakeFiles/Kode.dir/main.cpp.o
Kode: CMakeFiles/Kode.dir/hero.cpp.o
Kode: CMakeFiles/Kode.dir/enemy.cpp.o
Kode: CMakeFiles/Kode.dir/diverse.cpp.o
Kode: CMakeFiles/Kode.dir/cave.cpp.o
Kode: CMakeFiles/Kode.dir/build.make
Kode: /usr/lib/x86_64-linux-gnu/libQt5Sql.so.5.15.3
Kode: /usr/lib/x86_64-linux-gnu/libQt5Quick.so.5.15.3
Kode: /usr/lib/x86_64-linux-gnu/libQt5QmlModels.so.5.15.3
Kode: /usr/lib/x86_64-linux-gnu/libQt5Qml.so.5.15.3
Kode: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.3
Kode: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
Kode: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
Kode: CMakeFiles/Kode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sammy/workspace/SU/Kode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Kode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Kode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Kode.dir/build: Kode
.PHONY : CMakeFiles/Kode.dir/build

CMakeFiles/Kode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Kode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Kode.dir/clean

CMakeFiles/Kode.dir/depend:
	cd /home/sammy/workspace/SU/Kode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sammy/workspace/SU/Kode /home/sammy/workspace/SU/Kode /home/sammy/workspace/SU/Kode/build /home/sammy/workspace/SU/Kode/build /home/sammy/workspace/SU/Kode/build/CMakeFiles/Kode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Kode.dir/depend

