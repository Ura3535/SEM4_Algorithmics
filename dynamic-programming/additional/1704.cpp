#include <iostream>

int main()
{
    const int MAX = 31;
    long long arr[MAX][MAX]{};
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i < MAX; ++i) {
        arr[i][1] = 1;
        arr[1][i] = 1;
    }
    for (int i = 2; i < MAX; ++i)
        for (int j = 2; j < MAX; ++j)
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    std::cout << arr[n][m];
}