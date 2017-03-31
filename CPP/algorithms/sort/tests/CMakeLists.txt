include_directories(../)

add_executable(sort-test sort-tests.cc)

target_link_libraries(sort-test sort)
