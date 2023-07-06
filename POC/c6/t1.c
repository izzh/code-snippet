#include <stdio.h>

char *find_char(const char *source, const char *chars)
{
    if (source == NULL || chars == NULL) {
        return NULL;
    }
    char *s = (char *)source;
    char *c;
    while (*s != '\0') {
        c = (char *)chars;
        while (*c != '\0') {
            if (*s == *c) {
                return s;
            }
            c++;
        }
        s++;
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    char *s = "ABCDEF";
    char *c = "XRCQEF";
    char *r;
    r = find_char(s, c);
    if (r != NULL) {
        printf("out:%s\n", r);
    }
    return 0;
}
