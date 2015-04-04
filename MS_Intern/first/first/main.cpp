//
//  main.cpp
//  first
//
//  Created by zhengxx on 15/4/3.
//  Copyright (c) 2015年 zhengxx. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int x, y, z;
    while (cin >> x >> y >> z)
    {
        int value[3] = {0};
        value[0] = x;
        value[1] = y;
        value[2] = z;
        sort(value, value+3);
        string str;
        cin >> str;
        int a[3] = {0};
        int max_value = -1;
        int count = 0;
        for (int i = 0; i < str.size(); i++)
        {
            int status[3] = {0};
            count++;
            if (str[i] == 'R') a[0]++;
            else if (str[i] == 'B') a[1]++;
            else a[2]++;
            status[0] = abs(a[0] - a[1]);
            status[1] = abs(a[1] - a[2]);
            status[2] = abs(a[0] - a[2]);
            sort(status, status+3);
            bool flag = true;
            for (int j = 0; j < 3; j++)
                if (value[j] != status[j])
                {
                    flag = false;
                    break;
                }
            max_value = max(max_value, count);
            if (flag)
            {
                for (int j = 0; j < 3; j++)
                    a[j] = 0;
                count = 0;
            }
        }
        cout << max_value << endl;
    }
    return 0;
}
