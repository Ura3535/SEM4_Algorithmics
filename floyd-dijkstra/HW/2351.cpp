#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using ll = long long;

int dijkstra(const std::vector<std::vector<std::pair<int, ll>>>& arr, int n, int s, int f) {
    std::vector<ll> weight(n + 1);
    std::unordered_set<int> not_processed;
    for (int i = 1; i <= n; ++i)
        not_processed.insert(i);
    std::fill(weight.begin(), weight.end(), -1);
    weight[s] = 0;
    ll curr_v, next_v, edge;

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
    return weight[f];
}


int main() {
    int n, m, s, f;
    ll w;
    std::cin >> n >> s >> f;
    std::vector<std::vector<std::pair<int, ll>>> arr(n + 1);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            std::cin >> w;
            if (i != j && w != -1)
                arr[i].push_back(std::make_pair(j, w));
        }

    std::cout << dijkstra(arr, n, s, f);

    return 0;
}