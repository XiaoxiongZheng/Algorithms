#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	void iter(vector<vector<int> > &matrix, vector<int> &result, int rStart, int rEnd, int cStart, int cEnd)
	{

		if (rStart > rEnd || cStart > cEnd)
			return;
		if (rStart == rEnd && cStart == cEnd)
		{
			result.push_back(matrix[rStart][cStart]);
			return;
		}
		if (rStart == rEnd)
		{
			for (int i = cStart; i <= cEnd; i++)
				result.push_back(matrix[rStart][i]);
			return;
		}
		if (cStart == cEnd)
		{
			for (int i = rStart; i <= rEnd; i++)
				result.push_back(matrix[i][cStart]);
			return;
		}
		for (int i = cStart; i <= cEnd; i++)
			result.push_back(matrix[rStart][i]);
		for (int i = rStart + 1; i <= rEnd; i++)
			result.push_back(matrix[i][cEnd]);
		for (int i = cEnd - 1; i >= cStart; i--)
			result.push_back(matrix[rEnd][i]);
		for (int i = rEnd - 1; i > rStart; i--)
			result.push_back(matrix[i][cStart]);
		iter(matrix, result, rStart + 1, rEnd - 1, cStart + 1, cEnd - 1);

	}

	vector<int> spiralOrder(vector<vector<int> > &matrix)
	{
		vector<int> result;
		if (matrix.size() == 0) return result;
		if (matrix.size() == 1) return matrix[0];
		iter(matrix, result, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
		return result;
	}
}S;

int main()
{
	vector<int> vec1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> vec2 = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	vector<vector<int> > m;
	m.push_back(vec1);
	m.push_back(vec2);
	S.spiralOrder(m);


}