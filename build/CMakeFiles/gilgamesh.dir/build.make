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
CMAKE_COMMAND = /home/mohamed/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/mohamed/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mohamed/Dev/C++/GilgameshEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mohamed/Dev/C++/GilgameshEngine/build

# Include any dependencies generated for this target.
include CMakeFiles/gilgamesh.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gilgamesh.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gilgamesh.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gilgamesh.dir/flags.make

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/application.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/application.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/application.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/application.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/window.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/window.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/window.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/window.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/logger.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/logger.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/logger.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/logger.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/memory_alloc.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/memory_alloc.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/memory_alloc.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/memory_alloc.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/event.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/event.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/event.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/event.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/input.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/input.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/input.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/core/input.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/main.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/main.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/main.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/main.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/math/gilg_random.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/math/gilg_random.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/math/gilg_random.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/math/gilg_random.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/backend/graphics_context.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/backend/graphics_context.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/backend/graphics_context.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/backend/graphics_context.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/backend/vertex_array.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/backend/vertex_array.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/backend/vertex_array.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/backend/vertex_array.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/renderer.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/renderer.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/renderer.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/renderer.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/renderer_queue.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/renderer_queue.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/renderer_queue.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/renderer_queue.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/camera3d.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/camera3d.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/camera3d.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/graphics/camera3d.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/resources/resource_manager.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/resources/resource_manager.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/resources/resource_manager.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/resources/resource_manager.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/resources/shader.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/resources/shader.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/resources/shader.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/resources/shader.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.s

CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/resources/texture2d.cpp
CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.o -MF CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.o.d -o CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/resources/texture2d.cpp

CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/resources/texture2d.cpp > CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.i

CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/src/gilgamesh/resources/texture2d.cpp -o CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.s

CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.o: /home/mohamed/Dev/C++/GilgameshEngine/libs/src/stb_image/stb_image.cpp
CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.o -MF CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.o.d -o CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngine/libs/src/stb_image/stb_image.cpp

CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/libs/src/stb_image/stb_image.cpp > CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.i

CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/libs/src/stb_image/stb_image.cpp -o CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.s

CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.o: CMakeFiles/gilgamesh.dir/flags.make
CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.o: /home/mohamed/Dev/C++/GilgameshEngine/libs/src/glad/gl.c
CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.o: CMakeFiles/gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.o -MF CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.o.d -o CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.o -c /home/mohamed/Dev/C++/GilgameshEngine/libs/src/glad/gl.c

CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mohamed/Dev/C++/GilgameshEngine/libs/src/glad/gl.c > CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.i

CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mohamed/Dev/C++/GilgameshEngine/libs/src/glad/gl.c -o CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.s

# Object files for target gilgamesh
gilgamesh_OBJECTS = \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.o" \
"CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.o" \
"CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.o" \
"CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.o"

# External object files for target gilgamesh
gilgamesh_EXTERNAL_OBJECTS =

gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/core/application.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/core/window.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/core/logger.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/core/memory_alloc.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/core/event.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/core/input.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/main.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/math/gilg_random.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/graphics_context.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/backend/vertex_array.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/renderer_queue.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/graphics/camera3d.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/resource_manager.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/shader.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/src/gilgamesh/resources/texture2d.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/libs/src/stb_image/stb_image.cpp.o
gilgamesh: CMakeFiles/gilgamesh.dir/libs/src/glad/gl.c.o
gilgamesh: CMakeFiles/gilgamesh.dir/build.make
gilgamesh: /usr/lib/x86_64-linux-gnu/libglfw.so
gilgamesh: CMakeFiles/gilgamesh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable gilgamesh"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gilgamesh.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gilgamesh.dir/build: gilgamesh
.PHONY : CMakeFiles/gilgamesh.dir/build

CMakeFiles/gilgamesh.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gilgamesh.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gilgamesh.dir/clean

CMakeFiles/gilgamesh.dir/depend:
	cd /home/mohamed/Dev/C++/GilgameshEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mohamed/Dev/C++/GilgameshEngine /home/mohamed/Dev/C++/GilgameshEngine /home/mohamed/Dev/C++/GilgameshEngine/build /home/mohamed/Dev/C++/GilgameshEngine/build /home/mohamed/Dev/C++/GilgameshEngine/build/CMakeFiles/gilgamesh.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/gilgamesh.dir/depend

