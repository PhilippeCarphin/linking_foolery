add_executable(executable executable.cpp)

target_link_libraries(
        executable
    PRIVATE
        interface
        dl
)

target_compile_definitions(executable PRIVATE "LIB_INTERFACE_PATH=\"${CMAKE_BINARY_DIR}/interface/libinterface.so\"")
