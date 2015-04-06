//
//  main.cpp
//  VitalyandStrings
//
//  Created by zhengxx on 15/4/4.
//  Copyright (c) 2015年 zhengxx. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    while(cin >> s >> t)
    {
        size_t i = 0;
        while (i < s.size()){
            if (t[i] < s[i])
            {
                cout << "No such string" << endl;
                break;
            }
            else if (t[i] == s[i])
                i++;
            else
            {
                if (t[i] - s[i] == 1 && i + 1 == s.size())
                {
                    cout << "No such string" << endl;
                    break;
                }
                else if (t[i] - s[i] == 1)
                {
                    i++;
                    while (i < s.size() && s[i] == 'z' && t[i] == 'a')
                        i++;
                    if (i == s.size())
                    {
                        cout << "No such string" << endl;
                        break;
                    }
                    else{
                        if (s[i] != 'z'){
                            s[i] += 1;
                            cout << s << endl;
                        }
                        else
                        {
                            t[i] -= 1;
                            cout << t << endl;
                        }
                        break;
                    }
                }
                else
                {
                    s[i] += 1;
                    cout << s << endl;
                    break;
                }
            }
        }
    }
    
    return 0;
}
