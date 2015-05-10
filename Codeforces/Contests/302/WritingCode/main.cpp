#include <iostream>
#include "string.h"
using namespace std;

const int mx = 501;

int n, m, b, mod, dp[mx][mx],a[mx];

int main() {
    cin >> n >> m >> b >> mod;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = a[i]; k <= b; k++)
                dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i]]) % mod;

    int ans = 0;
    for (int i = 0; i <= b; i++)
        ans =(ans + dp[m][i]) % mod;
    cout << ans << endl;
    return 0;
}