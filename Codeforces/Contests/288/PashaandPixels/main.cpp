#include <iostream>
#include <string.h>
using namespace std;

const int mx = 1001;

bool a[mx][mx];

int n, m, k, i = 0, x, y;
bool ok = false;

int main() {
    cin >> n >> m >> k;
    memset(a, false, sizeof(a));
    while (i < k) {
        cin >> x >> y;
        a[x][y] = true;
        if (a[x-1][y+1] && a[x][y+1] && a[x-1][y]) ok = true;
        if (a[x+1][y+1] && a[x][y+1] && a[x+1][y]) ok = true;
        if (a[x-1][y] && a[x-1][y-1] && a[x][y-1]) ok = true;
        if (a[x][y-1] && a[x+1][y] && a[x+1][y-1]) ok = true;
        if (ok) {
            cout << i + 1 << endl;
            return 0;
        }
        i++;
    }
    cout << 0 << endl;
    return 0;
}