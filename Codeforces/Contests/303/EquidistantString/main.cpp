#include <iostream>
#include <string>

using namespace std;

string s, t;

int main() {
    cin >> s >> t;
    int n = s.size(), diff = 0;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i]) diff++;
    if (diff & 1) {
        cout << "impossible" << endl;
        return 0;
    }
    if (diff == 0){
        s[0] = (s[0] == '0')? '1' : '0';
        cout << s << endl;
        return 0;
    }
    diff /= 2;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i]) {
            if (diff) {
                s[i] = t[i];
                diff--;
            }
            else break;
        }
    cout << s << endl;
    return 0;
}