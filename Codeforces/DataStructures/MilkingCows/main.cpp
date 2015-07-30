#include <iostream>
#include <cstdio>
using namespace std;

const int mx=2e5+10;

int n, a[mx], zero[mx];

long long ans=0L;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = n; i >= 1; i--) {
        zero[i] = zero[i + 1] + 1 - a[i];
    }
    for (int i = 1; i <= n; i++){
        if (a[i])
            ans += zero[i];
    }
    cout << ans << endl;
    return 0;
}