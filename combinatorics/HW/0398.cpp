#include <iostream>
#include <math.h>

int main() {
    long long n;
    std::cin >> n;

    std::cout << (int)ceil((-1 + sqrt(8 * n + 1)) / 2);
}