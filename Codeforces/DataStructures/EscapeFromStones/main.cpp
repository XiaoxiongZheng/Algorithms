#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int mx = 1e6+10;
char str[mx];
int ans[mx];

void solve(){
    scanf("%s", str);
    int len = strlen(str), left = 0, right = len-1;
    for (int i = 0; i < len; i++){
        if (str[i] == 'r') ans[left++] = i + 1;
        else ans[right--] = i + 1;
    }
    for (int i = 0; i < len; i++)
        printf("%d\n", ans[i]);
}

int main() {
    solve();
    return 0;
}