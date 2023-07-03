#include <stdio.h>
#include <string.h>

void deblank(char string[]);

int main(int argc, char const *argv[])
{
    /* code */
    char arr[100] = {'a', ' ', ' ', ' ', 'b', ' ', ' ', 'c', ' ', ' ', ' ', 'd', '\0'};
    printf("out: %s\n", arr);
    deblank(arr);
    printf("after deblank out: %s\n", arr);
    return 0;
}


void deblank(char string[])
{
    int len = strlen(string);
    int i = 0;
    for (; string[i] != '\0'; i++) {
        if (string[i] == ' ') {
            int j = i+1;
            while (string[j] == ' ') {
                j++;
            }
            strcpy(string+i+1, string+j);
        }
    }
}