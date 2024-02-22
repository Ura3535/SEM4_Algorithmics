#include <iostream>

int main()
{
    long long n;
    long long arr[31];
    std::cin >> n;
    arr[1] = 2;
    arr[2] = 4;
    for (int i = 3; i <= n; ++i)
        arr[i] = arr[i - 1] + arr[i - 2];
    std::cout << arr[n];
}