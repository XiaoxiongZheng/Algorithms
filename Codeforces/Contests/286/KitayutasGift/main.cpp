#include <iostream>
#include <string>
using namespace std;

bool judge(const string &str){
    for (int i = 0; i < str.size()/2; i++){
        if (str[i] != str[str.size() - i - 1])
            return false;
    }
    return true;
}

string s;
int main() {
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len / 2; i++){
        if (s[i] != s[len - i - 1]){
            if (judge(s.substr(i, len - i - 1 - i)))
                s.insert(i, 1, s[len - i - 1]);
            else if (judge(s.substr(i + 1, len - i - 1 - i)))
                s.insert(len - i, 1, s[i]);
            else
                s = "NA";
            cout << s << endl;
            return 0;
        }
    }
    if (len % 2 == 0) s.insert(len / 2, 1, 'a');
    else s.insert(len / 2, 1, s[len / 2]);
    cout << s << endl;
    return 0;
}