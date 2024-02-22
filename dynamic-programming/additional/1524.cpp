#include <iostream>

int main()
{
    const int MAX = 71;
    long long arr[MAX][MAX]{};
    int n, t, p, q;
    std::cin >> q;
    for (int i = 1; i < MAX; ++i) {
        arr[i][0] = 1;
        arr[1][i] = 1;
    }
    for (int i = 2; i < MAX; ++i)
        for (int j = 1; j < MAX; ++j)
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];

    for (int i = 0; i != q; ++i) {
        std::cin >> n >> t >> p;
        std::cout << arr[n][t - n * p] << '\n';
    }
}