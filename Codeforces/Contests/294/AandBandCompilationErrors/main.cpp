#include <iostream>
using namespace std;

long long first, second, third;
int n, cnt = 0, tmp;

int main(){
    cin >> n;
    while (cnt++ < n) {
        cin >> tmp;
        first += tmp;
    }
    cnt = 0;
    while (cnt++ < n - 1) {
        cin >> tmp;
        second += tmp;
    }
    cnt = 0;
    while (cnt++ < n - 2) {
        cin >> tmp;
        third += tmp;
    }

    cout << first - second << endl;
    cout << second - third << endl;
}