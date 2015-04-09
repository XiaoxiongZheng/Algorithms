#include <iostream>

using namespace std;

const int mx = 100;

int cups[mx];

int main() {
    int n, s;
    while (cin >> n >> s)
    {
        int count = 0;
        while (count < n)
            cin >> cups[count++];
        bool find = false;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                sum += cups[j];
            }
            if (sum <= s) {
                find = true;
                cout << "YES" << endl;
                break;
            }
        }
        if (!find)
            cout << "NO" << endl;
    }
    return 0;
}