//
//  main.cpp
//  DNAAlignment
//
//  Created by zhengxx on 15/4/1.
//  Copyright (c) 2015年 zhengxx. All rights reserved.
//

#include <iostream>
using namespace std;

#define mod 1000000007

long long quick_pow(long long m, int n)
{
    long long ans = 1;
    while (n)
    {
        if (n & 1) ans = (ans * m) % mod;
        n = n >> 1;
        m = (m * m) % mod;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int status[4] = {0};
    for (size_t i = 0; i < str.size(); i++){
        if (str[i] == 'A') status[0]++;
        else if (str[i] == 'T') status[1]++;
        else if (str[i] == 'C') status[2]++;
        else if (str[i] == 'G') status[3]++;
    }
    int m;
    m = max(max(status[0], status[1]), max(status[2], status[3]));
    int x = 0;
    for (int i = 0; i < 4; i++)
        if (status[i] == m) x++;
    cout << quick_pow(x, n) << endl;
    return 0;
}
