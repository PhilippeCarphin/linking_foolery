cmake_minimum_required(VERSION 3.10)
project(linking_foolery)

set(CMAKE_CXX_STANDARD 14)

if(${APPLE})
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -undefined dynamic_lookup")
else()
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--allow-shlib-undefined")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--allow-shlib-undefined")
endif()

include_directories(${CMAKE_SOURCE_DIR})
add_subdirectory(interface)
add_subdirectory(backend)
add_subdirectory(executable)
