# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.8)

# Project's name
project(ka_data_structures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic")

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)


# The following folder will be included
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR})
  

# data_structures lib code
set(DATA_STRUCTURES_LIB_SRC
  ${CMAKE_SOURCE_DIR}/src/node.cpp
  ${CMAKE_SOURCE_DIR}/src/linked_list.cpp
  ${CMAKE_SOURCE_DIR}/src/dyn_array.cpp
  ${CMAKE_SOURCE_DIR}/src/dictionary.cpp
)


add_library(data_structures SHARED ${DATA_STRUCTURES_LIB_SRC})

# create the data structures library
add_executable(test_ll ${CMAKE_SOURCE_DIR}/src/test_linked_list.cpp )
add_executable(test_da ${CMAKE_SOURCE_DIR}/src/test_dyn_array.cpp )
add_executable(test_dict ${CMAKE_SOURCE_DIR}/src/test_dictionary.cpp )

target_link_libraries(test_ll data_structures )
target_link_libraries(test_da data_structures )
target_link_libraries(test_dict data_structures )


