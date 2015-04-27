#include <iostream>

using namespace std;

int main() {
    int v1, v2;
    while (cin >> v1 >> v2)
    {
        int t, d;
        cin >> t >> d;
        if (d == 0){
            cout << v1 * t << endl;
            continue;
        }
        int sum = 0;
        while (v1 <= v2) {
            sum += v1;
            v1 += d;
            t--;
        }
        int t1 = (t - 1) / 2, dif = v1 - v2;
        sum += v1;
        while (t1--)
        {
            v1 += d;
            sum += v1;
        }
        v1  = v1 - dif;
        sum += v1;
        int t2 = (t - 1) / 2;
        while (t2--)
        {
            v1 -= d;
            sum += v1;
        }
        cout << sum << endl;
    }
    return 0;
}