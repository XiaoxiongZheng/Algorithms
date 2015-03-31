#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result, path;
		if (s.size() < 4 || s.size() > 12)
			return result;
		for (int i = 1; i <= 3; i++)
			dfs(s, path, result, 0, i);
		
		return result;
	}
private:
	void dfs(string &s, vector<string> path, vector<string> &result, size_t from, size_t len)
	{
		
		//if (path.size() > 4 || (path.size() == 4 && from < s.size()) || from > s.size()) return;
		if (path.size() == 3)
		{
			if (from + len == s.size()){
				string str = s.substr(from, len);
				if (str > "255") return;
				string p = path[0] + ".";
				for (int i = 1; i < 3; i++)
					p += path[i] + ".";
				p += str;
				result.push_back(p);
				return;
			}
			return;
		}
		if (from + len > s.size() || s.substr(from, len) > "255") return;
		path.push_back(s.substr(from, len));
		for (int i = 1; i <= 3; i++)
			dfs(s, path, result, from + len, i);
	}
}S;

int main()
{
	string str = "25525511135";
	S.restoreIpAddresses(str);
}