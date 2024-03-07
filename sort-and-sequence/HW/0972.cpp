#include <iostream>
#include <algorithm>

struct Time {
    int h, m, s;
};

int main()
{
    Time arr[101];
    int n;
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> arr[i].h >> arr[i].m >> arr[i].s;
    std::sort(arr, arr + n, [](Time& a, Time& b) {return ((a.h * 60 + a.m) * 60 + a.s) < ((b.h * 60 + b.m) * 60 + b.s); });
    for (int i = 0; i != n; ++i)
        std::cout << arr[i].h << ' ' << arr[i].m << ' ' << arr[i].s << '\n';
}