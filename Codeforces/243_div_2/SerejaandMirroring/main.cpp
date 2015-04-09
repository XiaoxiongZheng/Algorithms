#include <iostream>
using namespace std;

string a[1000];
int n, m, i, k, p;

int main()
{
    cin >> n >> m;
    bool p = true;
    for (i = 0; i <= n; i++)
        getline(cin, a[i]);
    while (n % 2 == 0)
    {
        k = n;
        for (i = 1; i <= n / 2; i++)
            if (a[i] == a[k]) k--;
            else
            {
                p = false;
                break;
            }
        if (!p) break;
        n = n / 2;
    }
    cout << n << endl;
}