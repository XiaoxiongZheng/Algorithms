#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<vector<string> > partition(string s)
	{
		vector<vector<string> > result;
		if (s.length() == 0) return result;
		if (s.length() == 1)
		{
			vector<string> vec;
			vec.push_back(s);
			result.push_back(vec);
			return result;
		}
		vector<string> path;
		dfs(result, 0, path, s);
		return result;
	}
private:
	void dfs(vector<vector<string> > &result, size_t pos, vector<string> &path, string &s)
	{
		if (pos == s.length()) result.push_back(path);
		for (size_t i = pos; i < s.length(); i++)
		{
			string str = s.substr(pos, i - pos + 1);
			if (judgePalindrome(str))
			{
				vector<string> vec(path);
				vec.push_back(str);
				dfs(result, i + 1, vec, s);
			}
		}
	}
	bool judgePalindrome(string &str)
	{
		for (size_t i = 0; i < str.length() / 2; i++)
			if (str[i] != str[str.length() - i - 1])
				return false;
		return true;
	}
}S;

int main()
{
	string str = "aa";
	S.partition(str);
}