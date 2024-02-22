#include <iostream>
#include <cstdint>

std::ostream& operator<<(std::ostream& dest, __int128_t value)
{
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char* d = std::end(buffer);
        do
        {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

__int128 gcd(__int128 a, __int128 b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int a, n;
    __int128 res;
    std::cin >> n;
    std::cin >> a;
    res = a;
    for (int i = 1; i != n; i++)
    {
        std::cin >> a;
        res = res / gcd(res, a) * a;
    }
    std::cout << res;
}