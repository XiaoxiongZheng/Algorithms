#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 101;

int n, m;
int b[MX] = {0}, g[MX] = {0}, dp[MX][MX] = {0};

int solve()
{
    sort(b, b + n + 1);
    sort(g, g + m + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <=m; j++)
        {
            if (abs(b[i] - g[j]) > 1)
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
            else
                dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));
        }
    return dp[n][m];
}

int main() {
    cin >> n;
    for (int i = 1; i <=n; i++)
        cin >> b[i];
    cin >> m;
    for (int j = 1; j <= m; j++)
        cin >> g[j];
    cout << solve() << endl;
    return 0;
}