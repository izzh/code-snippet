#include <stdio.h>

#include "increment.h"
#include "negate.h"

int main(int argc, char const *argv[])
{
    int arr[3] = {10, 0, -10};
    int i = 0;
    for (; i < (sizeof(arr)/sizeof(int)); i++) {
        printf("origin value:%d, increment value:%d, negate value:%d\n", arr[i], increment(arr[i]), negate(arr[i]));
    }
    return 0;
}
