#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char a[50][50];
bool s[50][50], ok = false;
int n, m;

const int x[] = {-1, 1, 0, 0}, y[] = {0, 0, -1, 1};

void dfs(int r, int c, int sr, int sc, char curr){
    if (r >= n || r < 0 || c >= m || c < 0 || a[r][c] != curr) return;
    if (s[r][c]){
        ok = true;
        return;
    }
    s[r][c] = true;
    for (int i = 0; i < 4; i++){
        int nx = r + x[i];
        int ny = c + y[i];
        if (nx == sr && ny == sc) continue;

        dfs(nx, ny, r, c, curr);
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    memset(s, false, sizeof(s));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!s[i][j] && !ok) {
                dfs(i, j, -1, -1, a[i][j]);
            }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}