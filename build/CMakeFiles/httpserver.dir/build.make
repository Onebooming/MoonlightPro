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
include CMakeFiles/httpserver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/httpserver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/httpserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/httpserver.dir/flags.make

CMakeFiles/httpserver.dir/codegen:
.PHONY : CMakeFiles/httpserver.dir/codegen

CMakeFiles/httpserver.dir/src/mnjson.cpp.o: CMakeFiles/httpserver.dir/flags.make
CMakeFiles/httpserver.dir/src/mnjson.cpp.o: /home/parallels/chenglei_work/2025/MoonLightPro/src/mnjson.cpp
CMakeFiles/httpserver.dir/src/mnjson.cpp.o: CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/httpserver.dir/src/mnjson.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/httpserver.dir/src/mnjson.cpp.o -MF CMakeFiles/httpserver.dir/src/mnjson.cpp.o.d -o CMakeFiles/httpserver.dir/src/mnjson.cpp.o -c /home/parallels/chenglei_work/2025/MoonLightPro/src/mnjson.cpp

CMakeFiles/httpserver.dir/src/mnjson.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/src/mnjson.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/chenglei_work/2025/MoonLightPro/src/mnjson.cpp > CMakeFiles/httpserver.dir/src/mnjson.cpp.i

CMakeFiles/httpserver.dir/src/mnjson.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/src/mnjson.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/chenglei_work/2025/MoonLightPro/src/mnjson.cpp -o CMakeFiles/httpserver.dir/src/mnjson.cpp.s

CMakeFiles/httpserver.dir/src/mnlog.cpp.o: CMakeFiles/httpserver.dir/flags.make
CMakeFiles/httpserver.dir/src/mnlog.cpp.o: /home/parallels/chenglei_work/2025/MoonLightPro/src/mnlog.cpp
CMakeFiles/httpserver.dir/src/mnlog.cpp.o: CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/httpserver.dir/src/mnlog.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/httpserver.dir/src/mnlog.cpp.o -MF CMakeFiles/httpserver.dir/src/mnlog.cpp.o.d -o CMakeFiles/httpserver.dir/src/mnlog.cpp.o -c /home/parallels/chenglei_work/2025/MoonLightPro/src/mnlog.cpp

CMakeFiles/httpserver.dir/src/mnlog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/src/mnlog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/chenglei_work/2025/MoonLightPro/src/mnlog.cpp > CMakeFiles/httpserver.dir/src/mnlog.cpp.i

CMakeFiles/httpserver.dir/src/mnlog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/src/mnlog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/chenglei_work/2025/MoonLightPro/src/mnlog.cpp -o CMakeFiles/httpserver.dir/src/mnlog.cpp.s

CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.o: CMakeFiles/httpserver.dir/flags.make
CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.o: /home/parallels/chenglei_work/2025/MoonLightPro/src/http/core/mnhttpserver.cpp
CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.o: CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.o -MF CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.o.d -o CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.o -c /home/parallels/chenglei_work/2025/MoonLightPro/src/http/core/mnhttpserver.cpp

CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/chenglei_work/2025/MoonLightPro/src/http/core/mnhttpserver.cpp > CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.i

CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/chenglei_work/2025/MoonLightPro/src/http/core/mnhttpserver.cpp -o CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.s

CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.o: CMakeFiles/httpserver.dir/flags.make
CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.o: /home/parallels/chenglei_work/2025/MoonLightPro/src/http/app/app_hello.cpp
CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.o: CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.o -MF CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.o.d -o CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.o -c /home/parallels/chenglei_work/2025/MoonLightPro/src/http/app/app_hello.cpp

CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/chenglei_work/2025/MoonLightPro/src/http/app/app_hello.cpp > CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.i

CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/chenglei_work/2025/MoonLightPro/src/http/app/app_hello.cpp -o CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.s

CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.o: CMakeFiles/httpserver.dir/flags.make
CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.o: /home/parallels/chenglei_work/2025/MoonLightPro/src/http/app/app_admin_info.cpp
CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.o: CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.o -MF CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.o.d -o CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.o -c /home/parallels/chenglei_work/2025/MoonLightPro/src/http/app/app_admin_info.cpp

CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/chenglei_work/2025/MoonLightPro/src/http/app/app_admin_info.cpp > CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.i

CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/chenglei_work/2025/MoonLightPro/src/http/app/app_admin_info.cpp -o CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.s

CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.o: CMakeFiles/httpserver.dir/flags.make
CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.o: /home/parallels/chenglei_work/2025/MoonLightPro/src/server/mnhttpserverdemo.cpp
CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.o: CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.o -MF CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.o.d -o CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.o -c /home/parallels/chenglei_work/2025/MoonLightPro/src/server/mnhttpserverdemo.cpp

CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/chenglei_work/2025/MoonLightPro/src/server/mnhttpserverdemo.cpp > CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.i

CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/chenglei_work/2025/MoonLightPro/src/server/mnhttpserverdemo.cpp -o CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.s

# Object files for target httpserver
httpserver_OBJECTS = \
"CMakeFiles/httpserver.dir/src/mnjson.cpp.o" \
"CMakeFiles/httpserver.dir/src/mnlog.cpp.o" \
"CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.o" \
"CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.o" \
"CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.o" \
"CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.o"

# External object files for target httpserver
httpserver_EXTERNAL_OBJECTS =

httpserver: CMakeFiles/httpserver.dir/src/mnjson.cpp.o
httpserver: CMakeFiles/httpserver.dir/src/mnlog.cpp.o
httpserver: CMakeFiles/httpserver.dir/src/http/core/mnhttpserver.cpp.o
httpserver: CMakeFiles/httpserver.dir/src/http/app/app_hello.cpp.o
httpserver: CMakeFiles/httpserver.dir/src/http/app/app_admin_info.cpp.o
httpserver: CMakeFiles/httpserver.dir/src/server/mnhttpserverdemo.cpp.o
httpserver: CMakeFiles/httpserver.dir/build.make
httpserver: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
httpserver: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
httpserver: /usr/lib/x86_64-linux-gnu/libssl.so
httpserver: /usr/lib/x86_64-linux-gnu/libcrypto.so
httpserver: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.71.0
httpserver: CMakeFiles/httpserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable httpserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/httpserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/httpserver.dir/build: httpserver
.PHONY : CMakeFiles/httpserver.dir/build

CMakeFiles/httpserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/httpserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/httpserver.dir/clean

CMakeFiles/httpserver.dir/depend:
	cd /home/parallels/chenglei_work/2025/MoonLightPro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/chenglei_work/2025/MoonLightPro /home/parallels/chenglei_work/2025/MoonLightPro /home/parallels/chenglei_work/2025/MoonLightPro/build /home/parallels/chenglei_work/2025/MoonLightPro/build /home/parallels/chenglei_work/2025/MoonLightPro/build/CMakeFiles/httpserver.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/httpserver.dir/depend

