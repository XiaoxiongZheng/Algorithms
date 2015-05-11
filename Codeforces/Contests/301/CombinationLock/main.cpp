#include <iostream>
#include <stdlib.h>
using namespace std;

int n;
string str1, str2;

int main() {
    cin >> n >> str1 >> str2;
    int ans = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        int step1 = abs(str1[i] - str2[i]);
        int step2 = abs(10 - step1);
        ans += step1 > step2 ? step2 : step1;
    }
    cout << ans << endl;
    return 0;
}