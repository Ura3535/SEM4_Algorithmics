#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i].first;
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i].second;

    std::sort(arr.begin(), arr.end(),
        [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
            return std::min(p1.first, p2.second) < std::min(p2.first, p1.second);
        });

    int result = 0, a = 0;

    for (const auto& x : arr) {
        a += x.first;
        result = std::max(result, a) + x.second;
    }
    std::cout << result;
    return 0;
}