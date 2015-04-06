//
//  main.cpp
//  TanyaandPostcard
//
//  Created by zhengxx on 15/4/4.
//  Copyright (c) 2015年 zhengxx. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    while (cin >> s >> t)
    {
        int joys = 0, whoops = 0;
        int low[26] = {0}, upper[26] = {0};
        size_t i = 0;
        while (i < t.size())
        {
            if (t[i] < 'a')
                upper[t[i] - 'A']++;
            else
                low[t[i] - 'a']++;
            i++;
        }
        for (size_t j = 0; j < s.size(); j++)
        {
            if (s[j] < 'a'){
                if (upper[s[j] - 'A'] > 0)
                    joys++;
                upper[s[j] - 'A']--;
            }
            else{
                if (low[s[j] - 'a'] > 0)
                    joys++;
                low[s[j] - 'a']--;
            }
//        }
//        int m = t.size() - joys;
//        for (int k = 0; k < 26; k++)
//        {
//            if (low[k] < 0){
//                m += low[k];
//                whoops -= low[k];
//            }
//            if (upper[k] < 0)
//            {
//                m += upper[k];
//                whoops -= upper[k];
//            }
//        }
//        if (m < 0){
//            joys += m;
//            whoops -= m;
        }
        cout << joys << " " <<s.size() - joys << endl;
    }
    return 0;
}
