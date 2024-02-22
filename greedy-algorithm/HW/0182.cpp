#include <iostream>
#include <vector>
#include <algorithm>

struct T {
	T() = default;
	T(const T& other) = default;

	T operator=(const T& other) {
		first = other.first;
		second = other.second;
		return *this;
	}

	int first;
	int second;
};

int main()
{
	T arr[10000];
	int n = 0, g = 0, h = 0;
	std::cin >> n >> g >> h;
	for (int i = 0; i != n; ++i) {
		std::cin >> arr[i].first >> arr[i].second;
	}

	if (g + h > n) {
		std::cout << -1;
		return 0;
	}

	std::sort(arr, arr + n,
		[](T a, T b) {
			return a.first - a.second > b.first - b.second;
		});

	int res = 0;
	for (int i = 0; i != g; ++i)
		res += arr[i].first;
	for (int i = g; i != n - h; ++i)
		res += std::max(arr[i].first, arr[i].second);
	for (int i = n - h; i != n; ++i)
		res += arr[i].second;

	std::cout << res;
	return 0;
}