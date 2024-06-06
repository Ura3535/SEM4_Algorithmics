#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <stack>

int max_way(const std::vector<std::vector<std::pair<int, int>>>& arr, int n, int s) {
    std::vector<int> weight(n, -1);
    std::unordered_set<int> not_processed;
    for (int i = 0; i != n; ++i)
        not_processed.insert(i);
    weight[s] = 0;
    int curr_v, next_v, edge;

    while (!not_processed.empty()) {
        curr_v = *std::min_element(not_processed.begin(), not_processed.end(), [&](int l, int r)
            { return weight[l] != -1 && (weight[r] == -1 || weight[l] < weight[r]); });
        if (weight[curr_v] == -1)
            break;
        not_processed.erase(curr_v);
        for (const auto& x : arr[curr_v]) {
            next_v = x.first;
            edge = x.second;
            if (weight[next_v] == -1 || weight[curr_v] + edge < weight[next_v])
                weight[next_v] = weight[curr_v] + edge;
        }
    }

    return *std::max_element(weight.begin(), weight.end());
}


int main() {
    int n, m, u, v;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> arr(n);

    for (int i = 0; i != m; ++i) {
        std::cin >> u >> v;
        --u, --v;
        arr[u].push_back(std::make_pair(v, 0));
        arr[v].push_back(std::make_pair(u, 1));
    }

    int res = 0;
    for (int i = 0; i != n; ++i)
        res = std::max(res, max_way(arr, n, i));

    std::cout << res;

    return 0;
}