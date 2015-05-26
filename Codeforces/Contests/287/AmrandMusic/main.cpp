#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> p[101];

int n, k, tmp = 0, cnt = 0;

int main() {
    cin >> n >> k;
    while(tmp < n){
        cin >> p[tmp].first;
        p[tmp].second = tmp + 1;
        tmp++;
    }

    sort(p, p + n);
    for (int i = 0; i < n; i++){
        if (k >= p[i].first) {
            cnt++;
            k -= p[i].first;
        }
        else break;
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
        cout << p[i].second << " ";
    return 0;
}