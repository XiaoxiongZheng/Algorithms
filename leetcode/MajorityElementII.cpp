//
// Created by zhengxx on 15/8/7.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1, n2, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 || n1 == nums[i]) {
                cnt1++;
                n1 = nums[i];
            }
            else if (cnt2 == 0 || n2 == nums[i]) {
                cnt2++;
                n2 = nums[i];
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> candidate, ans;
        if (cnt1 > 0) candidate.push_back(n1);
        if (cnt2 > 0) candidate.push_back(n2);
        for (int i = 0; i < candidate.size(); i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (candidate[i] == nums[j]) count++;
            }
            if (count > nums.size() / 3) ans.push_back(candidate[i]);
        }
        return ans;

    }
};