#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int n;
string str;
vector<string> ans;
bool isOK;

struct Trie {
    Trie *alpha[26];
    int count;

    Trie() : count(1) {
        for (int i = 0; i < 26; i++)
            alpha[i] = nullptr;
    }
};

string tostring(int x){
    char c[20];
    sprintf(c, "%d", x);
    return string(c);
}

int main() {
    cin >> n;
    Trie t, *p = &t;
    for (int i = 0; i < n; i++) {
        cin >> str;
        isOK = false;
        p = &t;
        for (int j = 0; j < str.size(); j++) {
            if (p->alpha[str[j] - 'a'] == nullptr) {
                p->alpha[str[j] - 'a'] = new Trie();
                isOK = true;
            }
            p = p->alpha[str[j] - 'a'];
        }
        if (isOK || p->count == 1) ans.push_back("OK");
        else ans.push_back(str + tostring(p->count - 1));
        p->count++;
    }
    for (auto s: ans)
        cout << s << endl;
}