#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, gi, gj;
    while (cin >> n >> gi >> gj)
    {
        set<pair<double, double>> us;
        int vertical = 0, horizontal = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x == gi && y == gj)
                continue;
            if (x == gi)
                us.insert(make_pair(INT_MAX, 0));
            else {
                double k = double(gj - y) / (gi - x);
                double b = y - x * k;
                us.insert(make_pair(k, b));
            }
        }
        long long sum = us.size();
        cout << max(1LL, sum) << endl;
    }
    return 0;
}