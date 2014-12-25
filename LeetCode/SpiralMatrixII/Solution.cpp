#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int> > generateMatrix(int n)
	{
		if (n == 0)
			return{};
		vector<vector<int> > result;
		for (int i = 0; i < n; i++)
		{
			vector<int> temp;
			for (int j = 0; j < n; j++)
				temp.push_back(0);
			result.push_back(temp);
		}
		int count = 1;
		iter(result, 0, n - 1, 0, n - 1, count);
		return result;
	}
	void iter(vector<vector<int> > &result, int rStart, int rEnd, int cStart, int cEnd, int count)
	{
		if (rStart > rEnd || cStart > cEnd)
			return;
		if (rStart == rEnd && cStart == cEnd)
		{
			result[rStart][rEnd] = count;
			return;
		}
		for (int i = cStart; i <= cEnd; i++, count++)
			result[rStart][i] = count;
		for (int i = rStart + 1; i <= rEnd; i++, count++)
			result[i][cEnd] = count;
		for (int i = cEnd - 1; i >= cStart; i--, count++)
			result[rEnd][i] = count;
		for (int i = rEnd - 1; i > rStart; i--, count++)
			result[i][cStart] = count;
		iter(result, rStart + 1, rEnd - 1, cStart + 1, cEnd - 1, count);
	}

}S;

int main()
{
	S.generateMatrix(3);
}