//
// Created by zhengxx on 15/8/4.
//

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adjaces(numCourses);
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            adjaces[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]++;
        }

        queue<int> zerodegree;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                zerodegree.push(i);

        while (!zerodegree.empty()) {
            int temp = zerodegree.front();
            zerodegree.pop();
            for (int i = 0; i < adjaces[temp].size(); i++)
                if (--indegree[adjaces[temp][i]] == 0)
                    zerodegree.push(adjaces[temp][i]);
        }

        for (int i = 0; i < numCourses; i++)
            if (indegree[i] != 0)
                return false;

        return true;

    }
};