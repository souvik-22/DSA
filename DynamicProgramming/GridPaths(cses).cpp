//https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    if (a[0][0] == '*' || a[n - 1][n - 1] == '*')
    {
        cout << "0";
        return;
    }
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = 1;

    for (int i = 1; i < n; ++i)
    {
        dp[i][0] = (a[i][0] == '.' && dp[i - 1][0] == 1) ? 1 : 0;
    }

    for (int i = 1; i < n; ++i)
    {
        dp[0][i] = (a[0][i] == '.' && dp[0][i - 1] == 1) ? 1 : 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] == '.')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
            else
                dp[i][j] = 0;
        }
    }
    cout << dp[n - 1][n - 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}