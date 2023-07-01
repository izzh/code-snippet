#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000

int compare_ints(const void *a, const void *b);
int read_column_numbers(int columns[], int max);
void rearrange(char *outpu, const char *input, int n_columns, const int columns[]);

int main(void)
{
    int n_columns;
    int columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    n_columns = read_column_numbers(columns, MAX_COLS);
    qsort(columns, n_columns, sizeof(int), compare_ints);

    while (fgets(input, MAX_INPUT, stdin) != NULL) {
        printf("Original input: %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Rearrange line: %s\n", output);
    }

    return 0;
}

int read_column_numbers(int columns[], int max)
{
    int num = 0;
    int ch;

    while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0) {
        num++;
    }
    if (num % 2 != 0) {
        if (num > max) {
            puts("Last column number is not paired.");
            exit(EXIT_FAILURE);
        }
    }
    while ((ch = getchar()) != EOF && ch != '\n'){
        ;
    }
    return num;
    
}

void rearrange(char *output, const char *input, int n_columns, const int columns[])
{
    int col = 0;
    int output_col;
    int len;

    len = strlen(input);
    output_col = 0;
    int nn_columns = n_columns;
    if (n_columns % 2 == 1) {
        n_columns -= 1;
    }
    for (; col < n_columns; col += 2) {
        int nchars = columns[col+1] - columns[col] + 1;

        if (columns[col] >= len || output_col == MAX_INPUT - 1) {
            break;
        }
        if (output_col + nchars > MAX_INPUT - 1) {
            nchars = MAX_INPUT - output_col - 1;
        }
        strncpy(output+output_col, input+columns[col], nchars);
        output_col += nchars;
    }
    if (nn_columns % 2 == 1) {
        if (columns[nn_columns-1] < len) {
            int nchars = len - columns[nn_columns-1] + 1;
            strncpy(output+output_col, input+columns[nn_columns-1], nchars);
            output_col += nchars;
        }
    }
    output[output_col] = '\0';
}

int compare_ints(const void *a, const void *b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}