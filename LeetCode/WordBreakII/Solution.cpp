#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution{
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict)
	{
		vector<bool> status(s.size() + 1, false);
		vector<vector<bool> > path(s.size() + 1, vector<bool>(s.size() + 1, false));
		status[0] = true;
		for (int i = 1; i <= s.size(); i++)
			for (int j = i - 1; j >= 0; j--)
			{
				if (status[j] && dict.find(s.substr(j, i - j)) != dict.end())
				{
					status[i] = true;
					path[i][j] = true;
				}
			}
		if (!status[s.size()]) return vector<string>();
		vector<string> vec;
		dfs(path, s.size(), vec, "", s);
		return vec;
	}
private:
	void dfs(vector<vector<bool> > &path, size_t pos, vector<string> &vec, string p, string &s)
	{
		if (pos == 0)
		{
			vec.push_back(p);
			return;
		}
		for (int i = 0; i < pos; i++)
		{
			if (path[pos][i])
			{
				if (p == "") 
					dfs(path, i, vec, s.substr(i, pos - i), s);
				else
					dfs(path, i, vec, s.substr(i, pos - i) + " " + p, s);

			}
		}
	}
}S;

int main()
{
	string str = "catsanddog";
	unordered_set<string> dict = { "cat", "cats", "and", "sand", "dog" };
	vector<string> vec = S.wordBreak(str, dict);
	system("Pause");
}