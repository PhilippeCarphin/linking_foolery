# This is the whole point: interface does not link with backend even though it should
add_library(interface SHARED interface.cpp)
target_link_libraries(interface PRIVATE backend)