#include <iostream>
#include <string>
#include <algorithm>

int f(int a, int b, int c, long long n) {
    std::string s{ char('0' + a), char('0' + b), char('0' + c) };


    for (long long i = 0; i < n - 2; ++i) {
        std::swap(a, b);
        std::swap(b, c);
        c = (a + b + c) % 10;
        std::string tmp{ char('0' + a), char('0' + b), char('0' + c) };
        auto it = s.find(tmp);
        if (it == std::string::npos)
            s += char('0' + c);
        else {
            it += 2;
            n -= it;
            s = s.substr(it);
            break;
        }
    }

    return s[n % s.size()] - '0';
}

int main()
{
    int a, b, c;
    long long n;
    std::cin >> a >> b >> c >> n;
    --n;
    std::cout << f(a, b, c, n);
}