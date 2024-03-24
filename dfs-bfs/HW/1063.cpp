#include <iostream>

void dfs(bool arr[102][102], int i, int j) {
    arr[i][j] = false;
    if (arr[i - 1][j]) dfs(arr, i - 1, j);
    if (arr[i + 1][j]) dfs(arr, i + 1, j);
    if (arr[i][j - 1]) dfs(arr, i, j - 1);
    if (arr[i][j + 1]) dfs(arr, i, j + 1);
}

int main() {
    int n, m, count = 0;
    char symbol;
    bool arr[102][102]{};
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            std::cin >> symbol;
            if (symbol == '#')
                arr[i][j] = true;
        }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (arr[i][j]) {
                ++count;
                dfs(arr, i, j);
            }
    std::cout << count;
    return 0;
}