#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>

struct Knigth {
	int power;
	int money;
	int id;
	long long res;
};

int main()
{
	int n, k;
	std::vector<Knigth> arr;
	std::priority_queue<int, std::vector<int>, std::greater<int>> moneys;
	std::cin >> n >> k;
	arr.resize(n);
	for (int i = 0; i != n; ++i) {
		std::cin >> arr[i].power;
		arr[i].id = i;
	}
	for (int i = 0; i != n; ++i)
		std::cin >> arr[i].money;

	std::sort(arr.begin(), arr.end(),
		[](Knigth& a, Knigth& b) {
			return a.power < b.power;
		});

	long long res = 0;

	for (int i = 0; i != n; ++i) {
		if (moneys.size() > k) {
			res -= moneys.top();
			moneys.pop();
		}

		arr[i].res = res + arr[i].money;
		res += arr[i].money;
		moneys.push(arr[i].money);
	}

	std::sort(arr.begin(), arr.end(),
		[](Knigth& a, Knigth& b) {
			return a.id < b.id;
		});

	for (int i = 0; i != n; ++i)
		std::cout << arr[i].res << ' ';

	return 0;
}