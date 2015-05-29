#include <iostream>
#include <algorithm>
using namespace std;

int a[501][501], n, m, q, x, y;
int s[501], mx = INT_MIN, ix;

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        s[i] = INT_MIN;
        int mt = 0;
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                s[i] = max(s[i], mt);
                mt = 0;
            }
            else mt++;
        }
        s[i] = max(s[i], mt);
        if (s[i] > mx) mx = s[i], ix = i;
    }

    while(q--){
        cin >> x >> y;
        a[x][y] = 1 - a[x][y];
        s[x] = INT_MIN;
        int mt = 0;
        for (int i = 1; i <= m; i++) {
            if (a[x][i] == 0) {
                s[x] = max(s[x], mt);
                mt = 0;
            }
            else mt++;
        }
        s[x] = max(s[x], mt);
        if (ix != x){
            if (s[x] > mx) mx = s[x], ix = x;
        }
        else if (s[x] >= mx) mx = s[x];
        else{
            mx = INT_MIN;
            for (int i = 1; i <= n; i++)
                if (s[i] > mx) mx = s[i], ix = i;
        }
        cout << mx << endl;
    }

    return 0;
}