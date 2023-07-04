#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned char ch;

    while (scanf("%s", &ch) != EOF) 
    {
        // t1
        // printf("%c\n", (65 <= ch && ch <= 90)?(ch+32):ch);
        // t2
        if ('A' <= ch && ch <= 'Z') {
            ch += 13;
            ch = (ch > 'Z') ? (ch - 'Z' + 'A' - 1) : ch;
        } else if ('a' <= ch && ch  <= 'z') {
            ch += 13;
            ch = (ch > 'z') ? (ch - 'z' + 'a' - 1) : ch;
        }
        printf("%c\n", ch);
    }
    
    return 0;
}
