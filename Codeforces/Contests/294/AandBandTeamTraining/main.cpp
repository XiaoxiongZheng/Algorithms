#include <iostream>

using namespace std;

int n, m;

int solve(int x, int y)
{
    if (x > y) return solve(y, x);
    if (y >= 2 * x) return x;
    else return y - x + (2 * x - y) * 2 / 3;
}

int main() {
    cin >> n >> m;
    cout << solve(n, m);
    return 0;
}