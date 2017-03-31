#include <iostream>

#include "sort.h"

int main() {
    auto i = 3;
    auto j = 4;

    const auto sum = 7;

    if (test_env(i, j) == sum) {
        std::cout << "Testing success!"  << std::endl;
    }

    return 0;
}
