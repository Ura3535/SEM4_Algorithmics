#include <iostream>
#include <vector>
#include <algorithm>

void dfs(bool* arr, bool adjacency[101][101], int n, int& count, int x) {
    arr[x] = true;
    for (int i = 1; i <= n; ++i) {
        if (adjacency[x][i]) {
            ++count;
            adjacency[x][i] = adjacency[i][x] = false;
            dfs(arr, adjacency, n, count, i);
        }
    }
}


int main() {
    int n, m, u, v, count = 0;
    bool adjacency[101][101]{};
    bool arr[101]{};
    std::cin >> n >> m;

    for (int i = 0; i != m; ++i) {
        std::cin >> u >> v;
        adjacency[u][v] = adjacency[v][u] = true;
    }

    dfs(arr, adjacency, n, count, 1);
    std::cout << (std::all_of(arr + 1, arr + n + 1, [](bool x) {return x; }) ? "YES" : "NO");

    return 0;
}