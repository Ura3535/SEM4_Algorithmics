#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n + 1);
    arr[1] = 1;

    for (int i = 2; i <= n; ++i) {
        arr[i] = INT_MAX;
        for (int j = 1; j < i; ++j)
            arr[i] = std::min(arr[i], arr[j] + arr[i - j]);

        for (int j = 2; j * j <= i; ++j)
            if (i % j == 0)
                arr[i] = std::min(arr[i], arr[j] + arr[i / j]);
    }

    std::cout << arr[n];
}