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

	long first;
	long second;
};

int main()
{
	T arr[1000000];
	long n = 0;
	std::cin >> n;
	for (long i = 0; i != 2 * n; ++i) {
		std::cin >> arr[i].first >> arr[i].second;
	}

	std::sort(arr, arr + 2 * n,
		[](T a, T b) {
			return a.first - a.second > b.first - b.second;
		});

	long res = 0;
	for (long i = 0; i != n; ++i)
		res += arr[i].first;
	for (long i = n; i != 2 * n; ++i)
		res += arr[i].second;

	std::cout << res;
	return 0;
}