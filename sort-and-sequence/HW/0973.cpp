#include <iostream>
#include <vector>
#include <set>

int f(std::vector<std::set<int>>& tree, std::vector<int>& coins, int i) {
    if (tree[i].empty()) return coins[i];
    std::set<int> arr1, arr2;
    for (int x : tree[i]) {
        arr1.insert(x);
        tree[x].erase(i);
    }
    tree[i].clear();
    for (int x : arr1) {
        for (int x2 : tree[x])
            arr2.insert(x2);
    }

    int sum1 = 0, sum2 = coins[i];
    for (int x : arr1)
        sum1 += f(tree, coins, x);
    for (int x : arr2)
        sum2 += f(tree, coins, x);

    coins[i] = std::max(sum1, sum2);

    return coins[i];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, u, v;
    std::cin >> n;
    std::vector<std::set<int>> tree(n + 1);
    std::vector<int> coins(n + 1);
    for (int i = 0; i != n - 1; ++i) {
        std::cin >> u >> v;
        tree[u].emplace(v);
        tree[v].emplace(u);
    }
    for (int i = 1; i != n + 1; ++i)
        std::cin >> coins[i];

    std::cout << f(tree, coins, 1);
}