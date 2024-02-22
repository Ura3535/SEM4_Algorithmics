#include <iostream>

using namespace std;

int main()
{
    long long a[10000000], b[1000000], n, q = 0;
    cin >> n;
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    if (n < 3)
    {
        if (n == 0) cout << 0;
        if (n == 1) cout << a[0];
        if (n == 2) { if (a[0] > a[1]) cout << a[0]; else cout << a[1]; }
        cout << endl;
        q = 1;
    }
    b[0] = a[0];
    if (a[1] > a[0])
        b[1] = a[1];
    else b[1] = a[0];
    for (long long i = 2; i < n; i++)
        if (a[i] + b[i - 2] > b[i - 1])
            b[i] = a[i] + b[i - 2];
        else b[i] = b[i - 1];
    if (q == 0)cout << b[n - 1] << endl;
}