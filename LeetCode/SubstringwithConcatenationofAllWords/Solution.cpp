#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class Solution
{
public:
	vector<int> findSubstring(string S, vector<string> &L)
	{
		vector<int> result;
		if (S.size() == 0 || L.size() == 0)
			return result;
		size_t step = L[0].size();
		if (S.size() < step * L.size())
			return result;
		size_t i = 0;
		unordered_map<string, int> pos;
		for (string str : L)
		{
			if (pos.find(str) != pos.end())
				pos[str]++;
			else pos[str] = 1;
		}
		while (i <= S.size() - L.size() * step)
		{
			unordered_map<string, int> temp = pos;
			int j = 0;
			for (; j < L.size(); j++)
			{
				string str = S.substr(i + j*step, step);
				if (temp.find(str) == temp.end())
					break;
				else if (--temp[str] < 0)
						break;
			}
			if (j == L.size()) result.push_back(i);
			i++;
		}
		return result;
	}
}S;

int main()
{
	string s = "barfoo";
	string l_1 = "foo";
	string l_2 = "bar";
	vector<string> vec;
	vec.push_back(l_1);
	vec.push_back(l_2);
	S.findSubstring(s, vec);
}