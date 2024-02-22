#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;

int main()
{
    int n, k;
    std::cin >> n;
    std::vector<int> arr(n + 2);
    for (int i = 1; i <= n; ++i)
        std::cin >> arr[i];
    std::cin >> k;

    for (int i = 1; i <= n + 1; ++i) {
        arr[i] += *std::max_element(arr.begin() + std::max(0, i - k), arr.begin() + i);
    }

    std::cout << arr[n + 1];
}