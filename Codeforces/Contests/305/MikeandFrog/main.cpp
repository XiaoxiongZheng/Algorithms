#include <iostream>

using namespace std;

typedef long long ll;

ll mmod(ll a, ll b, ll m) {
    a %= m;
    b %= m;
    ll ret = 0;
    while (b) {
        if (b & 1) {
            ret += a;
            if (ret >= m) ret -= m;
        }
        a = a << 1;
        if (a >= m) a -= m;
        b = b >> 1;
    }
    return ret;
}

ll m;

ll h1, a1, x1, y1, h2, a2, x2, y2;

int main() {
    cin >> m;
    cin >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
    ll cnt = 0;
    int r = 10 * m + 10, ans = -1;
    for (int i = 1; i <= r; i++) {
        h1 = (mmod(x1, h1, m) + y1) % m;
        h2 = (mmod(x2, h2, m) + y2) % m;
        if (h1 == a1 && h2 == a2) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}