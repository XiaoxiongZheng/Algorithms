#include <iostream>
#include <algorithm>
using namespace std;

int n, k, p, x, y, median, a[1000], b[1000];

int main() {
    cin >> n >> k >> p >> x >> y;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        x -= a[i];
    }
    for (int i = k + 1; i <= n; i++)
    {
        x -= 1;
        a[i] = 1;
    }
    if (x < 0)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = k + 1; i <= n; i++)
    {
        int temp = min(x, y - 1);
        x -= temp;
        a[i] += temp;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] >= y)
            ans++;
    if (ans >= (n/2) + 1)
    {
        for (int i = k + 1; i <= n; i++)
            cout << a[i] << " ";
        return 0;
    }
    cout << -1 << endl;
    return 0;
}