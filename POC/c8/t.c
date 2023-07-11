#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    int actual_data[20];
    int *data = actual_data - 1;
    printf("%p, %p\n", actual_data, actual_data+1);
    printf("%p, %d\n", data, *data);
    return 0;
}
