#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int mx = 100001;

int main() {
    int n, p;
    while (cin >> n >> p) {
        string str;
        cin >> str;
        int ret = 0;
        vector<int> pos;
        for (int i = 0; i < n / 2; i++)
            if (str[i] != str[n - i - 1]) {
                int temp = abs(str[i] - str[n - i - 1]);
                temp = min(temp, 26 - temp);
                ret += temp;
                pos.push_back(abs(i + 1 - p) < abs(n - i - p) ? i + 1 : n - i);
            }
        if (pos.size() == 0)
        {
            cout << 0 << endl;
            break;
        }
        sort(pos.begin(), pos.end());
        int len = pos.size();
        ret += pos[len - 1] - pos[0] + min(abs(pos[len - 1] - p), abs(pos[0] - p));
        cout << ret << endl;
    }
    return 0;
}