#include <iostream>

using namespace std;

const int mx = 1e5 + 1;

int main() {
    int n;
    while (cin >> n)
    {
        long long c_nam[mx] = {0}, dp[mx] = {0};
        int max_val = INT_MIN;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            max_val = max(max_val, temp);
            c_nam[temp]++;
        }
        dp[0] = 0;
        for (int i = 1; i <= max_val; i++)
        {
            dp[i] = dp[max(i - 2, 0)] + c_nam[i] * i;
            if (dp[i - 1] > dp[i]) dp[i] = dp[i - 1];
        }
        cout << dp[max_val] << endl;
    }
    return 0;
}