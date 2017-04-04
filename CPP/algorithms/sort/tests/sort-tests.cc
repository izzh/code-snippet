#include <iostream>

#include "sort.h"

int main() {
    // int array[10] = {9, 2, 0, 1, 4, 3, 6, 5, 7,8};
    // InsertionSort(array, 10);
    double array[10] = {1024.0, 3.14, 4.4, 0.12, 10.24, 5.13, 2048.96, 23.58, 6.66, 0.1314};
    MergeSort(array, 0, 9);

    for (auto i=0; i<10; ++i) {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;


    return 0;
}
