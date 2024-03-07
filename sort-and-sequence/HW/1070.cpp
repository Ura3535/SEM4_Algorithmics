#include <iostream>
#include <algorithm>

struct Segment {
    int x, y;
};

int main()
{
    Segment arr[15001];
    int n;
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> arr[i].x >> arr[i].y;
    std::sort(arr, arr + n, [](Segment a, Segment b) { return a.x < b.x; });

    int l = arr[0].x, r = arr[0].y, res = r - l;

    for (int i = 0; i != n; ++i) {
        if (arr[i].x > r) {
            res += arr[i].y - arr[i].x;
            l = arr[i].x;
            r = arr[i].y;
        }
        else if (arr[i].y > r) {
            res += arr[i].y - r;
            r = arr[i].y;
        }
    }
    std::cout << res;
}