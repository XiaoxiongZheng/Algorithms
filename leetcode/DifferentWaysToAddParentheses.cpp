//
// Created by zhengxx on 15/8/9.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> _left = diffWaysToCompute(input.substr(0, i));
                vector<int> _right = diffWaysToCompute(input.substr(i + 1));

                for (int j = 0; j < _left.size(); j++)
                    for (int k = 0; k < _right.size(); k++){
                        if (input[i] == '+') ans.push_back(_left[j] + _right[k]);
                        else if (input[i] == '-') ans.push_back(_left[j] - _right[k]);
                        else ans.push_back(_left[j] * _right[k]);
                    }

            }
        }
        if (ans.size() == 0) {
            int num = 0;
            for (int i = 0; i < input.size(); i++) {
                num = num * 10 + (input[i] - '0');
            }
            ans.push_back(num);
        }
        return ans;
    }
};