# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /cygdrive/c/Users/Zosia/AppData/Local/JetBrains/CLion2021.3/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Zosia/AppData/Local/JetBrains/CLion2021.3/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/cmake-build-debug-cygwin

# Include any dependencies generated for this target.
include CMakeFiles/netsim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/netsim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/netsim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/netsim.dir/flags.make

CMakeFiles/netsim.dir/src/package.cpp.o: CMakeFiles/netsim.dir/flags.make
CMakeFiles/netsim.dir/src/package.cpp.o: ../src/package.cpp
CMakeFiles/netsim.dir/src/package.cpp.o: CMakeFiles/netsim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/netsim.dir/src/package.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/netsim.dir/src/package.cpp.o -MF CMakeFiles/netsim.dir/src/package.cpp.o.d -o CMakeFiles/netsim.dir/src/package.cpp.o -c /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/package.cpp

CMakeFiles/netsim.dir/src/package.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netsim.dir/src/package.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/package.cpp > CMakeFiles/netsim.dir/src/package.cpp.i

CMakeFiles/netsim.dir/src/package.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netsim.dir/src/package.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/package.cpp -o CMakeFiles/netsim.dir/src/package.cpp.s

CMakeFiles/netsim.dir/src/storage_types.cpp.o: CMakeFiles/netsim.dir/flags.make
CMakeFiles/netsim.dir/src/storage_types.cpp.o: ../src/storage_types.cpp
CMakeFiles/netsim.dir/src/storage_types.cpp.o: CMakeFiles/netsim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/netsim.dir/src/storage_types.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/netsim.dir/src/storage_types.cpp.o -MF CMakeFiles/netsim.dir/src/storage_types.cpp.o.d -o CMakeFiles/netsim.dir/src/storage_types.cpp.o -c /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/storage_types.cpp

CMakeFiles/netsim.dir/src/storage_types.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netsim.dir/src/storage_types.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/storage_types.cpp > CMakeFiles/netsim.dir/src/storage_types.cpp.i

CMakeFiles/netsim.dir/src/storage_types.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netsim.dir/src/storage_types.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/storage_types.cpp -o CMakeFiles/netsim.dir/src/storage_types.cpp.s

CMakeFiles/netsim.dir/src/nodes.cpp.o: CMakeFiles/netsim.dir/flags.make
CMakeFiles/netsim.dir/src/nodes.cpp.o: ../src/nodes.cpp
CMakeFiles/netsim.dir/src/nodes.cpp.o: CMakeFiles/netsim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/netsim.dir/src/nodes.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/netsim.dir/src/nodes.cpp.o -MF CMakeFiles/netsim.dir/src/nodes.cpp.o.d -o CMakeFiles/netsim.dir/src/nodes.cpp.o -c /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/nodes.cpp

CMakeFiles/netsim.dir/src/nodes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netsim.dir/src/nodes.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/nodes.cpp > CMakeFiles/netsim.dir/src/nodes.cpp.i

CMakeFiles/netsim.dir/src/nodes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netsim.dir/src/nodes.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/nodes.cpp -o CMakeFiles/netsim.dir/src/nodes.cpp.s

CMakeFiles/netsim.dir/src/helpers.cpp.o: CMakeFiles/netsim.dir/flags.make
CMakeFiles/netsim.dir/src/helpers.cpp.o: ../src/helpers.cpp
CMakeFiles/netsim.dir/src/helpers.cpp.o: CMakeFiles/netsim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/netsim.dir/src/helpers.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/netsim.dir/src/helpers.cpp.o -MF CMakeFiles/netsim.dir/src/helpers.cpp.o.d -o CMakeFiles/netsim.dir/src/helpers.cpp.o -c /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/helpers.cpp

CMakeFiles/netsim.dir/src/helpers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netsim.dir/src/helpers.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/helpers.cpp > CMakeFiles/netsim.dir/src/helpers.cpp.i

CMakeFiles/netsim.dir/src/helpers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netsim.dir/src/helpers.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/helpers.cpp -o CMakeFiles/netsim.dir/src/helpers.cpp.s

CMakeFiles/netsim.dir/src/factory.cpp.o: CMakeFiles/netsim.dir/flags.make
CMakeFiles/netsim.dir/src/factory.cpp.o: ../src/factory.cpp
CMakeFiles/netsim.dir/src/factory.cpp.o: CMakeFiles/netsim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/netsim.dir/src/factory.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/netsim.dir/src/factory.cpp.o -MF CMakeFiles/netsim.dir/src/factory.cpp.o.d -o CMakeFiles/netsim.dir/src/factory.cpp.o -c /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/factory.cpp

CMakeFiles/netsim.dir/src/factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netsim.dir/src/factory.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/factory.cpp > CMakeFiles/netsim.dir/src/factory.cpp.i

