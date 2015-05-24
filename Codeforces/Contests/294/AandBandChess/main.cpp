#include <iostream>

using namespace std;

int a[256], black = 0, white = 0;
char t;

int main() {
    a['q' - 'a'] = 9, a['r' - 'a'] = 5, a['b' - 'a']  = 3, a['n' - 'a']  = 3, a['p' - 'a']  = 1;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++){
            cin >> t;
            if (t >= 'a' && t <= 'z') black += a[t - 'a'];
            else if (t >= 'A' && t <= 'Z') white += a[t - 'A'];
        }
    if (white > black) cout << "White" << endl;
    else if (white < black) cout << "Black" << endl;
    else cout << "Draw" << endl;

    return 0;
}