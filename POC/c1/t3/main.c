#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ch;
    signed char checksum = -1;
    while ((ch=getchar()) != EOF)
    {
        checksum += ch;
        if (ch == '\n') {
            printf("%d\n", checksum);
            break;
        }
    }
    
    return 0;
}
