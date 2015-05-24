#include <iostream>

using namespace std;

const int mx = 101;
int a[mx][mx], n, cnt = 0;
bool s[mx];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1 || a[i][j] == 3) {
                s[i] = true;
                break;
            }
        }
        if (!s[i]) cnt++;
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
        if (!s[i]) cout << i << " ";
    return 0;
}