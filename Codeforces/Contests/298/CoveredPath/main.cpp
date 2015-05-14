#include <iostream>
#include <algorithm>
using namespace std;

int v1, v2, t, d;

int main() {
    cin >> v1 >> v2 >> t >> d;
    int sum = 0;
    for (int i = 0; i < t; i++)
        sum += min(v1 + i * d, v2 + (t - i - 1) * d);
    cout << sum << endl;
    return 0;
}