#pragma once

template<typename T>
void InsertionSort(T *array, int length) {

    T key;
    auto j = 0;
    for (auto i=1; i<length; ++i) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            --j;
        }
        array[j+1] = key;
    }
}

template<typename T>
void Merge(T *array, int p, int q, int r) {
    auto n1 = q - p + 1;
    auto n2 = r - q;

    T leftArray[n1];
    T rightArray[n2];

    for (auto i=0; i<n1; ++i) {
        leftArray[i] = array[p+i];
    }

    for (auto i=0; i<n2; ++i) {
        rightArray[i] = array[q+i+1];
    }

    auto i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (leftArray[i] < rightArray[j]) {
            array[k] = leftArray[i];
            ++i;
        } else {
            array[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        array[k] = rightArray[j];
        ++j;
        ++k;
    }
}


// p is array lower position, r is array upper position
template<typename T>
void MergeSort(T *array, int p, int r) {
    if (p < r) {
        auto q = (p + r - 1) / 2;
        MergeSort(array, p, q);
        MergeSort(array, q+1, r);
        Merge(array, p, q, r);
    }
}
