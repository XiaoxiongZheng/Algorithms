#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S)
	{
		vector<vector<int> > result;
		if (S.size() == 0)
			return result;
		vector<int> empty;
		result.push_back(empty);
		sort(S.begin(), S.end());
		for (int i = 0; i < S.size(); i++)
		{
			int currentNum = result.size();
			for (int j = 0; j < currentNum; j++)
			{
				vector<int> vec(result[j]);
				vec.push_back(S[i]);
				result.push_back(vec);
			}
		}
		set<vector<int> > temp;
		for (int i = 0; i < result.size(); i++)
			temp.insert(result[i]);
		vector<vector<int> > vec;
		for (set<vector<int> >::iterator iter = temp.begin(); iter != temp.end(); iter++)
			vec.push_back(*iter);
		return vec;
	}
}S;

int main()
{
	vector<int> vec = { 0 };
	S.subsetsWithDup(vec);
}