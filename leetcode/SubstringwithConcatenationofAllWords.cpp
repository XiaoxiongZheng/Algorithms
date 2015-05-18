//
// Created by zhengxx on 15/5/18.
//

/**
 * substring with concatenation of all words
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 * time = O(m * n), space = O(n)
 */

#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.size() < words.size() * words[0].size()) return {};
        unordered_map<string, int> um;
        vector<int> ans;
        int len = s.size(), wlen = words.size(), wl = words[0].size();
        for (int i = 0; i < wlen; i++)
            um[words[i]]++;
        for (int i = 0; i < len - wl * wlen + 1; i++){
            unordered_map<string, int> tum(um);
            int j = 0;
            while (j < wlen * wl){
                if (tum[s.substr(i + j, wl)] != 0){
                    tum[s.substr(i + j, wl)]--;
                    j += wl;
                }
                else break;
            }
            if (j == wlen * wl) ans.push_back(i);
        }
        return ans;
    }
};