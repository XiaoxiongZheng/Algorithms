#include <iostream>
#include <vector>
#include <string>
using namespace std;

string num[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution{
public:
	void dfs(int step, const string &digits, vector<string>& result, string &path)
	{
		if (step == digits.size())
		{
			result.push_back(path);
			return;
		}
		for(int i=0; i<num[digits[step] - '0'].size(); i++)
		{
			path.push_back(num[digits[step] - '0'][i]);
			dfs(step+1, digits, result, path);
			path.pop_back();
		}
	}

	vector<string> letterCombinations(string digits)
	{
		vector<string> result;
		int step = 0;
		string path = "";
		dfs(step, digits, result, path);
		return result;
	}
}S;

int main()
{
	string digits = "4";
	vector<string> vec = S.letterCombinations(digits);
	system("Pause");
}