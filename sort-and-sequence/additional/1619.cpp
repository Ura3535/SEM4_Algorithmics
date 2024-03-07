#include <iostream>

int main()
{
    int arr[1000001];
    long long res[1000001];
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    res[0] = arr[0];
    res[1] = std::max(arr[0], arr[1]);
    for (int i = 2; i < n; ++i)
        res[i] = std::max(arr[i] + res[i - 2], res[i - 1]);
    std::cout << res[n - 1];
}