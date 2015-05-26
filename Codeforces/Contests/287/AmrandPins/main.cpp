#include <iostream>
#include <cmath>
using namespace std;

int r, x, y, xe, ye;

int main() {
    cin >> r >> x >> y >> xe >> ye;

    double s = sqrt(pow(x - xe, 2) + pow(y - ye, 2));

    cout << ceil(s / (2 * r)) << endl;

    return 0;
}