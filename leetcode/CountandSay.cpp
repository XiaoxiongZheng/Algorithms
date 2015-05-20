//
// Created by zhengxx on 15/5/20.
//

/**
 * count and say
 * https://leetcode.com/problems/combination-sum/
 * time = O(n), space = O(n)
 */


#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while (--n){
            int cnt = 1;
            string str = "";
            for (int i = 0; i < ans.size() - 1; i++){
                if (ans[i] != ans[i + 1]) {
                    str += to_string(cnt) + ans[i];
                    cnt = 1;
                }
                else cnt++;
            }
            str += to_string(cnt) + ans[ans.size() - 1];
            ans = str;
        }
        return ans;
    }
};