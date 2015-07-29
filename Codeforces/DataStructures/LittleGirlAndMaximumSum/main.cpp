#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>

using namespace std;

const int mx=2e5+10;

int n, q, a[mx], t[mx], li, ri;
long long ans=0;

void solve() {
    memset(t, 0, sizeof(t));
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    while (q--) {
        scanf("%d%d", &li, &ri);
        t[li]++;
        if (ri < n)
            t[ri+1]--;
    }
    for (int i = 1; i <= n; i++)
        t[i]+=t[i-1];
    sort(a + 1, a+n+1);
    sort(t + 1, t+n+1);
    for (int i = 1; i <= n; i++)
        ans += (long long)a[i] * t[i];
    cout << ans <<endl;
}

int main() {
    solve();
    return 0;
}