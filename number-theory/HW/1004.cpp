#include <iostream>

int f(bool* begin, bool* end) {
    int res = 0;
    for (int i = 0; begin + i != end; res += (1 << i) * begin[i], ++i)
        ;
    return res;
}

int main()
{
    int n, end = 0, res = 0;
    bool a[100]{};
    std::cin >> n;
    for (; n > 0; a[end] = n % 2, ++end, n /= 2)
        ;

    for (int i = 0; i != end; ++i) {
        a[end + i] = a[i];
        res = std::max(f(a + i, a + end + i), res);
    }
    std::cout << res;
}