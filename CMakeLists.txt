

cmake_minimum_required (VERSION 2.8)

project (TestCases)

# header path
include_directories ("${PROJECT_SOURCE_DIR}/include")
include_directories ("~/.progs/include")

# library path
link_directories("~/.progs/lib")

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -std=c++11 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
# add_compile_options(-std=c++11)
 

# target and its link libraries
add_executable(test_stringx test/test_stringx.cc) 

add_executable(test_path test/test_path.cc) 
target_link_libraries(test_path gtest pthread)

add_executable(test_strutils test/test_strutils.cc) 
 


 
