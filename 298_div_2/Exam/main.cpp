#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n)
    {
        int a[5001];
        int i;
        if (n == 1)
        {
            cout << 1 << endl;
            cout << 1 << endl;
            continue;
        }
        if (n == 2)
        {
            cout << 1 << endl;
            cout << 1 << endl;
            continue;
        }
        if (n == 3)
        {
            cout << 2 << endl;
            cout << 1 <<" " << 3 << endl;
            continue;
        }
        if (n == 4)
        {
            cout << 4 << endl;
            cout << 3 <<" " << 1 << " " << 4 << " " << 2 << endl;
            continue;
        }
        cout << n << endl;
        if (n % 2)
        {
            for (int i = 1; i <= n; i+=2)
                cout << i << " ";
            for (int i = 2; i <= n - 1; i+=2)
                cout << i << " ";
            cout << endl;
        }
        else
        {
            for (int i = 1; i <= n - 1; i+=2)
                cout << i << " ";
            for (int i = 2; i <= n; i+=2)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}