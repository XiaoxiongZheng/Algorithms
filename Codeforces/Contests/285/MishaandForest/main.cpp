#include <iostream>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;

const int mx = 2e5+10;

int ans[mx], l[mx], r[mx], a[mx];
stack<int> stk;
int n, tmp = 0;

int main() {
    cin >> n;
    fill(r, r + n + 1, n);
    memset(l, -1, sizeof(l));
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++){
        while(!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
        if (!stk.empty()) l[i] = stk.top();
        stk.push(i);
    }

    while (!stk.empty()) stk.pop();
    for (int i = n - 1; i >= 0; i--){
        while (!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
        if (!stk.empty()) r[i] = stk.top();
        stk.push(i);
    }

    for (int i = 0; i < n; i++){
        int len = r[i] - l[i] - 1;
        ans[len] = max(ans[len], a[i]);
    }

    for (int i = n ; i > 0; i--) ans[i] = max(ans[i], ans[i + 1]);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}