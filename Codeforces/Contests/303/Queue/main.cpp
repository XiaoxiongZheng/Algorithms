#include <iostream>
#include <algorithm>

using namespace std;

const int mx = 100001;

int a[mx], n, cnt = 0, wat = 0, ans = 0;

int main() {
    cin >> n;
    while (cnt < n) cin >> a[cnt++];
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (wat <= a[i]) {
            ans++;
            wat += a[i];
        }
    }
    cout << ans << endl;
    return 0;
}