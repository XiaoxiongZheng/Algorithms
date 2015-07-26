//
// Created by zhengxx on 15/7/26.
//

#include <iostream>
using namespace std;


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long tmp = m, cnt = 0, ans = 0xFFFFFFFF, bin = 1;
        while (tmp) {
            tmp >>= 1;
            cnt++;
        }
        bin <<= cnt;
        if (n >= bin) return 0;
        for (long i = m; i <= n; i++)
            ans &= i;
        return ans;
    }
};