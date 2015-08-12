//
// Created by zhengxx on 15/8/12.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution{
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string> &wordDict) {
        wordDict.insert(beginWord);
        wordDict.insert(endWord);
        queue<string> _queue;
        _queue.push(beginWord);
        int ans = 0;
        while (!_queue.empty()) {
            ans++;
            int num = _queue.size();
            for (int i = 0; i < num; i++) {
                string word = _queue.front();
                _queue.pop();
                if (word == endWord) return ans;
                wordDict.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char temp = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (wordDict.find(word) != wordDict.end()) {
                            _queue.push(word);
                            wordDict.erase(word);
                        }
                    }
                    word[j] = temp;
                }
            }
        }
    }
};