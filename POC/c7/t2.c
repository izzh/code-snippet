#include <stdio.h>

int gcd(int m, int n)
{
    if (m<=0 || n<= 0) {
        return 0;
    }
    if (m % n == 0) {
        return n;
    }
    return gcd(n, m%n);
}

int main(int argc, char const *argv[])
{
    printf("%d\n", gcd(3, 22));
    return 0;
}
