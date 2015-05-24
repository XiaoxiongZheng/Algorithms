#include <iostream>
#include <string>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        if (i & 1){
            string tmp(m, '#');
            cout << tmp << endl;
        }
        else{
            string tmp(m, '.');
            if (i % 4 == 0) tmp[0] = '#';
            else tmp[m - 1] = '#';
            cout << tmp << endl;
        }
    }

    return 0;
}