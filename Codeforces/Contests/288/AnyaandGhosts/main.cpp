#include <iostream>

using namespace std;

const int mx = 301;

int m, t, r, a[mx], c[mx], ans;

int main() {
    cin >> m >> t >> r;
    for (int i = 0; i < m; i++) cin >> a[i];

    if (r > t ){
        cout << -1 << endl;
        return 0;
    }

    for (int i = r, tmp = 0; i >= 1; i--, tmp++)
        c[i] = t - tmp;

    ans = r;

    for(int i = 1; i < m; i++){
        int tm = a[i] - a[i - 1], tmp = 0;
        for (int i = r; i >= 1; i--){
            if (c[i] - tm <= 0) {
                c[i] = t - tmp;
                ans++;
                tmp++;
            }
            else c[i] -= tm;

        }
    }
    cout << ans << endl;
    return 0;
}