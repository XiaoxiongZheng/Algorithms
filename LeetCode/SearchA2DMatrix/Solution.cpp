#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target)
	{
		int start1 = 0, end1 = matrix.size() - 1;
		while (start1 <= end1)
		{
			int mid = (start1 + end1) / 2;
			if (matrix[mid][0] == target)
				return true;
			if (matrix[mid][0] < target)
				start1 = mid + 1;
			else
				end1 = mid - 1;
		}
		int start2 = 0, end2 = matrix[0].size() - 1;
		if (end1 == -1) return false;
		while (start2 <= end2)
		{ 
			int mid = (start2 + end2) / 2;
			if (matrix[end1][mid] == target)
				return true;
			if (matrix[end1][mid] < target)
				start2 = mid + 1;
			else
				end2 = mid - 1;
		}
		return false;
	}
}S;

int main(){
	vector<int> vec1 = { 1, 3, 5, 7 };
	vector<int> vec2 = { 10, 11, 16, 20 };
	vector<int> vec3 = { 23, 30, 34, 50 };
	vector<vector<int> > vec;
	vec.push_back(vec1);
	vec.push_back(vec2);
	vec.push_back(vec3);
	cout<<S.searchMatrix(vec, 11);
	system("Pause");
 }