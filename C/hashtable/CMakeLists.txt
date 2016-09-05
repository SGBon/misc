cmake_minimum_required(VERSION 2.8)

project (hashtable)
set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(hashtable SHARED src/fnvhash.c src/hashtable.c src/htutil.c)
