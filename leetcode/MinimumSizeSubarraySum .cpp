//
// Created by zhengxx on 15/8/2.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size(), ans = len + 1, res = 0;
        for(int i = 0, j = 0; i <= len;) {
            if (res >= s && i >= j) {
                ans = min(ans, i - j);
                res -= nums[j];
                j++;
            }
            else if (i < len){
                res += nums[i];
                i++;
            }
            else break;
        }
        if (ans == len + 1) return 0;
        return ans;
    }
};