#include <iostream>
#include <string>
using namespace std;

string s;
int k;

bool judge(const string &str){
    for (int i = 0; i < str.size() / 2; i++){
        if (str[i] != str[str.size() - i - 1])
            return false;
    }
    return true;
}

int main() {
    cin >> s >> k;
    int len = s.size();
    if (len % k != 0) {
        cout << "NO" << endl;
        return 0;
    }
    int step = len / k;
    for (int i = 0; i < len; i+=step){
        if (!judge(s.substr(i, step))){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}