cmake_minimum_required(VERSION 3.0) 
project(lsrom)           

#enable vim's pluign YouCompleteMe for autocomplete
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

###############################################################################
#                             List Sources and Data                           #
###############################################################################

set (sources 
             src/main.cpp
             
             src/Rom.cpp
             src/RomManager.cpp
)

set (headers
             include/main.h

             include/Rom.h
             include/RomManager.h

             include/constants/constants.h
             include/constants/kOptions.h
)

set (data 
          TODO
)

###############################################################################
#                              Target Definitions                             #
###############################################################################

#include all resources and data in the project
add_executable(lsrom ${sources} ${data})

#compiler flags
target_compile_options(lsrom PUBLIC -Wall) 

# This allows to include files relative to the root of the src directory with a <> pair
target_include_directories(lsrom PUBLIC src/main)

# This copies all resource files in the build directory.
# We need this, because we want to work with paths relative to the executable.
file(COPY ${data} DESTINATION resources)

###############################################################################
#                                 Dependencies                                #
###############################################################################

# This defines the variables Boost_LIBRARIES that containts all library names
# that we need to link into the program.
find_package(Boost 1.36.0 COMPONENTS program_options  REQUIRED)

target_link_libraries(lsrom PUBLIC
  ${Boost_LIBRARIES}
)

###############################################################################
#                                   Tests                                     #
###############################################################################

#find_package(GTest)

if(0) #GTEST_FOUND)
  add_executable(unit_tests ${sources_test} ${sources})

  # This define is added to prevent collision with the main.
  # It might be better solved by not adding the source with the main to the
  # testing target.
  target_compile_definitions(unit_tests PUBLIC UNIT_TESTS)

  # This allows us to use the executable as a link library, and inherit all 
  # linker options and library dependencies from it, by simply adding it as dependency.
  set_target_properties(example PROPERTIES ENABLE_EXPORTS on)

  target_link_libraries(unit_tests PUBLIC
    ${GTEST_BOTH_LIBRARIES}
    example
  )

  target_include_directories(unit_tests PUBLIC
    ${GTEST_INCLUDE_DIRS} # doesn't do anything on linux
  )
  
endif()

###############################################################################
#                                 Packaging                                   #
###############################################################################

if(0)
# All install commands get the same destination. this allows us to use paths
# relative to the executable.
install(TARGETS lsrom DESTINATION example_destination)

# This is basically a repeat of the file copy instruction that copies the
# resources in the build directory, but here we tell cmake that we want it
# in the package.
install(DIRECTORY resources DESTINATION example_destination)

# Now comes everything we need, to create a package
# there are a lot more variables you can set, and some
# you need to set for some package types, but we want to
# be minimal here.
set(CPACK_PACKAGE_NAME "MyExample")
set(CPACK_PACKAGE_VERSION "1.0.0")

# We don't want to split our program up into several incomplete pieces.
set(CPACK_MONOLITHIC_INSTALL 1)

# This must be last
include(CPack)
endif()
