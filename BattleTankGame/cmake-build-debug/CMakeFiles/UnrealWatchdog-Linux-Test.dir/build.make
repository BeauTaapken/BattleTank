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
CMAKE_COMMAND = /home/beau/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/beau/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/crucial-ssd/UnrealGames/BattleTank/BattleTankGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/crucial-ssd/UnrealGames/BattleTank/BattleTankGame/cmake-build-debug

# Utility rule file for UnrealWatchdog-Linux-Test.

# Include any custom commands dependencies for this target.
include CMakeFiles/UnrealWatchdog-Linux-Test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/UnrealWatchdog-Linux-Test.dir/progress.make

CMakeFiles/UnrealWatchdog-Linux-Test:
	cd /home/beau/UnrealEngine-4.23.0-release && bash /home/beau/UnrealEngine-4.23.0-release/Engine/Build/BatchFiles/Linux/Build.sh UnrealWatchdog Linux Test -game -progress -buildscw

UnrealWatchdog-Linux-Test: CMakeFiles/UnrealWatchdog-Linux-Test
UnrealWatchdog-Linux-Test: CMakeFiles/UnrealWatchdog-Linux-Test.dir/build.make
.PHONY : UnrealWatchdog-Linux-Test

# Rule to build all files generated by this target.
CMakeFiles/UnrealWatchdog-Linux-Test.dir/build: UnrealWatchdog-Linux-Test
.PHONY : CMakeFiles/UnrealWatchdog-Linux-Test.dir/build

CMakeFiles/UnrealWatchdog-Linux-Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UnrealWatchdog-Linux-Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UnrealWatchdog-Linux-Test.dir/clean

CMakeFiles/UnrealWatchdog-Linux-Test.dir/depend:
	cd /mnt/crucial-ssd/UnrealGames/BattleTank/BattleTankGame/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/crucial-ssd/UnrealGames/BattleTank/BattleTankGame /mnt/crucial-ssd/UnrealGames/BattleTank/BattleTankGame /mnt/crucial-ssd/UnrealGames/BattleTank/BattleTankGame/cmake-build-debug /mnt/crucial-ssd/UnrealGames/BattleTank/BattleTankGame/cmake-build-debug /mnt/crucial-ssd/UnrealGames/BattleTank/BattleTankGame/cmake-build-debug/CMakeFiles/UnrealWatchdog-Linux-Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UnrealWatchdog-Linux-Test.dir/depend
