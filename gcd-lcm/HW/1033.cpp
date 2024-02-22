#include <iostream>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b - gcd(a, b);
}