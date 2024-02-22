#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a[100000];
    cin >> n;
    a[1] = 2;
    a[2] = 4;
    a[3] = 7;
    for (int i = 4; i <= n; i++)
        a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % 12345;
    cout << a[n];
}