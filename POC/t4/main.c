#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 1000

int main(int argc, char const *argv[])
{
    char max_str[MAX_STR_LEN];
    int max_len = 0;
    char input[MAX_STR_LEN];
    char ch;
    int ch_len = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n') {
            input[ch_len] = '\0';
            if (strcmp(input, "quit") == 0) {
                break;
            }
            if (ch_len > max_len) {
                strncpy(max_str, input, ch_len);
                max_len = ch_len;
            }
            ch_len = 0;
            continue;
        }
        input[ch_len++] = ch;
        if (ch_len >= MAX_STR_LEN) {
            break;
        }
    }
    printf("max_str_len: %d, str: %s\n", max_len, max_str);
       
    return 0;
}
