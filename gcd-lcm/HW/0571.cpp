#include <iostream>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int a, res, n;
    std::cin >> n >> res;
    for (int i = 1; i != n; ++i) {
        std::cin >> a;
        res = gcd(res, a);
    }
    std::cout << res;
}