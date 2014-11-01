#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	int minimumTotal(vector<vector<int> > &triangle)
	{
		if (triangle.size() == 0)
			return 0;
		if (triangle.size() == 1)
			return triangle[0][0];
		int row = triangle.size();
		vector<int> val;
		for (int i = 0; i < triangle.size(); i++){
			val.push_back(0);
			int temp = val[0];
			val[0] = temp + triangle[i][0];
			for (int j = 1; j < triangle[i].size() - 1; j++)
			{
				int t = val[j];
				val[j] = min(temp, val[j]) + triangle[i][j];
				temp = t;
			}
			val[triangle[i].size() - 1] = temp + triangle[i][triangle[i].size() - 1];
		}

		int minVal = INT_MAX;
		for (int i = 0; i < val.size(); i++)
			minVal = min(minVal, val[i]);
		return minVal;
	}
}S;

int main()
{
	int a1[] = {2};
	int a2[] = {3,4};
	int a3[] = {6,5,7};
	int a4[] = {4,1,8,3};
	vector<int> v1(a1, a1 + 1);
	vector<int> v2(a2, a2 + 2);
	vector<int> v3(a3, a3 + 3);
	vector<int> v4(a4, a4 + 4);

	vector<vector<int> > vec;
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);

	cout << S.minimumTotal(vec) << endl;
	system("Pause");
}