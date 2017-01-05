/*************************************************************************
 > File Name: netutils_test.c
 > Author:
 > Mail:
 > Created Time: 2017年01月05日 星期四 15时54分39秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>

#include "netutils.h"

int
main(int argc, char *argv[])
{
    if (argc < 3) {
        perror("args with addr and port");
        exit(EXIT_FAILURE);
    }

    int listen_fd;
    // test create_and_bind
    if (-1 == (listen_fd = create_and_bind(argv[1], argv[2]))) {
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_fd, SOMAXCONN) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    // test setnonblocking
    // setnonblocking(listen_fd);

    int serverfd = accept(listen_fd, NULL, NULL);
    if (serverfd == -1) {
        perror("accept!");
        return -1;
    }
    // set serverfd
    setnonblocking(serverfd);
    // disable Nagle algorithm
    int opt = 1;
    setsockopt(serverfd, SOL_TCP, TCP_NODELAY, &opt, sizeof(opt));

    printf("accept success, wait 1 second close\n");
    // wait 1 second
    sleep(1);

    close(listen_fd);
    close(serverfd);

    return 0;
}
