# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bl1023/new/advanced-programming-group-yen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bl1023/new/advanced-programming-group-yen/build

# Include any dependencies generated for this target.
include CMakeFiles/Yen_Project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Yen_Project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Yen_Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Yen_Project.dir/flags.make

CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.o: CMakeFiles/Yen_Project.dir/flags.make
CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.o: /Users/bl1023/new/advanced-programming-group-yen/src/ColorConversion.cpp
CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.o: CMakeFiles/Yen_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.o -MF CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.o.d -o CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.o -c /Users/bl1023/new/advanced-programming-group-yen/src/ColorConversion.cpp

CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bl1023/new/advanced-programming-group-yen/src/ColorConversion.cpp > CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.i

CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bl1023/new/advanced-programming-group-yen/src/ColorConversion.cpp -o CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.s

CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.o: CMakeFiles/Yen_Project.dir/flags.make
CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.o: /Users/bl1023/new/advanced-programming-group-yen/src/ColourFilterCorrection.cpp
CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.o: CMakeFiles/Yen_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.o -MF CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.o.d -o CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.o -c /Users/bl1023/new/advanced-programming-group-yen/src/ColourFilterCorrection.cpp

CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bl1023/new/advanced-programming-group-yen/src/ColourFilterCorrection.cpp > CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.i

CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bl1023/new/advanced-programming-group-yen/src/ColourFilterCorrection.cpp -o CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.s

CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.o: CMakeFiles/Yen_Project.dir/flags.make
CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.o: /Users/bl1023/new/advanced-programming-group-yen/src/EdgeDetectionFilter.cpp
CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.o: CMakeFiles/Yen_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.o -MF CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.o.d -o CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.o -c /Users/bl1023/new/advanced-programming-group-yen/src/EdgeDetectionFilter.cpp

CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bl1023/new/advanced-programming-group-yen/src/EdgeDetectionFilter.cpp > CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.i

CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bl1023/new/advanced-programming-group-yen/src/EdgeDetectionFilter.cpp -o CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.s

CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.o: CMakeFiles/Yen_Project.dir/flags.make
CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.o: /Users/bl1023/new/advanced-programming-group-yen/src/Filter3D.cpp
CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.o: CMakeFiles/Yen_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.o -MF CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.o.d -o CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.o -c /Users/bl1023/new/advanced-programming-group-yen/src/Filter3D.cpp

CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bl1023/new/advanced-programming-group-yen/src/Filter3D.cpp > CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.i

CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bl1023/new/advanced-programming-group-yen/src/Filter3D.cpp -o CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.s

CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.o: CMakeFiles/Yen_Project.dir/flags.make
CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.o: /Users/bl1023/new/advanced-programming-group-yen/src/FilterInputHandler.cpp
CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.o: CMakeFiles/Yen_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.o -MF CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.o.d -o CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.o -c /Users/bl1023/new/advanced-programming-group-yen/src/FilterInputHandler.cpp

CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bl1023/new/advanced-programming-group-yen/src/FilterInputHandler.cpp > CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.i

CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bl1023/new/advanced-programming-group-yen/src/FilterInputHandler.cpp -o CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.s

CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.o: CMakeFiles/Yen_Project.dir/flags.make
CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.o: /Users/bl1023/new/advanced-programming-group-yen/src/FilterInputHandler3D.cpp
CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.o: CMakeFiles/Yen_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.o -MF CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.o.d -o CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.o -c /Users/bl1023/new/advanced-programming-group-yen/src/FilterInputHandler3D.cpp

CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bl1023/new/advanced-programming-group-yen/src/FilterInputHandler3D.cpp > CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.i

CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bl1023/new/advanced-programming-group-yen/src/FilterInputHandler3D.cpp -o CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.s

CMakeFiles/Yen_Project.dir/src/Image.cpp.o: CMakeFiles/Yen_Project.dir/flags.make
CMakeFiles/Yen_Project.dir/src/Image.cpp.o: /Users/bl1023/new/advanced-programming-group-yen/src/Image.cpp
CMakeFiles/Yen_Project.dir/src/Image.cpp.o: CMakeFiles/Yen_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Yen_Project.dir/src/Image.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yen_Project.dir/src/Image.cpp.o -MF CMakeFiles/Yen_Project.dir/src/Image.cpp.o.d -o CMakeFiles/Yen_Project.dir/src/Image.cpp.o -c /Users/bl1023/new/advanced-programming-group-yen/src/Image.cpp

CMakeFiles/Yen_Project.dir/src/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yen_Project.dir/src/Image.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bl1023/new/advanced-programming-group-yen/src/Image.cpp > CMakeFiles/Yen_Project.dir/src/Image.cpp.i

CMakeFiles/Yen_Project.dir/src/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yen_Project.dir/src/Image.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bl1023/new/advanced-programming-group-yen/src/Image.cpp -o CMakeFiles/Yen_Project.dir/src/Image.cpp.s

CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.o: CMakeFiles/Yen_Project.dir/flags.make
CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.o: /Users/bl1023/new/advanced-programming-group-yen/src/ImageBlurFilter.cpp
CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.o: CMakeFiles/Yen_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.o -MF CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.o.d -o CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.o -c /Users/bl1023/new/advanced-programming-group-yen/src/ImageBlurFilter.cpp

CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bl1023/new/advanced-programming-group-yen/src/ImageBlurFilter.cpp > CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.i

CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bl1023/new/advanced-programming-group-yen/src/ImageBlurFilter.cpp -o CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.s

CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.o: CMakeFiles/Yen_Project.dir/flags.make
CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.o: /Users/bl1023/new/advanced-programming-group-yen/src/ProjectionInputHandler.cpp
CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.o: CMakeFiles/Yen_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.o -MF CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.o.d -o CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.o -c /Users/bl1023/new/advanced-programming-group-yen/src/ProjectionInputHandler.cpp

CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bl1023/new/advanced-programming-group-yen/src/ProjectionInputHandler.cpp > CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.i

CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bl1023/new/advanced-programming-group-yen/src/ProjectionInputHandler.cpp -o CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.s

CMakeFiles/Yen_Project.dir/src/Projections.cpp.o: CMakeFiles/Yen_Project.dir/flags.make
CMakeFiles/Yen_Project.dir/src/Projections.cpp.o: /Users/bl1023/new/advanced-programming-group-yen/src/Projections.cpp
CMakeFiles/Yen_Project.dir/src/Projections.cpp.o: CMakeFiles/Yen_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Yen_Project.dir/src/Projections.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yen_Project.dir/src/Projections.cpp.o -MF CMakeFiles/Yen_Project.dir/src/Projections.cpp.o.d -o CMakeFiles/Yen_Project.dir/src/Projections.cpp.o -c /Users/bl1023/new/advanced-programming-group-yen/src/Projections.cpp

CMakeFiles/Yen_Project.dir/src/Projections.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yen_Project.dir/src/Projections.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bl1023/new/advanced-programming-group-yen/src/Projections.cpp > CMakeFiles/Yen_Project.dir/src/Projections.cpp.i

CMakeFiles/Yen_Project.dir/src/Projections.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yen_Project.dir/src/Projections.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bl1023/new/advanced-programming-group-yen/src/Projections.cpp -o CMakeFiles/Yen_Project.dir/src/Projections.cpp.s

CMakeFiles/Yen_Project.dir/src/Slice.cpp.o: CMakeFiles/Yen_Project.dir/flags.make
CMakeFiles/Yen_Project.dir/src/Slice.cpp.o: /Users/bl1023/new/advanced-programming-group-yen/src/Slice.cpp
CMakeFiles/Yen_Project.dir/src/Slice.cpp.o: CMakeFiles/Yen_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Yen_Project.dir/src/Slice.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yen_Project.dir/src/Slice.cpp.o -MF CMakeFiles/Yen_Project.dir/src/Slice.cpp.o.d -o CMakeFiles/Yen_Project.dir/src/Slice.cpp.o -c /Users/bl1023/new/advanced-programming-group-yen/src/Slice.cpp

CMakeFiles/Yen_Project.dir/src/Slice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yen_Project.dir/src/Slice.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bl1023/new/advanced-programming-group-yen/src/Slice.cpp > CMakeFiles/Yen_Project.dir/src/Slice.cpp.i

CMakeFiles/Yen_Project.dir/src/Slice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yen_Project.dir/src/Slice.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bl1023/new/advanced-programming-group-yen/src/Slice.cpp -o CMakeFiles/Yen_Project.dir/src/Slice.cpp.s

CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.o: CMakeFiles/Yen_Project.dir/flags.make
CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.o: /Users/bl1023/new/advanced-programming-group-yen/src/SliceInputHandler.cpp
CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.o: CMakeFiles/Yen_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.o -MF CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.o.d -o CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.o -c /Users/bl1023/new/advanced-programming-group-yen/src/SliceInputHandler.cpp

CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bl1023/new/advanced-programming-group-yen/src/SliceInputHandler.cpp > CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.i

CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bl1023/new/advanced-programming-group-yen/src/SliceInputHandler.cpp -o CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.s

CMakeFiles/Yen_Project.dir/src/Volume.cpp.o: CMakeFiles/Yen_Project.dir/flags.make
CMakeFiles/Yen_Project.dir/src/Volume.cpp.o: /Users/bl1023/new/advanced-programming-group-yen/src/Volume.cpp
CMakeFiles/Yen_Project.dir/src/Volume.cpp.o: CMakeFiles/Yen_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Yen_Project.dir/src/Volume.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yen_Project.dir/src/Volume.cpp.o -MF CMakeFiles/Yen_Project.dir/src/Volume.cpp.o.d -o CMakeFiles/Yen_Project.dir/src/Volume.cpp.o -c /Users/bl1023/new/advanced-programming-group-yen/src/Volume.cpp

