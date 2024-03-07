#include <iostream>
#include <algorithm>

int main()
{
    int arr[1001];
    int n;
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> arr[i];

    std::sort(arr, arr + n);

    for (int i = 0; i != n; ++i)
        std::cout << arr[i] << ' ';
}