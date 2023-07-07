#include <stdio.h>

int leap_year(unsigned int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 1 : 0;
}

int main(int argc, char const *argv[])
{
    unsigned int arr[] = {2000, 2020, 2021, 2022, 2023, 2024};
    int i = 0;
    for (; i < sizeof(arr)/sizeof(unsigned int); i++) {
        if (leap_year(arr[i])) {
            printf("%d is leap year\n", arr[i]);
        }
    }
    return 0;
}
