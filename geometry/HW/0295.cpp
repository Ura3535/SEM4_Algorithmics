#include <iostream>

int main() {
    int r, res = 0;
    std::cin >> r;
    for (int i = 1; i <= r; ++i)
        for (int j = 0; j <= r; ++j)
            if (i * i + j * j <= r * r)
                ++res;
            else break;

    std::cout << res * 4 + 1;

    return 0;
}