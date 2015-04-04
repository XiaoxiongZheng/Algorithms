//
//  main.cpp
//  TwoButtons
//
//  Created by zhengxx on 15/3/31.
//  Copyright (c) 2015年 zhengxx. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, m, sum = 0;
    cin >> n >> m;
    int temp = m;
    while(n != temp)
    {
        if (temp < n){
            sum += n - temp;
            break;
        }
        else if (temp % 2)
        {
            temp = (temp + 1) / 2;
            sum++;
        }
        else
            temp /= 2;
        sum++;
    }
    cout << sum << endl;
    return 0;
}
