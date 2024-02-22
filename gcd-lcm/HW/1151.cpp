#include <iostream>
#include <algorithm>

int gcd(int a, int b)
{
    if (b == 0) return a;
    a %= b;
    return gcd(b, a);
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b);

    return 0;
}