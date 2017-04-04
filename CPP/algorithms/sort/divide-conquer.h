#pragma once
#include <cmath>

template<typename T>
int BinarySearch(T *array, int length, T key) {
    auto low = 0, high = length - 1;
    auto mid = 0;

    while (high >= low){
        mid = (high + low) / 2;
        if (array[mid] == key) {
            return mid;
        } else if (array[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

template<typename T>
T XN(T x, int n) {
    if (n == 0) {
        return 1;
    }  else if (n == 1) {
        return x;
    } else {
        return x * XN(x, n-1);
    }
}

int Fibonacci(int n) {
    if (n == 0 || n == 1 || n== 2) {
        return n == 0 ? 0 : 1;
    }
    double alpha = 1 / 2.0 * (1 + sqrt(5.0));

    return static_cast<int>((XN(alpha, n) - (XN(1.0 - alpha, n))) / sqrt(5.0));
}
