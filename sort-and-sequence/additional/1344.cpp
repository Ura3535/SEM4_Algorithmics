#include <iostream>
#include <string>
#include <algorithm>

struct Affairs {
    std::string _class, lname, fname, birth_date;

    bool operator < (Affairs other) {
        int a = _class.size() == 3
            ? _class[0] * 10000 + _class[1] * 100 + _class[2]
            : _class[0] * 100 + _class[1],
            b = other._class.size() == 3
            ? other._class[0] * 10000 + other._class[1] * 100 + other._class[2]
            : other._class[0] * 100 + other._class[1];
        return (a < b || a == b && lname < other.lname);
    }
};

int main()
{
    Affairs arr[1001];
    int n;
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin
        >> arr[i].lname
        >> arr[i].fname
        >> arr[i]._class
        >> arr[i].birth_date;

    std::sort(arr, arr + n);

    for (int i = 0; i != n; ++i)
        std::cout
        << arr[i]._class << ' '
        << arr[i].lname << ' '
        << arr[i].fname << ' '
        << arr[i].birth_date << '\n';
}