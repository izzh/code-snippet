#include <stdio.h>

int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit)
{
    int mask = 0;
    while (starting_bit >= ending_bit)
    {
       mask |= 1<<(starting_bit--);
    }
    original_value &= ~mask;
    value_to_store <<= ending_bit;
    value_to_store &= mask;

    return original_value | value_to_store;
}

int main(int argc, char const *argv[])
{
    int o = 0xffff;
    int v = 0x123;
    printf("%x\n", store_bit_field(o, v, 15, 4));
    return 0;
}
