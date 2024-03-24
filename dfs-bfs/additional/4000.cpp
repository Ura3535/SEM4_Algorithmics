#include <iostream>
#include <vector>
#include <algorithm>

int dfs(bool* arr, bool(*adjacency)[101], int n, int x) {
    int res = 1;
    arr[x] = true;
    for (int i = 1; i <= n; ++i) {
        if (adjacency[x][i] && !arr[i]) {
            res += dfs(arr, adjacency, n, i);
        }
    }
    return res;
}


int main() {
    int n, s;
    bool adjacency[101][101]{};
    bool arr[101]{};
    std::cin >> n >> s;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            std::cin >> adjacency[i][j];
        }

    std::cout << dfs(arr, adjacency, n, s);

    return 0;
}