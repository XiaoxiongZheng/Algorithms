#include <iostream>

using namespace std;

const int mx = 4e3 + 1;

int n, a, b, c, dp[mx];

int main() {
    cin >> n >> a >> b >> c;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        if ((i - a == 0) || (i - a > 0 && dp[i - a] != 0))
            dp[i] = max(dp[i - a] + 1, dp[i]);
        if ((i - b == 0) || (i - b > 0 && dp[i - b] != 0))
            dp[i] = max(dp[i - b] + 1, dp[i]);
        if ((i - c == 0) || (i - c > 0 && dp[i - c] != 0))
            dp[i] = max(dp[i - c] + 1, dp[i]);
    }
    cout << dp[n] << endl;
    return 0;
}