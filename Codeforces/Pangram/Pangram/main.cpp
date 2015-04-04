//
//  main.cpp
//  Pangram
//
//  Created by zhengxx on 15/3/31.
//  Copyright (c) 2015年 zhengxx. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {
    int num;
    cin >> num;
    int status[26] = {0}, total = 26;
    string str;
    cin >> str;
    for (size_t i = 0; i < str.size() && total != 0; i++)
    {
        if (str[i] >= 'a' && status[str[i] - 'a'] == 0)
        {
            status[str[i] - 'a']++;
            total--;
        }
        else if (str[i] < 'a' && status[str[i] - 'A'] == 0)
        {
            status[str[i] - 'A']++;
            total--;
        }
    }
    if (total == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
