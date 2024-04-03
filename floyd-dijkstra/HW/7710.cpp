#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <stack>

std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, int>>>& arr, int n, int s, int f) {
    std::vector<int> weight(n + 1);
    std::unordered_set<int> not_processed;
    for (int i = 1; i <= n; ++i)
        not_processed.insert(i);
    std::fill(weight.begin(), weight.end(), -1);
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
    return weight;
}


int main() {
    int n, m, k, a, b, c;
    std::cin >> n >> m >> k;
    std::vector<std::vector<std::pair<int, int>>> arr(n + 1);

    for (int i = 0; i != k; ++i)
        std::cin >> a;
    for (int i = 0; i != m; ++i) {
        std::cin >> a >> b >> c;
        arr[a].push_back(std::make_pair(b, c));
        arr[b].push_back(std::make_pair(a, c));
    }

    auto weigth = dijkstra(arr, n, 1, n);

    int curr_v = n;
    while (curr_v != 1)
        if (std::count_if(arr[curr_v].begin(), arr[curr_v].end(),
            [&](auto x) { return weigth[x.first] + x.second == weigth[curr_v]; }
        ) > 1) {
            std::cout << "yes";
            return 0;
        }
        else
            curr_v = std::find_if(arr[curr_v].begin(), arr[curr_v].end(),
                [&](auto x) { return weigth[x.first] + x.second == weigth[curr_v]; }
    )->first;

    std::cout << "no";

    return 0;
}