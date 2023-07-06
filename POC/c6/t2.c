#include <stdio.h>

int del_substr(char *str, const char *substr)
{
    if (str == NULL || substr == NULL) {
        return 0;
    }
    int len = 0;
    char *sub = (char *)substr;
    while (*sub++ != '\0') {
        len++;
    }
    if (len == 0) {
        return 1;
    }
    char *s = str;
    int count = 0;
    sub = (char *)substr;
    char *pos = NULL;
    while (*s != '\0' && *sub != '\0') {
        if (*s != *sub) {
            sub = (char *)substr;
            count = 0;
        } else {
            if (count == 0) {
                pos = s;
            }
            sub++;
            count++;
        }
        s++;
    }
    if (count == len) {
        char *pos2 = pos + len;
        while (*pos2 != '\0') {
            *pos++ = *pos2++;
        }
        *pos = '\0';
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    char s[8] = "ABCDEFG";
    char *sub = "CDE";
    char *sub2 = "FGH";
    printf("out: %d, str: %s\n", del_substr(s, sub), s);
    printf("out: %d\n", del_substr(s, sub2));
    return 0;
}
