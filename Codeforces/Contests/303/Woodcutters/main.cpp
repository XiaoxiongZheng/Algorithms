#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

const int mx = 100001;
int n, cnt = 0, ans = 0, b = INT_MIN;
pair<int, int> p[mx];

int main() {
    cin >> n;
    while (cnt < n) {
        cin >> p[cnt].first >> p[cnt].second;
        cnt++;
    }
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        if (p[i].first - p[i].second > b) {
            ans++;
            b = p[i].first;
        }
        else if (i == n - 1 || p[i].first + p[i].second < p[i + 1].first)
        {
            ans++;
            b = p[i].first + p[i].second;
        }
        else
            b = p[i].first;
    }
    cout << ans << endl;
    return 0;
}