#include <iostream>
#include <vector>
#include <unordered_set>

void dfs(std::vector<bool>& arr, std::vector<std::unordered_set<int>>& adjacency, int x) {
    arr[x] = true;
    auto x_adjacency = adjacency[x];

    for (int i : x_adjacency)
        if (!adjacency[x].contains(i))
            continue;
        else if (arr[i]) {
            adjacency[x].erase(i);
            adjacency[i].erase(x);
        }
        else {
            adjacency[i].erase(x);
            dfs(arr, adjacency, i);
        }

    arr[x] = false;
}


int main() {
    int n, m, u, v;
    std::cin >> n >> m;
    std::vector<bool> arr(n + 1);
    std::vector<std::unordered_set<int>> adjacency(n + 1);

    for (int i = 0; i != m; ++i) {
        std::cin >> u >> v;
        adjacency[u].insert(v);
        adjacency[v].insert(u);
    }

    dfs(arr, adjacency, 1);

    for (int i = 1; i <= n; ++i)
        for (int j : adjacency[i])
            std::cout << i << ' ' << j << '\n';

    return 0;
}