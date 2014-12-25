#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{

public:
	int largestRectangleArea(vector<int> &height)
	{
		height.push_back(0);
		int length = height.size();
		stack<int> s;
		int maxArea = 0, i=0;
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
	vector<int> vec = { 10,10,10,9,9,9,0,0,0};
	S.largestRectangleArea(vec);
}