CMakeFiles/netsim.dir/src/factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netsim.dir/src/factory.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/factory.cpp -o CMakeFiles/netsim.dir/src/factory.cpp.s

CMakeFiles/netsim.dir/src/reports.cpp.o: CMakeFiles/netsim.dir/flags.make
CMakeFiles/netsim.dir/src/reports.cpp.o: ../src/reports.cpp
CMakeFiles/netsim.dir/src/reports.cpp.o: CMakeFiles/netsim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/netsim.dir/src/reports.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/netsim.dir/src/reports.cpp.o -MF CMakeFiles/netsim.dir/src/reports.cpp.o.d -o CMakeFiles/netsim.dir/src/reports.cpp.o -c /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/reports.cpp

CMakeFiles/netsim.dir/src/reports.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netsim.dir/src/reports.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/reports.cpp > CMakeFiles/netsim.dir/src/reports.cpp.i

CMakeFiles/netsim.dir/src/reports.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netsim.dir/src/reports.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/reports.cpp -o CMakeFiles/netsim.dir/src/reports.cpp.s

CMakeFiles/netsim.dir/src/simulation.cpp.o: CMakeFiles/netsim.dir/flags.make
CMakeFiles/netsim.dir/src/simulation.cpp.o: ../src/simulation.cpp
CMakeFiles/netsim.dir/src/simulation.cpp.o: CMakeFiles/netsim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/netsim.dir/src/simulation.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/netsim.dir/src/simulation.cpp.o -MF CMakeFiles/netsim.dir/src/simulation.cpp.o.d -o CMakeFiles/netsim.dir/src/simulation.cpp.o -c /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/simulation.cpp

CMakeFiles/netsim.dir/src/simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netsim.dir/src/simulation.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/simulation.cpp > CMakeFiles/netsim.dir/src/simulation.cpp.i

CMakeFiles/netsim.dir/src/simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netsim.dir/src/simulation.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/src/simulation.cpp -o CMakeFiles/netsim.dir/src/simulation.cpp.s

CMakeFiles/netsim.dir/main.cpp.o: CMakeFiles/netsim.dir/flags.make
CMakeFiles/netsim.dir/main.cpp.o: ../main.cpp
CMakeFiles/netsim.dir/main.cpp.o: CMakeFiles/netsim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/netsim.dir/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/netsim.dir/main.cpp.o -MF CMakeFiles/netsim.dir/main.cpp.o.d -o CMakeFiles/netsim.dir/main.cpp.o -c /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/main.cpp

CMakeFiles/netsim.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netsim.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/main.cpp > CMakeFiles/netsim.dir/main.cpp.i

CMakeFiles/netsim.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netsim.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/main.cpp -o CMakeFiles/netsim.dir/main.cpp.s

# Object files for target netsim
netsim_OBJECTS = \
"CMakeFiles/netsim.dir/src/package.cpp.o" \
"CMakeFiles/netsim.dir/src/storage_types.cpp.o" \
"CMakeFiles/netsim.dir/src/nodes.cpp.o" \
"CMakeFiles/netsim.dir/src/helpers.cpp.o" \
"CMakeFiles/netsim.dir/src/factory.cpp.o" \
"CMakeFiles/netsim.dir/src/reports.cpp.o" \
"CMakeFiles/netsim.dir/src/simulation.cpp.o" \
"CMakeFiles/netsim.dir/main.cpp.o"

# External object files for target netsim
netsim_EXTERNAL_OBJECTS =

netsim.exe: CMakeFiles/netsim.dir/src/package.cpp.o
netsim.exe: CMakeFiles/netsim.dir/src/storage_types.cpp.o
netsim.exe: CMakeFiles/netsim.dir/src/nodes.cpp.o
netsim.exe: CMakeFiles/netsim.dir/src/helpers.cpp.o
netsim.exe: CMakeFiles/netsim.dir/src/factory.cpp.o
netsim.exe: CMakeFiles/netsim.dir/src/reports.cpp.o
netsim.exe: CMakeFiles/netsim.dir/src/simulation.cpp.o
netsim.exe: CMakeFiles/netsim.dir/main.cpp.o
netsim.exe: CMakeFiles/netsim.dir/build.make
netsim.exe: CMakeFiles/netsim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable netsim.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/netsim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/netsim.dir/build: netsim.exe
.PHONY : CMakeFiles/netsim.dir/build

CMakeFiles/netsim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/netsim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/netsim.dir/clean

CMakeFiles/netsim.dir/depend:
	cd /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/cmake-build-debug-cygwin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/cmake-build-debug-cygwin /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/cmake-build-debug-cygwin /cygdrive/c/Users/Zosia/Desktop/rzeczy/netsim/Advanced-OOP/cmake-build-debug-cygwin/CMakeFiles/netsim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/netsim.dir/depend

