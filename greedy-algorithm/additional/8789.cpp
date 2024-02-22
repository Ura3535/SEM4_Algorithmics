#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n, a, sum = 0, maxi = 0, mini = 1000009;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum = sum - 1;
        mini = min(mini, a);
        maxi = max(maxi, a);
    }
    sum += maxi - mini + 1;
    cout << sum;
}