#include <iostream>
#include <vector>
#include <climits>

int main()
{
    const int MAX = 1000001;
    std::vector<int> arr(MAX);
    std::fill(arr.begin(), arr.end(), INT_MAX);
    arr[1] = 0;
    int n;
    for (int i = 1; i < MAX; ++i) {
        if (i + 1 < MAX && arr[i] < arr[i + 1])
            arr[i + 1] = arr[i] + 1;
        if (i * 2 < MAX && arr[i] < arr[i * 2])
            arr[i * 2] = arr[i] + 1;
        if (i * 3 < MAX && arr[i] < arr[i * 3])
            arr[i * 3] = arr[i] + 1;
    }
    while (std::cin >> n) {
        std::cout << arr[n] << '\n';
    }
}