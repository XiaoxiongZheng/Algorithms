#include <iostream>
#include <string>
#include <utility>

using namespace std;

pair<string, string> pr[1000];

int n, tmp = 0, cnt = 0;

string str1, str2;

int main() {
    cin >> n;
    while (tmp++ < n) {
        cin >> str1 >> str2;
        int i = 0;
        for (; i < cnt; i++) {
            if (pr[i].first == str1) {
                pr[i].first = str2;
                break;
            }
        }
        if (i == cnt) {
            pr[cnt].first = str2;
            pr[cnt].second = str1;
            cnt++;
        }

    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
        cout << pr[i].second << " " << pr[i].first << endl;

    return 0;
}