set(base_SRCS
    netutils.c
  )

add_library(netutils ${base_SRCS})

add_subdirectory(tests)
# include_directories(../list)
# add_executable(socks5-proxy ${base_SRCS})
# target_link_libraries(socks5-proxy ev m list)
