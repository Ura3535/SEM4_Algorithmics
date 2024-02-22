#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int arr[100000];
	int n = 0, k = 0;
	std::cin >> n >> k;
	for (int i = 0; i != n; ++i) {
		std::cin >> arr[i];
	}

	std::sort(arr, arr + n);

	if (arr[n - 1] > k) {
		std::cout << "Impossible";
		return 0;
	}

	int left = 0, rigth = n - 1, res = 0;

	while (left < rigth) {
		if (arr[left] + arr[rigth] <= k) {
			++left;
			--rigth;
			++res;
		}
		else {
			--rigth;
			++res;
		}
	}
	if (left == rigth)
		++res;

	std::cout << res;

	return 0;
}