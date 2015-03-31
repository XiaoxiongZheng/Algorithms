#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		if (s1.size() + s2.size() != s3.size())
			return false;
		vector<vector<bool> > status(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		//status[0][0] = true;
		for (int i = 1; i <= s1.size(); i++)
			status[i][0] = status[i - 1][0] && s1[i - 1] == s3[i - 1];
		for (int j = 1; j <= s2.size(); j++)
			status[0][j] = status[0][j - 1] && s2[j - 1] == s3[j - 1];

		for (int i = 1; i <= s1.size(); i++)
			for (int j = 1; j <= s2.size(); j++)
			{
				status[i][j] = (s1[i - 1] == s3[i + j - 1] && status[i - 1][j]) ||
					(s2[j - 1] == s3[i + j - 1] && status[i - 1][j]);
			}
		return status[s1.size()][s2.size()];
	}
};