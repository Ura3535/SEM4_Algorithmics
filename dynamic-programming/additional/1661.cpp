#include <iostream>
#include <vector>

int main()
{
    int arr[251]{};
    std::vector<std::pair<int, int>> items;
    int s, n, w, v;
    std::cin >> s >> n;
    for (int i = 0; i != n; ++i) {
        std::cin >> w >> v;
        items.push_back(std::make_pair(w, v));
    }
    for (int i = 1; i <= s; ++i) {
        for (const auto& item : items)
            if (item.first <= i && arr[i - item.first] + item.second > arr[i])
                arr[i] = arr[i - item.first] + item.second;
    }

    std::cout << arr[s];
}