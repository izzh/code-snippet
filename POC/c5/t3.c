#include <stdio.h>

unsigned int reverse_bits(unsigned int value)
{
    unsigned char len = sizeof(unsigned int) * 8;
    unsigned int result = 0;
    int i = 0;
    for (; i<len/2; i++) {
        result |= (value & (1 << i))<<(len-2*i-1);
        result |= (value & (1 << (len-i-1)))>>(len-2*i-1);
    }

    return result;
}

int main(int argc, char const *argv[])
{
    unsigned int x = 25;
    unsigned int y = 0xc3000000;
    unsigned int z = 0x000000c3;
    printf("%u\n", reverse_bits(x));
    printf("%u\n", reverse_bits(y));
    return 0;
}
