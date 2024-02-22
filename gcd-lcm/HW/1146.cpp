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
    int arr[501][501]{};
    long long n, res;

    while (true) {
        std::cin >> n;
        if (n == 0) return 0;
        res = 0;
        for (int i = 1; i < n; ++i)
            for (int j = i + 1; j <= n; ++j) {
                if (arr[i][j] == 0)
                    arr[i][j] = gcd(i, j);
                res += arr[i][j];
            }
        std::cout << res << '\n';
    }

    return 0;
}