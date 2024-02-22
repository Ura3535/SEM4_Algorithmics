#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n, c, d, h;
    bool q = true;
    cin >> n;
    cin >> c >> d;
    h = max(c, d);
    for (int i = 1; i < n; i++)
    {
        cin >> c >> d;
        if (min(c, d) > h)q = false;
        if (max(c, d) <= h)h = max(c, d); else
            if (min(c, d) <= h)h = min(c, d);
    }
    if (q)cout << "YES";
    else cout << "NO";
}