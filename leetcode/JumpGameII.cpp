//
// Created by zhengxx on 15/5/22.
//

#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size(), right = nums[0], count = 1;
        for (int i = 0; i < len;){
            if (right >= len - 1) return count;
            int temp = right;
            while (i <= temp){
                right = max(right, i + nums[i]);
                i++;
            }
            count++;
        }
        return count;
    }
};
