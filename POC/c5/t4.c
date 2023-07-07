#include <stdio.h>

#define MAX_BIT_NUMBER 8192


/*
bit_number start with 1
*/
void set_bit(char bit_array[], unsigned bit_number)
{
    if (bit_number > MAX_BIT_NUMBER) {
        return;
    }
    int pos = (bit_number - 1) / 8;
    int bit_pos = 8 - (bit_number % 8);
    bit_pos = (bit_pos == 8) ? 0 : bit_pos;
    bit_array[pos] |= (1<<bit_pos);
}

void clear_bit(char bit_array[], unsigned bit_number)
{
    if (bit_number > MAX_BIT_NUMBER) {
        return;
    }
    int pos = (bit_number - 1) / 8;
    int bit_pos = 8 - (bit_number % 8);
    bit_pos = (bit_pos == 8) ? 0 : bit_pos;
    bit_array[pos] &= ~(1<<bit_pos);
}

void assign_bit(char bit_array[], unsigned bit_number, int value)
{
    value == 0 ? clear_bit(bit_array, bit_number) : set_bit(bit_array, bit_number);
}

int test_bit(char bit_array[], unsigned bit_number)
{
    if (bit_number > MAX_BIT_NUMBER) {
        return 0;
    }
    int pos = (bit_number - 1) / 8;
    int bit_pos = 8 - (bit_number % 8);
    bit_pos = (bit_pos == 8) ? 0 : bit_pos;
    return (bit_array[pos] & (1<<bit_pos)) == 0 ? 0 : 1;
}

int main(int argc, char const *argv[])
{
    char bit_array[MAX_BIT_NUMBER/8] = {0};
    set_bit(bit_array, 5);
    printf("%x\n", bit_array[0]);
    printf("%x\n", test_bit(bit_array, 5));
    return 0;
}
