#include <iostream>
#include <vector>

int main() {
    int n, k, j;
    std::cin >> n >> k;
    std::vector<int> arr;
    for (int i = 1; i != n + 1; ++i)
        arr.push_back(i);
    j = n - 1;
    while (arr.size() != 1) {
        j = (j + k) % arr.size();
        arr.erase(arr.begin() + j);
        if (j == 0) j = arr.size();
        --j;
    }
    std::cout << arr[0];
}