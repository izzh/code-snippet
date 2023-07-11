#include <stdio.h>

int ascii_to_integer(char *string)
{
    if (string == NULL) {
        return 0;
    }
    int result = 0;
    while (*string != '\0') {
        if (*string < '0' || *string > '9') {
            return 0;
        }
        result *= 10;
        result += *string - '0';
        string++;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    /* code */
    char s[5] = {'1', '0', '2', '4', '\0'};
    printf("out: %d\n", ascii_to_integer(s));

    return 0;
}
