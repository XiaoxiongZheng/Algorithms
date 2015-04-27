#include <iostream>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        int b[101][101];
        int a[101][101];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                cin >> b[i][j];
                a[i][j] = 1;
            }


        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (b[i][j] == 0) {
                    for (int k = 1; k <= m; k++)
                        a[i][k] = 0;
                    for (int k = 1; k <= n; k++)
                        a[k][j] = 0;
                }
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            bool flag1 = true;
            for (int j = 1; j <= m; j++) {
                if (b[i][j] == 1) {
                    bool flag2 = false;
                    for (int k = 1; k <= n; k++) {
                        if (a[i][k] || a[k][j]) {
                            flag2 = true;
                            break;
                        }
                    }
                    if (!flag2)
                    {
                        flag1 = false;
                        break;
                    }
                }
            }
            if (!flag1) {
                flag = false;
                break;
            }
        }
        if (!flag)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++)
                    cout << a[i][j] << " ";
                cout << endl;
            }
        }
    }
    return 0;
}