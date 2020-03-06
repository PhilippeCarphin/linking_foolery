add_library(interface SHARED interface.cpp)
target_link_libraries(interface PRIVATE backend)
