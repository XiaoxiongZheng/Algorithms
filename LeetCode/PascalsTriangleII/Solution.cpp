#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<int> getRow(int rowIndex)
	{
		vector<int> result;
		//if (rowIndex == 0)
		//	return result;
		result.push_back(1);
		if (rowIndex == 0)
			return result;
		for (int k = 1; k <= rowIndex; k++)
		{
			vector<int> temp(result);
			int count = 1;
			result[0] = 1;
			while (count < k)
			{
				result[count] = temp[count - 1] + temp[count];
				count++;
			}
			result.push_back(1);
		}
		return result;
	}
}S;

int main()
{
	S.getRow(3);

}