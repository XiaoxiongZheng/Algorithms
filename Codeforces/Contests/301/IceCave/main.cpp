#include <iostream>
#include <string>
#include "stdio.h"
using namespace std;

int n, m, xs, ys, xt, yt;
char a[505][505];
bool vis[505][505];
bool ok;

int xx[4] = {0, 0, 1, -1}, yy[4] = {1, -1, 0, 0};
void dfs(int x, int y)
{
    if (x > n || y > m || x < 1 || y < 1) return;
    if (a[x][y] == 'X' && (x != xt || y != yt)) return;
    if (!vis[x][y]) vis[x][y] = 1;
    else return;
    for (int k = 0; k < 4; k++)
        dfs(x + xx[k], y + yy[k]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    cin >> xs >> ys >> xt >> yt;
    ok = false;
    a[xs - 1][ys - 1] = '.';
    dfs(xs, ys);
    if (!vis[xt][yt]){cout << "NO" << endl; return 0;}
    int t = 0;
    for (int i = 0; i < 4; i++)
        if (a[xt + xx[i]][yt + yy[i]] == '.')
            t++;
    if (xs == xt && ys == yt)
    {
        if (t == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
        return 0;
    }
    if (a[xt][yt] != 'X' && t == 1) {cout << "NO" << endl; return 0;}
    cout << "YES" << endl;
    return 0;
}