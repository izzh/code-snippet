#include <iostream>

#include "divide-conquer.h"

int main() {
    int arr[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, \
        9, 10, 11};

    std::cout << "Position: " << BinarySearch(arr, 12, 6) << std::endl;
    std::cout << "Position: " << BinarySearch(arr, 12, 13) << std::endl;
    std::cout << "Position: " << BinarySearch(arr, 12, 0) << std::endl;

    std::cout << "Value: " << XN(2, 10) << std::endl;
    std::cout << "Value: " << XN(0, 0) << std::endl;
    std::cout << "Value: " << XN(3, 6) << std::endl;

    std::cout << "Fibonacci:: " << Fibonacci(10) << std::endl;
    std::cout << "Fibonacci:: " << Fibonacci(20) << std::endl;
}

