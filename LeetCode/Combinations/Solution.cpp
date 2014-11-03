#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<vector<int> > combine(int n, int k)
	{
		vector<vector<int> > result;
		if (n <= 0 || k <= 0)
			return result;
		vector<int> vec;
		generateCombine(1, n, k, vec, result);
		return result;
	}
	void generateCombine(int start, int end, int k, vector<int> &vec, vector<vector<int> > &result)
	{
		if (k == 0)
			result.push_back(vec);
		else{
			for (int i = start; i <= end - k + 1; i++)
			{
				vector<int> res = vec;
				res.push_back(i);
				generateCombine(i + 1, end, k - 1, res, result);
			}
		}
		
	}
}S;

int main()
{
	vector<vector<int> > vec;
	vec = S.combine(4, 0);
	cout << vec.size() << endl;
	system("Pause");
}