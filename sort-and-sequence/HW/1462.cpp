#include <iostream>
#include <algorithm>

int main()
{
    int arr[101];
    int n;

    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> arr[i];

    std::sort(arr, arr + n, [](int a, int b) {return a % 10 < b % 10 || a % 10 == b % 10 && a < b; });

    for (int i = 0; i != n; ++i)
        std::cout << arr[i] << ' ';
}