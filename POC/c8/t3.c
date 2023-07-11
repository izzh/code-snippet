#include <stdio.h>

// int identity_matrix(int matrix[][10], int size)
int identity_matrix(int *matrix, int size)
{
    int i, j;
    for (i = 0; i<size; i++) {
        // if (matrix[i][i] != 1) {
        if (matrix[i*size+i] != 1) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int martix[10][10];
    int i;
    for (i=0; i<10; i++) {
        martix[i][i] = 1;
    }
    printf("identity_matrix: %d\n", identity_matrix(martix, 10));
    return 0;
}
