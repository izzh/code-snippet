#include <stdio.h>

void copy_n(char dst[], const char src[], int n);

int main(int argc, char const *argv[])
{
    /* code */
    char a1[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
    char a2[10];
    copy_n(a2, a1, 5);
    printf("out: %s\n", a2);
    return 0;
}

void copy_n(char dst[], const char src[], int n)
{
    int i = 0;
    for (; i < n; i++) {
        dst[i] = src[i];
        if (src[i] == '\0') {
            break;
        }
    }
    while (i < n) {
        dst[++i] = '\0';
    }
}
