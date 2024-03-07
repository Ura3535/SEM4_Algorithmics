#include <iostream>
#include <algorithm>

int main()
{
    int arr[10001];
    long long n, res = 1;
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> arr[i];

    std::sort(arr, arr + n);

    for (int i = 0; i != n; ++i) {
        if (res < arr[i]) break;
        res += arr[i];
    }

    std::cout << res;
}