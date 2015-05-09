#include <iostream>
#include <vector>
using namespace std;

int n, status[26];
string s;

int main() {
    cin >> n >> s;
    memset(status, 0, sizeof(status));
    if (n > s.size())
    {
        cout << "NO" << endl;
        return 0;
    }
    if (n == 1)
    {
        cout << "YES" << endl << s << endl;
        return 0;
    }
    vector<string> vec;
    int prev = 0;
    status[s[0] - 'a'] = 1, n--;

    for (int i = 1; i < s.size(); i++)
    {

        if (status[s[i] - 'a'] == 0){
            status[s[i] - 'a'] = 1;
            if(--n == 0)
            {
                cout << "YES" << endl;
                for (auto s: vec)
                    cout << s << endl;
                cout << s.substr(prev, i - prev) << endl;
                cout << s.substr(i) << endl;
                return 0;
            }
            vec.push_back(s.substr(prev, i - prev));
            prev = i;
        }
    }
    cout << "NO" << endl;
    return 0;
}