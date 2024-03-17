#include <iostream>
#include <algorithm>

int main() {
    double arr[4];
    std::cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];

    std::sort(arr, arr + 4);

    std::cout << (arr[0] == arr[1] && arr[2] == arr[3] ? "YES" : "NO");

    return 0;
}
