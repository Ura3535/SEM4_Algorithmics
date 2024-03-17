#include <iostream>
#include <unordered_map>

int main()
{
    int n, a;
    std::unordered_map<int, int> arr;
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        std::cin >> a;
        ++arr[a];
    }
    a = -1;
    for (const auto& x : arr)
        if (x.second * 2 > n) {
            a = x.first;
            break;
        }
    std::cout << a;
}