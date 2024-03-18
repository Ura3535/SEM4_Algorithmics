#include <iostream>

int main()
{
    long long n, res = 3;
    std::cin >> n;
    for (int i = 1; i != n; ++i, res *= 2)
        ;
    std::cout << res;
}