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
CMAKE_SOURCE_DIR = /home/mohamed/Dev/C++/GilgameshEngineII

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mohamed/Dev/C++/GilgameshEngineII/build

# Include any dependencies generated for this target.
include CMakeFiles/Gilgamesh.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Gilgamesh.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Gilgamesh.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Gilgamesh.dir/flags.make

CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch: CMakeFiles/Gilgamesh.dir/flags.make
CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.cxx
CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx
CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch: CMakeFiles/Gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -x c++-header -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -MD -MT CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch -MF CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch.d -o CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch -c /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.cxx

CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -x c++-header -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -E /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.cxx > CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.i

CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -x c++-header -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -S /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.cxx -o CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.s

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.o: CMakeFiles/Gilgamesh.dir/flags.make
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.o: /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Core/Application.cpp
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.o: CMakeFiles/Gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -MD -MT CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.o -MF CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.o.d -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Core/Application.cpp

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -E /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Core/Application.cpp > CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.i

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -S /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Core/Application.cpp -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.s

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.o: CMakeFiles/Gilgamesh.dir/flags.make
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.o: /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Core/Window.cpp
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.o: CMakeFiles/Gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -MD -MT CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.o -MF CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.o.d -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Core/Window.cpp

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -E /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Core/Window.cpp > CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.i

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -S /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Core/Window.cpp -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.s

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.o: CMakeFiles/Gilgamesh.dir/flags.make
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.o: /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Managers/AssetManager.cpp
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.o: CMakeFiles/Gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -MD -MT CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.o -MF CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.o.d -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Managers/AssetManager.cpp

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -E /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Managers/AssetManager.cpp > CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.i

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -S /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Managers/AssetManager.cpp -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.s

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.o: CMakeFiles/Gilgamesh.dir/flags.make
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.o: /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Managers/EventManager.cpp
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.o: CMakeFiles/Gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -MD -MT CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.o -MF CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.o.d -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Managers/EventManager.cpp

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -E /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Managers/EventManager.cpp > CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.i

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -S /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Managers/EventManager.cpp -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.s

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.o: CMakeFiles/Gilgamesh.dir/flags.make
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.o: /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Managers/SceneManager.cpp
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.o: CMakeFiles/Gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -MD -MT CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.o -MF CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.o.d -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Managers/SceneManager.cpp

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -E /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Managers/SceneManager.cpp > CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.i

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -S /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Managers/SceneManager.cpp -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.s

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.o: CMakeFiles/Gilgamesh.dir/flags.make
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.o: /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Graphics/Renderer2D.cpp
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.o: CMakeFiles/Gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -MD -MT CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.o -MF CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.o.d -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Graphics/Renderer2D.cpp

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -E /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Graphics/Renderer2D.cpp > CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.i

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -S /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Graphics/Renderer2D.cpp -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.s

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.o: CMakeFiles/Gilgamesh.dir/flags.make
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.o: /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Graphics/Color.cpp
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.o: CMakeFiles/Gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -MD -MT CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.o -MF CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.o.d -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Graphics/Color.cpp

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -E /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Graphics/Color.cpp > CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.i

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -S /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Graphics/Color.cpp -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.s

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.o: CMakeFiles/Gilgamesh.dir/flags.make
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.o: /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Scene/Scene2D.cpp
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.o: CMakeFiles/Gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -MD -MT CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.o -MF CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.o.d -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Scene/Scene2D.cpp

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -E /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Scene/Scene2D.cpp > CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.i

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -S /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Scene/Scene2D.cpp -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.s

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.o: CMakeFiles/Gilgamesh.dir/flags.make
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.o: /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Components/Transform2D.cpp
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.o: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch
CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.o: CMakeFiles/Gilgamesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -MD -MT CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.o -MF CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.o.d -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.o -c /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Components/Transform2D.cpp

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -E /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Components/Transform2D.cpp > CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.i

CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/cmake_pch.hxx -S /home/mohamed/Dev/C++/GilgameshEngineII/Gilgamesh/src/Components/Transform2D.cpp -o CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.s

# Object files for target Gilgamesh
Gilgamesh_OBJECTS = \
"CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.o" \
"CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.o" \
"CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.o" \
"CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.o" \
"CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.o" \
"CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.o" \
"CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.o" \
"CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.o" \
"CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.o"

# External object files for target Gilgamesh
Gilgamesh_EXTERNAL_OBJECTS =

libGilgamesh.so: CMakeFiles/Gilgamesh.dir/cmake_pch.hxx.gch
libGilgamesh.so: CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Application.cpp.o
libGilgamesh.so: CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Core/Window.cpp.o
libGilgamesh.so: CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/AssetManager.cpp.o
libGilgamesh.so: CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/EventManager.cpp.o
libGilgamesh.so: CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Managers/SceneManager.cpp.o
libGilgamesh.so: CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Renderer2D.cpp.o
libGilgamesh.so: CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Graphics/Color.cpp.o
libGilgamesh.so: CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Scene/Scene2D.cpp.o
libGilgamesh.so: CMakeFiles/Gilgamesh.dir/Gilgamesh/src/Components/Transform2D.cpp.o
libGilgamesh.so: CMakeFiles/Gilgamesh.dir/build.make
libGilgamesh.so: /usr/lib/x86_64-linux-gnu/libglfw.so
libGilgamesh.so: CMakeFiles/Gilgamesh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX shared library libGilgamesh.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Gilgamesh.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Gilgamesh.dir/build: libGilgamesh.so
.PHONY : CMakeFiles/Gilgamesh.dir/build

CMakeFiles/Gilgamesh.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Gilgamesh.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Gilgamesh.dir/clean

CMakeFiles/Gilgamesh.dir/depend:
	cd /home/mohamed/Dev/C++/GilgameshEngineII/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mohamed/Dev/C++/GilgameshEngineII /home/mohamed/Dev/C++/GilgameshEngineII /home/mohamed/Dev/C++/GilgameshEngineII/build /home/mohamed/Dev/C++/GilgameshEngineII/build /home/mohamed/Dev/C++/GilgameshEngineII/build/CMakeFiles/Gilgamesh.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Gilgamesh.dir/depend
