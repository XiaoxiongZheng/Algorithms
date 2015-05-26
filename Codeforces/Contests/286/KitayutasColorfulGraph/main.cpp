#include <iostream>
using namespace std;

const int mx = 200;

int n, m, q;

int fa[mx][mx];

void init(){
    for (int i = 0; i < 200; i++)
        for (int j = 0; j < 200; j++)
            fa[i][j] = j;
}

int find(int c, int x){
    if (fa[c][x] == x) return x;
    return fa[c][x] = find(c, fa[c][x]);
}

void Union(int c, int a, int b){
    a = find(c, a);
    b = find(c, b);

    if (a == b) return;
    fa[c][a] = fa[c][b];
}

int main(){
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Union(c, a, b);
    }
    cin >> q;
    while (q--){
        int u, v;
        cin >> u >> v;
        int temp = 0;
        for (int i = 1; i <= m; i++){
            int a = find(i, u);
            int b = find(i, v);
            if (a == b) temp++;
        }
        cout << temp << endl;
    }
}
