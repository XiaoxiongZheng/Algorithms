#include <iostream>
#include <math.h>
using namespace std;

const int MX = 5e5+ 10;
int a[MX], n;
long long cnt[MX];

void solve(){
    cin >> n;
    long long s = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    if (s % 3 != 0) cout << 0 << endl;
    else{
        s /= 3;
        long long ss = 0;
        for (int i = n - 1; i >= 0; i--){
            ss += a[i];
            if (ss == s)
                cnt[i] = 1;
        }
        for (int i = n-2; i >= 0; i--)
            cnt[i] += cnt[i+1];
        long long ans = 0;
        ss = 0;
        for (int i = 0; i+2 < n; i++){
            ss += a[i];
            if (ss == s)
                ans += cnt[i+2];
        }
        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}