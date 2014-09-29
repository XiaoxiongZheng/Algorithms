#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		vector<int> result;
		map<int,int> m;
		for (int i=0; i<numbers.size(); i++)
		{
			
			int num = target - numbers[i];
			if (m.count(num) != 0)
			{
				result.push_back(m[num]+1);
				result.push_back(i+1);
			}
			m[numbers.at(i)] = i;
		}
		return result;
		
	}
};
int main()
{
	Solution s;
	int a[]={2,7,11,15};
	vector<int> v(a, a+7);
	vector<int> result(s.twoSum(v, 9));
	for (int i = 0; i < 2; i++)
	{
		cout<<result.at(i)<<endl;
	}
	system("Pause");
	return 0;
}
