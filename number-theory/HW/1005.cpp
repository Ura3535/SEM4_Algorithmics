#include <iostream>

int main()
{
    int t, m, n;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m;
        std::cout << (n % (m + 1) != 0 ? 1 : 2);
    }
}