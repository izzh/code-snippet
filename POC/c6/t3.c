#include <stdio.h>

void reverse_string(char *string)
{
    if (string == NULL) {
        return;
    }
    char *start = string;
    int len = 0;
    while (*start++ != '\0') {
        len++;
    }
    int i = 0, j = len-1;
    /*1 2 3 4 5 6*/
    while (i < (len / 2)) {
        char c = *(string+i);
        *(string+i) = *(string+j);
        *(string+j) = c;
        i++;
        j--;
    }

}

int main(int argc, char const *argv[])
{
    /* code */
    char s[8] = {'a', 'b', 'c', 'd', 'e', 'f'};
    reverse_string(s);
    printf("out:  %s\n", s);
    char s2[8] = {'1', 'b', 'c', 'd', 'e', 'f', '7'};
    reverse_string(s2);
    printf("out:  %s\n", s2);
    return 0;
}
