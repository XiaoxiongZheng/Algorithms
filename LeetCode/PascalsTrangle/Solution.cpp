#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
	vector<vector<int> > generate(int numRows)
	{
		vector<vector<int> > result;
		if (numRows == 0)
			return result;
		vector<int> vec;
		vec.push_back(1);
		result.push_back(vec);
		if (numRows == 1)
			return result;
		
		for (int i = 1; i < numRows; i++)
		{
			vector<int> temp;
			int count = 1;
			temp.push_back(1);
			while (count < i)
			{
				temp.push_back(result[i - 1][count - 1] + result[i - 1][count]);
				count++;
			}
			temp.push_back(1);
			result.push_back(temp);
		}
		return result;
	}
}S;

int main(){
	S.generate(5);
}