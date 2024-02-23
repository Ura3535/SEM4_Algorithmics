#include <iostream>

int main()
{
    int n, m, a, res = 0;
    std::cin >> n >> m;
    for (int i = 0; i != n; ++i) {
        std::cin >> a;
        while (m % ++a == 0)
            ++res;
    }
    std::cout << res;
}