#include <iostream>
#include <algorithm>

int main() {
    int arr[3];
    std::cin >> arr[0] >> arr[1] >> arr[2];

    std::sort(arr, arr + 3);

    std::cout << (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2] ? "YES" : "NO");

    return 0;
}
