#include <iostream>
#include <string.h>
using namespace std;

const int MX = 2e+5 + 10;
int n, t, c, a[MX], cnt = 0;


void solve(){
    cin >> n >> t >> c;
    memset(a, 0, sizeof(a));
    int val = c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= t && val == 1)
            cnt++;
        else if (a[i] <= t)
            val--;
        else
            val = c;
    }
    cout << cnt << endl;
}

int main() {
    solve();
    return 0;
}