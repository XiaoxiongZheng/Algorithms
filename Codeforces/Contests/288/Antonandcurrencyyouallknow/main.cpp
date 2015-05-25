#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    cin >> str;
    int len = str.size();
    for (int i = 0; i < len - 1; i++){
        if ((str[i] - '0') % 2 == 0 && str[i] < str[len - 1]) {
            swap(str[i], str[len - 1]);
            cout << str << endl;
            return 0;
        }
    }
    for (int i = len - 2; i >= 0; i--){
        if ((str[i] - '0') % 2 == 0){
            swap(str[i], str[len - 1]);
            cout << str << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}