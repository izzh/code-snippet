#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 2048

int io_with_length_limit()
{
    char out[MAX_STR_LEN];
    char ch;
    int ch_len = 0;
    int line = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n') {
            out[ch_len] = '\0';
            printf("line: %d str_len:%ld output: %s\n", ++line, strlen(out), out);
            ch_len = 0;
            continue;

        }
        out[ch_len++] = ch;
    }
    return 0;
}

int io_without_length_limit()
{
    char *out;
    size_t out_len = MAX_STR_LEN;
    out = (char *)malloc(sizeof(char)*out_len);
    memset(out, 0, sizeof(out));

    char ch;
    int ch_len = 0;
    int line = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n') {
            out[ch_len] = '\0';
            printf("line: %d str_len:%ld output: %s\n", ++line, strlen(out), out);
            ch_len = 0;
            continue;

        }
        if (ch_len == out_len-1) {
            out_len += out_len;
            out = (char *)realloc(out, out_len);
        }
        out[ch_len++] = ch;
    }
    free(out);
    return 0;
}


int main(void)
{
    io_without_length_limit();
    return 0;
}