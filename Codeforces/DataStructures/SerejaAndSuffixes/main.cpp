#include <iostream>
#include <string.h>
using namespace std;

const int MX = 1e5 + 10;
int n, m, a[MX], dp[MX], s[MX], temp;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(dp, 0, sizeof(dp));
    dp[n - 1] = 1;
    s[a[n - 1]] = 1;
    for (int i = n - 2; i >= 0; i--){
        if (s[a[i]] == 0) {
            s[a[i]] = 1;
            dp[i] = dp[i + 1] + 1;
        }
        else dp[i] = dp[i + 1];
    }
    for (int i = 0; i < m; i++){
        cin >> temp;
        cout << dp[temp - 1] << endl;
    }
}

int main() {
    solve();
    return 0;
}