CMakeFiles/Yen_Project.dir/src/Volume.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yen_Project.dir/src/Volume.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bl1023/new/advanced-programming-group-yen/src/Volume.cpp > CMakeFiles/Yen_Project.dir/src/Volume.cpp.i

CMakeFiles/Yen_Project.dir/src/Volume.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yen_Project.dir/src/Volume.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bl1023/new/advanced-programming-group-yen/src/Volume.cpp -o CMakeFiles/Yen_Project.dir/src/Volume.cpp.s

CMakeFiles/Yen_Project.dir/src/main.cpp.o: CMakeFiles/Yen_Project.dir/flags.make
CMakeFiles/Yen_Project.dir/src/main.cpp.o: /Users/bl1023/new/advanced-programming-group-yen/src/main.cpp
CMakeFiles/Yen_Project.dir/src/main.cpp.o: CMakeFiles/Yen_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Yen_Project.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yen_Project.dir/src/main.cpp.o -MF CMakeFiles/Yen_Project.dir/src/main.cpp.o.d -o CMakeFiles/Yen_Project.dir/src/main.cpp.o -c /Users/bl1023/new/advanced-programming-group-yen/src/main.cpp

CMakeFiles/Yen_Project.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yen_Project.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bl1023/new/advanced-programming-group-yen/src/main.cpp > CMakeFiles/Yen_Project.dir/src/main.cpp.i

CMakeFiles/Yen_Project.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yen_Project.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bl1023/new/advanced-programming-group-yen/src/main.cpp -o CMakeFiles/Yen_Project.dir/src/main.cpp.s

# Object files for target Yen_Project
Yen_Project_OBJECTS = \
"CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.o" \
"CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.o" \
"CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.o" \
"CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.o" \
"CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.o" \
"CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.o" \
"CMakeFiles/Yen_Project.dir/src/Image.cpp.o" \
"CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.o" \
"CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.o" \
"CMakeFiles/Yen_Project.dir/src/Projections.cpp.o" \
"CMakeFiles/Yen_Project.dir/src/Slice.cpp.o" \
"CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.o" \
"CMakeFiles/Yen_Project.dir/src/Volume.cpp.o" \
"CMakeFiles/Yen_Project.dir/src/main.cpp.o"

# External object files for target Yen_Project
Yen_Project_EXTERNAL_OBJECTS =

Yen_Project: CMakeFiles/Yen_Project.dir/src/ColorConversion.cpp.o
Yen_Project: CMakeFiles/Yen_Project.dir/src/ColourFilterCorrection.cpp.o
Yen_Project: CMakeFiles/Yen_Project.dir/src/EdgeDetectionFilter.cpp.o
Yen_Project: CMakeFiles/Yen_Project.dir/src/Filter3D.cpp.o
Yen_Project: CMakeFiles/Yen_Project.dir/src/FilterInputHandler.cpp.o
Yen_Project: CMakeFiles/Yen_Project.dir/src/FilterInputHandler3D.cpp.o
Yen_Project: CMakeFiles/Yen_Project.dir/src/Image.cpp.o
Yen_Project: CMakeFiles/Yen_Project.dir/src/ImageBlurFilter.cpp.o
Yen_Project: CMakeFiles/Yen_Project.dir/src/ProjectionInputHandler.cpp.o
Yen_Project: CMakeFiles/Yen_Project.dir/src/Projections.cpp.o
Yen_Project: CMakeFiles/Yen_Project.dir/src/Slice.cpp.o
Yen_Project: CMakeFiles/Yen_Project.dir/src/SliceInputHandler.cpp.o
Yen_Project: CMakeFiles/Yen_Project.dir/src/Volume.cpp.o
Yen_Project: CMakeFiles/Yen_Project.dir/src/main.cpp.o
Yen_Project: CMakeFiles/Yen_Project.dir/build.make
Yen_Project: CMakeFiles/Yen_Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable Yen_Project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Yen_Project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Yen_Project.dir/build: Yen_Project
.PHONY : CMakeFiles/Yen_Project.dir/build

CMakeFiles/Yen_Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Yen_Project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Yen_Project.dir/clean

CMakeFiles/Yen_Project.dir/depend:
	cd /Users/bl1023/new/advanced-programming-group-yen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bl1023/new/advanced-programming-group-yen /Users/bl1023/new/advanced-programming-group-yen /Users/bl1023/new/advanced-programming-group-yen/build /Users/bl1023/new/advanced-programming-group-yen/build /Users/bl1023/new/advanced-programming-group-yen/build/CMakeFiles/Yen_Project.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Yen_Project.dir/depend

