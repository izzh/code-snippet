include_directories(../)
add_executable(utils-test.app netutils_test.c)
target_link_libraries(utils-test.app netutils)
