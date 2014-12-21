#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target)
	{
		int start1 = 0, end1 = matrix[0].size() - 1;
		while (start1 <= end1)
		{
			int mid = (start1 + end1) / 2;
			if (matrix[mid][0] == target)
				return true;
			if (matrix[mid][0] > target)
				start1 = mid + 1;
			else
				end1 = mid - 1;
		}
		int start2 = 0, end2 = matrix[0].size() - 1;
		while (start2 <= end2)
		{ 
			int mid = (start2 + end2) / 2;
			if (matrix[start1][mid] == target)
				return true;
			if (matrix[start1][mid] > target)
				start2 = mid + 1;
			else
				end2 = mid - 1;
		}
		return false;
	}
};