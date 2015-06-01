#include <iostream>
#include <algorithm>
using namespace std;

double p1, t1, p2, t2;

int main() {
    cin >> p1 >> p2 >> t1 >> t2;

    double m1 = max(3 * p1 / 10, p1 - p1 * t1 / 250);
    double m2 = max(3 * p2 / 10, p2 - p2 * t2 / 250);

    if (m1 > m2) cout << "Misha" << endl;
    else if (m1 < m2) cout << "Vasya" << endl;
    else cout << "Tie" << endl;
    return 0;
}