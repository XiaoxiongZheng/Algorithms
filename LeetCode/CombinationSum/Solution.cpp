#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution{
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int targets)
	{
		vector<vector<int> > result;
		if (candidates.size() == 0 || targets == 0)
			return result;
		vector<int> vec;
		sort(candidates.begin(), candidates.end());
		findElement(candidates, targets, 0, vec, result);
		return result;
	}
	void findElement(vector<int> &candidates, int targets, int start, vector<int> &vec, vector<vector<int> > &result)
	{
		
		for (int i = start; i < candidates.size(); i++)
		{
			if (candidates[i] == targets)
			{
				vector<int> res = vec;
				res.push_back(candidates[i]);
				result.push_back(res);
			}
			else if (candidates[i] > targets)
				continue;
			else {
				vector<int> res = vec;
				res.push_back(candidates[i]);
				findElement(candidates, targets - candidates[i], i+1, res, result);
			}
		}
	}
}S;

int main()
{
	int a[] = {1,1,1,2};
	int targets = 2;
	vector<int> vec(a, a + 4);
	vector<vector<int> > result = S.combinationSum(vec, targets);
	cout << result.size() << endl;
	system("Pause");
}