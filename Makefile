# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/quagmire/projects/romviewer/lsrom

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/quagmire/projects/romviewer/lsrom

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target package_source
package_source:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool for source..."
	/usr/bin/cpack --config ./CPackSourceConfig.cmake /home/quagmire/projects/romviewer/lsrom/CPackSourceConfig.cmake
.PHONY : package_source

# Special rule for the target package_source
package_source/fast: package_source

.PHONY : package_source/fast

# Special rule for the target package
package: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool..."
	/usr/bin/cpack --config ./CPackConfig.cmake
.PHONY : package

# Special rule for the target package
package/fast: package

.PHONY : package/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/quagmire/projects/romviewer/lsrom/CMakeFiles /home/quagmire/projects/romviewer/lsrom/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/quagmire/projects/romviewer/lsrom/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named lsrom

# Build rule for target.
lsrom: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 lsrom
.PHONY : lsrom

# fast build rule for target.
lsrom/fast:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/build
.PHONY : lsrom/fast

src/Debug.o: src/Debug.cpp.o

.PHONY : src/Debug.o

# target to build an object file
src/Debug.cpp.o:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/Debug.cpp.o
.PHONY : src/Debug.cpp.o

src/Debug.i: src/Debug.cpp.i

.PHONY : src/Debug.i

# target to preprocess a source file
src/Debug.cpp.i:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/Debug.cpp.i
.PHONY : src/Debug.cpp.i

src/Debug.s: src/Debug.cpp.s

.PHONY : src/Debug.s

# target to generate assembly for a file
src/Debug.cpp.s:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/Debug.cpp.s
.PHONY : src/Debug.cpp.s

src/Genre.o: src/Genre.cpp.o

.PHONY : src/Genre.o

# target to build an object file
src/Genre.cpp.o:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/Genre.cpp.o
.PHONY : src/Genre.cpp.o

src/Genre.i: src/Genre.cpp.i

.PHONY : src/Genre.i

# target to preprocess a source file
src/Genre.cpp.i:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/Genre.cpp.i
.PHONY : src/Genre.cpp.i

src/Genre.s: src/Genre.cpp.s

.PHONY : src/Genre.s

# target to generate assembly for a file
src/Genre.cpp.s:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/Genre.cpp.s
.PHONY : src/Genre.cpp.s

src/OutputFormatter.o: src/OutputFormatter.cpp.o

.PHONY : src/OutputFormatter.o

# target to build an object file
src/OutputFormatter.cpp.o:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/OutputFormatter.cpp.o
.PHONY : src/OutputFormatter.cpp.o

src/OutputFormatter.i: src/OutputFormatter.cpp.i

.PHONY : src/OutputFormatter.i

# target to preprocess a source file
src/OutputFormatter.cpp.i:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/OutputFormatter.cpp.i
.PHONY : src/OutputFormatter.cpp.i

src/OutputFormatter.s: src/OutputFormatter.cpp.s

.PHONY : src/OutputFormatter.s

# target to generate assembly for a file
src/OutputFormatter.cpp.s:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/OutputFormatter.cpp.s
.PHONY : src/OutputFormatter.cpp.s

src/Rom.o: src/Rom.cpp.o

.PHONY : src/Rom.o

# target to build an object file
src/Rom.cpp.o:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/Rom.cpp.o
.PHONY : src/Rom.cpp.o

src/Rom.i: src/Rom.cpp.i

.PHONY : src/Rom.i

# target to preprocess a source file
src/Rom.cpp.i:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/Rom.cpp.i
.PHONY : src/Rom.cpp.i

src/Rom.s: src/Rom.cpp.s

.PHONY : src/Rom.s

# target to generate assembly for a file
src/Rom.cpp.s:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/Rom.cpp.s
.PHONY : src/Rom.cpp.s

src/RomManager.o: src/RomManager.cpp.o

.PHONY : src/RomManager.o

# target to build an object file
src/RomManager.cpp.o:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/RomManager.cpp.o
.PHONY : src/RomManager.cpp.o

src/RomManager.i: src/RomManager.cpp.i

.PHONY : src/RomManager.i

# target to preprocess a source file
src/RomManager.cpp.i:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/RomManager.cpp.i
.PHONY : src/RomManager.cpp.i

src/RomManager.s: src/RomManager.cpp.s

.PHONY : src/RomManager.s

# target to generate assembly for a file
src/RomManager.cpp.s:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/RomManager.cpp.s
.PHONY : src/RomManager.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/lsrom.dir/build.make CMakeFiles/lsrom.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... lsrom"
	@echo "... package_source"
	@echo "... package"
	@echo "... src/Debug.o"
	@echo "... src/Debug.i"
	@echo "... src/Debug.s"
	@echo "... src/Genre.o"
	@echo "... src/Genre.i"
	@echo "... src/Genre.s"
	@echo "... src/OutputFormatter.o"
	@echo "... src/OutputFormatter.i"
	@echo "... src/OutputFormatter.s"
	@echo "... src/Rom.o"
	@echo "... src/Rom.i"
	@echo "... src/Rom.s"
	@echo "... src/RomManager.o"
	@echo "... src/RomManager.i"
	@echo "... src/RomManager.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

