#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using ll = long long;

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<ll>> v(n + 2, std::vector<ll>(m + 2, 0)), dp(n + 2, std::vector<ll>(m + 2, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> v[i][j];

    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++)
            dp[i][j] = v[i][j] + std::max(dp[i + 1][j], dp[i][j - 1]);

    int i = 1, j = m;
    std::string ans = "";
    while (true)
    {
        ll left = dp[i][j - 1], down = dp[i + 1][j];
        if (left > down)
            j--, ans += 'R';
        else if (left < down)
            i++, ans += 'F';
        else if (left == down)
        {
            if (j > 1)
                j--, ans += 'R';
            else
                i++, ans += 'F';
        }

        if (i == n && j == 1)
            break;
    }

    std::reverse(ans.begin(), ans.end());
    std::cout << ans;
}