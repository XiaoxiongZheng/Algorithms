#include <iostream>

using namespace std;

int n, m, k, a[100][100], ans;

int min_row(int *r1, int *r2) {
    int c = 0;
    for (int i = 0; i < m; i++)
        if (r1[i] != r2[i])
            c++;
    return min(c, m - c);
}

int min_col(int c1, int c2) {
    int c = 0;
    for (int i = 0; i < n; i++)
        if (a[i][c1] != a[i][c2])
            c++;
    return min(c, n - c);
}

int main() {

    while (cin >> n >> m >> k) {

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        if (n < m)
        {
            for (int i = 0; i <m; i++)
                for (int j = i + 1; j < m; j++)
                    swap(a[i][j], a[j][i]);
            swap(n, m);
        }
        ans = k + 1;
        if (n <= k)
        {
            for (int i = 0; i < (1<<m); i++)
            {
                int sum = 0;
                for (int l = 0; l < n; l++)
                {
                    int temp = 0;
                    for (int j = 0; j < m; j++)
                    {
                        if (i & (1 << j) && !a[l][j])
                            temp++;
                        else if (! (i & (1 << j)) && a[l][j])
                            temp++;
                    }
                    sum += min(temp, m - temp);
                }
                ans = min(ans, sum);
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                int sum = 0;
                for (int j = 0; j < n; j++)
                {
                    int temp = 0;
                    if (i == j) continue;
                    for (int l = 0; l < m; l++)
                        if (a[i][l] != a[j][l]) temp++;
                    sum += min(temp, m - temp);
                }
                ans = min (ans, sum);
            }
        }
        if (ans > k) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}