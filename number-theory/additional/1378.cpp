#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> compute_fibonacci() {
    const int MAX = 100000000;
    int a = 1, b = 2;
    std::vector<int> fibonacci{ a, b };
    while (b <= MAX) {
        b = b + a;
        a = b - a;
        fibonacci.push_back(b);
    }

    return fibonacci;
}

std::string to_fib_base(int x, const std::vector<int>& fibonacci) {
    std::string res;
    auto i = std::upper_bound(fibonacci.begin(), fibonacci.end(), x) - 1;
    while (i != fibonacci.begin()) {
        if (*i <= x) {
            res += "1";
            x -= *i;
        }
        else
            res += "0";
        --i;
    }
    if (x == 1)
        res += "1";
    else
        res += "0";

    return res;
}

int main()
{
    int n, a;
    std::vector<int> fibonacci(compute_fibonacci());
    std::cin >> n;

    for (int i = 0; i != n; ++i) {
        std::cin >> a;
        std::cout << a << " = " << to_fib_base(a, fibonacci) << " (fib)\n";
    }

}