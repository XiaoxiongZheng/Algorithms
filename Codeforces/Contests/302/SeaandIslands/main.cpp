#include <iostream>

using namespace std;

int n, k;
int main() {
    cin >> n >> k;
    int t = n * n;
    if ((t % 2 && k > (t/2 + 1) )|| (t % 2 == 0 && k > t/2))
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (k != 0 && ((i % 2 == 0 && j % 2 == 0) || (i % 2 && j % 2))) {
                cout << "L";
                k--;
            } else
                cout << "S";
        }
        cout << endl;
    }
    return 0;
}