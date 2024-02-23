#include <iostream>

int main()
{
    long long k, n, m, d;
    std::cin >> k >> n >> m >> d;

    long long a = d * k * n * m,
        b = k * n * m - (n * m + k * m + k * n);
    if (b >= 0 && a % b == 0)
        std::cout << a / b;
    else
        std::cout << -1;
}