#include <iostream>

struct Station {
	int x;
	int y;
	int key;
};

bool transition(Station a, Station b) {
	return std::abs(a.x - b.x) <= 1
		&& std::abs(a.y - b.y) <= 1;
}

void mark_land(Station* arr, int n, const Station& x) {
	for (int i = 0; i != n; ++i)
		if (arr[i].key == -1 && transition(arr[i], x)) {
			arr[i].key = x.key;
			mark_land(arr, n, arr[i]);
		}

	return;
}


int main()
{
	Station arr[100];
	int n = 0, keys = 0;
	std::cin >> n;

	for (int i = 0; i != n; ++i) {
		std::cin >> arr[i].x >> arr[i].y;
		arr[i].key = -1;
	}

	for (int i = 0; i != n - 1; ++i)
		if (arr[i].key == -1) {
			arr[i].key = keys;
			++keys;
			mark_land(arr, n, arr[i]);
		}

	std::cout << keys;

	return 0;
}