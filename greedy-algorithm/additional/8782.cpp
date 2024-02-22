#include <iostream>

int f1(int x) {
	int res = 0;

	for (; (1 << res) < x; ++res);

	return res;
}

int f2(int x) {
	return (1 << x);
}

int main()
{
	int n, q, m = 0;
	int arr[1000]{};
	std::cin >> n >> q;
	for (int i = 0; i != n; ++i) {
		int tmp;
		std::cin >> tmp;
		++arr[f1(tmp)];
		m = std::max(m, f1(tmp));
	}

	for (int i = 0; i != q; ++i) {
		int tmp, res = 0;
		std::cin >> tmp;
		for (int j = m, q = 0; j >= 0 && tmp > 0; ) {
			if (arr[j] == q || f2(j) > tmp) {
				--j;
				q = 0;
				continue;
			}
			int k = std::min(tmp / f2(j), arr[j] - q);
			tmp -= k * f2(j);
			q += k;
			res += k;
		}

		if (tmp != 0)
			res = -1;
		std::cout << res << '\n';
	}

	return 0;
}