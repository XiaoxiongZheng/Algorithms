//
// Created by zhengxx on 15/8/9.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};