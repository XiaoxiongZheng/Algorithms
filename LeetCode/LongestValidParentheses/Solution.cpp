#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		vector<int> status(s.size(), 0);
		int ret = 0;
		for (int i = s.size() - 2; i >= 0; --i)
		{
			int match = i + status[i + 1] + 1;
			if (s[i] == '(' && match < s.size() && s[match] == ')')
			{
				status[i] = status[i + 1] + 2;
				if (match + 1 < s.size()) status[i] += status[match + 1];
			}
			ret = max(ret, status[i]);
		}
		return ret;
	}
}S;

int main()
{
	string str = "()(()";
	S.longestValidParentheses(str);
}