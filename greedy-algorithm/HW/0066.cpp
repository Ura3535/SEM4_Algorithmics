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

int parse(std::string str) {
	return
		(str[0] - '0') * 10 * 60 +
		(str[1] - '0') * 60 +
		(str[3] - '0') * 10 +
		(str[4] - '0');
}

int main()
{
	T arr[1000];
	int n = 0;
	std::cin >> n;
	for (int i = 0; i != n; ++i) {
		std::string tmp;
		std::cin >> tmp;
		arr[i].first = parse(tmp);
		std::cin >> tmp;
		arr[i].second = parse(tmp);
	}

	std::sort(arr, arr + n,
		[](T a, T b) {
			return a.first < b.first;
		});

	int last = 0, res = 0;
	for (int i = 0; i != n; ++i) {
		if (arr[i].first >= last) {
			last = arr[i].second;
			++res;
		}
		if (arr[i].second < last)
			last = arr[i].second;
	}

	std::cout << res;

	return 0;
}