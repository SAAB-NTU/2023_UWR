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
CMAKE_SOURCE_DIR = /home/saab/Desktop/2023_UWR/opencv/opencv-4.x

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build

# Include any dependencies generated for this target.
include apps/version/CMakeFiles/opencv_version.dir/depend.make

# Include the progress variables for this target.
include apps/version/CMakeFiles/opencv_version.dir/progress.make

# Include the compile flags for this target's objects.
include apps/version/CMakeFiles/opencv_version.dir/flags.make

apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o: apps/version/CMakeFiles/opencv_version.dir/flags.make
apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o: ../apps/version/opencv_version.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o"
	cd /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build/apps/version && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_version.dir/opencv_version.cpp.o -c /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/apps/version/opencv_version.cpp

apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_version.dir/opencv_version.cpp.i"
	cd /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build/apps/version && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/apps/version/opencv_version.cpp > CMakeFiles/opencv_version.dir/opencv_version.cpp.i

apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_version.dir/opencv_version.cpp.s"
	cd /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build/apps/version && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/apps/version/opencv_version.cpp -o CMakeFiles/opencv_version.dir/opencv_version.cpp.s

# Object files for target opencv_version
opencv_version_OBJECTS = \
"CMakeFiles/opencv_version.dir/opencv_version.cpp.o"

# External object files for target opencv_version
opencv_version_EXTERNAL_OBJECTS =

bin/opencv_version: apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o
bin/opencv_version: apps/version/CMakeFiles/opencv_version.dir/build.make
bin/opencv_version: 3rdparty/lib/libippiw.a
bin/opencv_version: 3rdparty/ippicv/ippicv_lnx/icv/lib/intel64/libippicv.a
bin/opencv_version: lib/libopencv_core.so.4.8.0
bin/opencv_version: apps/version/CMakeFiles/opencv_version.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/opencv_version"
	cd /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build/apps/version && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_version.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/version/CMakeFiles/opencv_version.dir/build: bin/opencv_version

.PHONY : apps/version/CMakeFiles/opencv_version.dir/build

apps/version/CMakeFiles/opencv_version.dir/clean:
	cd /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build/apps/version && $(CMAKE_COMMAND) -P CMakeFiles/opencv_version.dir/cmake_clean.cmake
.PHONY : apps/version/CMakeFiles/opencv_version.dir/clean

apps/version/CMakeFiles/opencv_version.dir/depend:
	cd /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/saab/Desktop/2023_UWR/opencv/opencv-4.x /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/apps/version /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build/apps/version /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build/apps/version/CMakeFiles/opencv_version.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/version/CMakeFiles/opencv_version.dir/depend

