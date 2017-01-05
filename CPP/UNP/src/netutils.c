/*************************************************************************
 > File Name: netutils.c
 > Author:
 > Mail:
 > Created Time: 2017年01月05日 星期四 14时15分51秒
 ************************************************************************/
#include "netutils.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int
create_and_bind(const char *addr, const char *port)
{
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int s, listen_sock;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC; /* return ipv4 & ipv6 choices*/
    hints.ai_socktype = SOCK_STREAM; /* Tcp socket*/

    s = getaddrinfo(addr, port, &hints, &result);
    if (s != 0) {
        perror("getaddrinfo");
        return -1;
    }

    for (rp = result; rp != NULL; rp = rp->ai_next) {
        listen_sock = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (listen_sock == -1) {
            continue;
        }

        // set reuse addr before bind
        int opt = 1;
        setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

        int err = setreuseport(listen_sock);
        if (err == 0) {
            perror("set reuse port!");
        }

        s = bind(listen_sock, rp->ai_addr, rp->ai_addrlen);
        if (s == 0) {
            break;
        } else {
            perror("bind");
        }

        // close fd
        close(listen_sock);
    }

    if (rp == NULL) {
        perror("can't bind success!");
        return -1;
    }

    freeaddrinfo(result);

    return listen_sock;
}

int
setnonblocking(int fd)
{
    int flags;
    if (-1 == (flags=fcntl(fd, F_GETFL, 0))) {
        flags = 0;
    }

    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

int
setreuseport(int socket)
{
    int opt = 1;
    return setsockopt(socket, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt));
}
