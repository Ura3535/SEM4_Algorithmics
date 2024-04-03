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
    int n, m, s, f, b, e, w;
    std::cin >> n >> m >> s >> f;
    std::vector<std::vector<std::pair<int, int>>> arr(n + 1);

    for (int i = 0; i != m; ++i) {
        std::cin >> b >> e >> w;
        arr[b].push_back(std::make_pair(e, w));
        arr[e].push_back(std::make_pair(b, w));
    }

    auto weigth = dijkstra(arr, n, s, f);
    if (weigth[f] == -1) {
        std::cout << -1;
        return 0;
    }

    std::stack<int> way;
    int curr_v = f;
    while (curr_v != s)
        for (const auto& x : arr[curr_v])
            if (weigth[x.first] + x.second == weigth[curr_v]) {
                way.push(curr_v);
                curr_v = x.first;
                break;
            }

    way.push(s);
    std::cout << weigth[f] << '\n';
    while (!way.empty()) {
        std::cout << way.top() << ' ';
        way.pop();
    }

    return 0;
}