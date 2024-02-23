#include <iostream>

int main()
{
    int n, a, b, c, d;
    std::cin >> n;
    for (int i = 0; i != n; ++i) {
        std::cin >> a >> b >> c >> d;
        if (((a & 1) == (c & 1) && (b & 1) != (d & 1)) || ((a & 1) != (c & 1) && (b & 1) == (d & 1)))
            std::cout << 1;
        else
            std::cout << 0;
    }
}