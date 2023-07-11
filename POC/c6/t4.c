#include <stdio.h>

void eratosthenes(unsigned char data[], int len)
{
    int i, j;
    for (i = 2; i < len; i++) {
        if (data[i] == 0) {
            continue;
        }
        for (j = i+1; j < len; j++) {
            if ((data[j] == 1) && (j % i == 0)) {
                data[j] = 0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    unsigned char data[1001] = {0, 1, 1};
    int i;
    for (i = 2; i <= 1000; i++) {
        data[i] = 1;
    }
    eratosthenes(data, 1001);
    for (i = 0; i <= 1000; i++) {
        if (data[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
