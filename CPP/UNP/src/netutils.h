/*************************************************************************
 > File Name: netutils.h
 > Author:
 > Mail:
 > Created Time: 2017年01月05日 星期四 14时13分48秒
 ************************************************************************/
#pragma once
/* create and bind tcp socket
 * return -1 error*/
int create_and_bind(const char *addr, const char *port);

/* set nonblocking socket io*/
int setnonblocking(int fd);

/* set reuse port*/
int setreuseport(int socket);
