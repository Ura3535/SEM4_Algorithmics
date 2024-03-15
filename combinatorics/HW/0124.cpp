#include <iostream>

int main() {
    int n;
    while (std::cin >> n)
        std::cout << n * 4 << ' ' << n * n << '\n';
}