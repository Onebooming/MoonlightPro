# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /home/parallels/chenglei_work/2025/MoonLightPro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parallels/chenglei_work/2025/MoonLightPro/build

# Include any dependencies generated for this target.
include CMakeFiles/serverDemo2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/serverDemo2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/serverDemo2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serverDemo2.dir/flags.make

CMakeFiles/serverDemo2.dir/codegen:
.PHONY : CMakeFiles/serverDemo2.dir/codegen

CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.o: CMakeFiles/serverDemo2.dir/flags.make
CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.o: /home/parallels/chenglei_work/2025/MoonLightPro/src/mnepoll.cpp
CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.o: CMakeFiles/serverDemo2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.o -MF CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.o.d -o CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.o -c /home/parallels/chenglei_work/2025/MoonLightPro/src/mnepoll.cpp

CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/chenglei_work/2025/MoonLightPro/src/mnepoll.cpp > CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.i

CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/chenglei_work/2025/MoonLightPro/src/mnepoll.cpp -o CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.s

CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.o: CMakeFiles/serverDemo2.dir/flags.make
CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.o: /home/parallels/chenglei_work/2025/MoonLightPro/src/mnthreadpool.cpp
CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.o: CMakeFiles/serverDemo2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.o -MF CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.o.d -o CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.o -c /home/parallels/chenglei_work/2025/MoonLightPro/src/mnthreadpool.cpp

CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/chenglei_work/2025/MoonLightPro/src/mnthreadpool.cpp > CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.i

CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/chenglei_work/2025/MoonLightPro/src/mnthreadpool.cpp -o CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.s

CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.o: CMakeFiles/serverDemo2.dir/flags.make
CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.o: /home/parallels/chenglei_work/2025/MoonLightPro/src/mnsocket.cpp
CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.o: CMakeFiles/serverDemo2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.o -MF CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.o.d -o CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.o -c /home/parallels/chenglei_work/2025/MoonLightPro/src/mnsocket.cpp

CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/chenglei_work/2025/MoonLightPro/src/mnsocket.cpp > CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.i

CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/chenglei_work/2025/MoonLightPro/src/mnsocket.cpp -o CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.s

CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.o: CMakeFiles/serverDemo2.dir/flags.make
CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.o: /home/parallels/chenglei_work/2025/MoonLightPro/src/server/mnserversocket.cpp
CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.o: CMakeFiles/serverDemo2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.o -MF CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.o.d -o CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.o -c /home/parallels/chenglei_work/2025/MoonLightPro/src/server/mnserversocket.cpp

CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/chenglei_work/2025/MoonLightPro/src/server/mnserversocket.cpp > CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.i

CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/chenglei_work/2025/MoonLightPro/src/server/mnserversocket.cpp -o CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.s

CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.o: CMakeFiles/serverDemo2.dir/flags.make
CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.o: /home/parallels/chenglei_work/2025/MoonLightPro/src/server/serverdemo1.cpp
CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.o: CMakeFiles/serverDemo2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.o -MF CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.o.d -o CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.o -c /home/parallels/chenglei_work/2025/MoonLightPro/src/server/serverdemo1.cpp

CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/chenglei_work/2025/MoonLightPro/src/server/serverdemo1.cpp > CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.i

CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/chenglei_work/2025/MoonLightPro/src/server/serverdemo1.cpp -o CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.s

# Object files for target serverDemo2
serverDemo2_OBJECTS = \
"CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.o" \
"CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.o" \
"CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.o" \
"CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.o" \
"CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.o"

# External object files for target serverDemo2
serverDemo2_EXTERNAL_OBJECTS =

serverDemo2: CMakeFiles/serverDemo2.dir/src/mnepoll.cpp.o
serverDemo2: CMakeFiles/serverDemo2.dir/src/mnthreadpool.cpp.o
serverDemo2: CMakeFiles/serverDemo2.dir/src/mnsocket.cpp.o
serverDemo2: CMakeFiles/serverDemo2.dir/src/server/mnserversocket.cpp.o
serverDemo2: CMakeFiles/serverDemo2.dir/src/server/serverdemo1.cpp.o
serverDemo2: CMakeFiles/serverDemo2.dir/build.make
serverDemo2: CMakeFiles/serverDemo2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable serverDemo2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serverDemo2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serverDemo2.dir/build: serverDemo2
.PHONY : CMakeFiles/serverDemo2.dir/build

CMakeFiles/serverDemo2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serverDemo2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serverDemo2.dir/clean

CMakeFiles/serverDemo2.dir/depend:
	cd /home/parallels/chenglei_work/2025/MoonLightPro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/chenglei_work/2025/MoonLightPro /home/parallels/chenglei_work/2025/MoonLightPro /home/parallels/chenglei_work/2025/MoonLightPro/build /home/parallels/chenglei_work/2025/MoonLightPro/build /home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles/serverDemo2.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/serverDemo2.dir/depend

