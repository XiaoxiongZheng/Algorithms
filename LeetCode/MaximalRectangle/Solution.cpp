#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
	int maximalRectangle(vector<vector<char> > &matrix)
	{
		int row = matrix.size(); 
		if (row == 0)
			return 0;
		int col = matrix[0].size();
		vector<int> result;
		for (int i = 0; i < col; i++)
			result.push_back(0);
		int maxArea = 0;
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++)
			{
				if (matrix[i][j] == '1')
					result[j] += 1;
				else
					result[j] = 0;
			}
			int area = largestRectangleArea(result);
			maxArea = maxArea > area ? maxArea : area;
		}
		return maxArea;
	}
private:
	int largestRectangleArea(vector<int> &height)
	{
		height.push_back(0);
		int length = height.size();
		stack<int> s;
		int maxArea = 0, i = 0;
		while (i < length)
		{
			if (s.empty() || height[i] >= height[s.top()])
				s.push(i++);
			else
			{
				int t = s.top();
				s.pop();
				int area = height[t] * (s.empty() ? i : i - s.top() - 1);
				if (area > maxArea)
					maxArea = area;
			}
		}
		return maxArea;
	}
}S;

int main()
{
	vector<vector<char> > matrix;
	vector<char> vec = { '0' };
	matrix.push_back(vec);
	S.maximalRectangle(matrix);
}