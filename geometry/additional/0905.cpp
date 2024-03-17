#include <iostream>
#include <algorithm>

int main() {
    int arr[3];
    std::cin >> arr[0] >> arr[1] >> arr[2];

    std::sort(arr, arr + 3);

    if (arr[0] == arr[1] && arr[0] == arr[2])
        std::cout << 1;
    else if (arr[0] == arr[1] || arr[1] == arr[2])
        std::cout << 2;
    else
        std::cout << 3;

    return 0;
}
