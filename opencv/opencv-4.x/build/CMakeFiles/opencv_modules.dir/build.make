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

# Utility rule file for opencv_modules.

# Include the progress variables for this target.
include CMakeFiles/opencv_modules.dir/progress.make

opencv_modules: CMakeFiles/opencv_modules.dir/build.make

.PHONY : opencv_modules

# Rule to build all files generated by this target.
CMakeFiles/opencv_modules.dir/build: opencv_modules

.PHONY : CMakeFiles/opencv_modules.dir/build

CMakeFiles/opencv_modules.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opencv_modules.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opencv_modules.dir/clean

CMakeFiles/opencv_modules.dir/depend:
	cd /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/saab/Desktop/2023_UWR/opencv/opencv-4.x /home/saab/Desktop/2023_UWR/opencv/opencv-4.x /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build /home/saab/Desktop/2023_UWR/opencv/opencv-4.x/build/CMakeFiles/opencv_modules.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opencv_modules.dir/depend

