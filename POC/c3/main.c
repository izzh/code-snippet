#include <stdio.h>

int a = 1024;

int print()
{
    int *p;
    p = &a;
    printf("value:%d, pointer address:%p\n", a, p);
    return a;
}

int main(int argc, char const *argv[])
{
    print();
    extern int a;
    int *p = &a;
    printf("value:%d, pointer address:%p\n", a, p);
    // {
    //     extern int h = 2048;
    //     printf("h value:%d\n", h);
    // }
    enum Liquid  {OUNCE = 1, CUP = 8, PINT = 16, QUART = 32, GALLON = 128};
    enum Liquid jar;
    jar = QUART;
    printf("%d\n", jar);
    jar += PINT;
    printf("%d\n", jar);

    return 0;
}
