#include <iostream>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;

    if (a == 0 && b == 0) {
        std::cout << 0;
        return 0;
    }
    else std::cout << (a == 0 || b == 0 || a == b ? 1 : 2);

    for (int i = 1; i != n; ++i)
        std::cout << '0';

    return 0;
}