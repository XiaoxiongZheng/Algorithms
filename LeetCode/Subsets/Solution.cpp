#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	vector<vector<int> > subsets(vector<int> &S)
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
		return result;
	}
}S;

int main()
{
	int a[] = { 2, 1, 3 };
	vector<int> vec(a, a + 3);
	vector<vector<int> > r = S.subsets(vec);
	for (int i = 0; i < r.size(); i++){
		for (int j = 0; j < r[i].size(); j++)
			cout << r[i][j] << " ";
		cout << endl;
	}
	system("Pause");
}