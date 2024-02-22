#include <iostream>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int arr[4]{};
    int a, res = 0;
    for (int i = 0; i != 4; ++i) {
        std::cin >> arr[i];
        a = gcd(a, arr[i]);
    }
    for (int i = 0; i != 4; ++i) {
        res += arr[i] / a;
    }
    std::cout << res;
}