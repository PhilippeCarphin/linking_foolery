add_executable(executable executable.cpp)

target_link_libraries(
        executable
    PRIVATE
        interface
        backend
)

if(${APPLE})
    #define LIB_INTERFACE_PATH "${CMAKE_BINARY_DIR}/interface/libinterface.dylib"
    target_compile_definitions(executable PRIVATE "LIB_INTERFACE_PATH=\"${CMAKE_BINARY_DIR}/interface/libinterface.dylib\"")
else()
    target_link_libraries(executable PRIVATE dl)
    #define LIB_INTERFACE_PATH "${CMAKE_BINARY_DIR}/interface/libinterface.so"
    target_compile_definitions(executable PRIVATE "LIB_INTERFACE_PATH=\"${CMAKE_BINARY_DIR}/interface/libinterface.so\"")
endif()
