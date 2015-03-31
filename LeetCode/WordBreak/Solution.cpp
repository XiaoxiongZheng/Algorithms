#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	bool wordBreak(string s, unordered_set<string> &dict)
	{
		vector<bool> status(s.size() + 1, false);
		status[0] = true;
		for (int i = 1; i <= s.size(); i++)
			for (int j = i - 1; j >= 0; j--)
			{
				if (status[j] && dict.find(s.substr(j, i - j)) != dict.end())
				{
					status[i] = true;
					break;
				}
			}
		return status[s.size()];
	}
};