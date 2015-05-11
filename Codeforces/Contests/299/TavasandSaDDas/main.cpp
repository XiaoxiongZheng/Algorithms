#include <iostream>
#include <cmath>

using namespace std;

string n;

int main() {
    cin >> n;
    int len = n.size();
    if (n == "4" || n == "7") {
        cout << (n == "4" ? 1 : 2) << endl;
        return 0;
    }
    int ans = 0, l = len - 1;
    while (l)
    {
        ans += pow(2, l);
        l--;
    }
    int temp = 1;
    for (int i = 0; i < len; i++) {
        if (n[i] == '7') {
            temp += pow(2, len - i - 1);
        }
    }
    cout << ans + temp << endl;
    return 0;
}