//
//  main.cpp
//  second
//
//  Created by zhengxx on 15/4/3.
//  Copyright (c) 2015年 zhengxx. All rights reserved.
//

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    int count;
    cin >> count;
    while (count--) {
        vector<int> initial_vec;
        unordered_map<int, vector<int>> um;
        int n, m;
        while (cin >> n >> m)
        {
            int initial;
            while (m--)
            {
                cin >> initial;
                initial_vec.push_back(initial);
            }
            while (n--)
            {
                int key, num;
                cin >> key >> num;
                while(num--)
                {
                    int value;
                    cin >> value;
                    um[key].push_back(value);
                }
            }
            queue<int> q;
            for (int i = 0; i < um.size(); i++)
            {
                q.push(<#const value_type &__v#>)
            }
        }
    }
    return 0;
}
