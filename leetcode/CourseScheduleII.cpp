//
// Created by zhengxx on 15/8/5.
//
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adjaces(numCourses);
        vector<int> indegrees(numCourses, 0);
        int len = prerequisites.size();
        for (int i = 0; i < len; i++) {
            adjaces[prerequisites[i].second].push_back(prerequisites[i].first);
            indegrees[prerequisites[i].first]++;
        }
        queue<int> zerodegree;
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) zerodegree.push(i);
        }
        while (!zerodegree.empty()) {
            int node = zerodegree.front();
            zerodegree.pop();
            ans.push_back(node);
            for (int i = 0; i < adjaces[node].size(); i++)
                if(--indegrees[adjaces[node][i]] == 0)
                    zerodegree.push(adjaces[node][i]);
        }
        if (ans.size() != numCourses) return {};
        else return ans;
    }
};