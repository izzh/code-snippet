cmake_minimum_required(VERSION 2.6)

project(socks5-libev C CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

set(C_FLAGS
 -g
 -DCHECK_PTHREAD_RETURN_VALUE
 -D_FILE_OFFSET_BITS=64
 -Wall
 -Wextra
 -Werror
 -Wconversion
 -Wno-unused-parameter
 -Wpointer-arith
 -Wshadow
 -Wwrite-strings
 -march=native
 # -std=c99
 -std=gnu99
 -rdynamic
 )
string(REPLACE ";" " " CMAKE_C_FLAGS "${C_FLAGS}")

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_C_FLAGS_RELEASE "-O2 -fno-strict-aliasing -finline-limit=1000 -DNDEBUG")

add_subdirectory(src)
