#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	/*int maxArea(vector<int> &height)
	{
		int length = height.size();
		int maxContainer = 0;
		for(int i=0; i<length; i++)
			for(int j = length - 1; j>i; j--)
			{
				if(height[j] >= height[i])
				{
					int temp = height[i] * (j-i);
					if(temp > maxContainer)
						maxContainer = temp;
				}
				else
				{
					int temp = height[j] * (j-i);
					if(temp > maxContainer)
						maxContainer = temp;
				}
			}
		return maxContainer;
	}*/

	int maxArea(vector<int> &height)
	{
		
		int prior = 0;
		int tail = height.size()-1;
		int maxContainer = 0;

		while(prior != tail)
		{
			if(height[prior] >= height[tail])
			{
				int temp = (tail - prior) * height[tail];
				if (temp > maxContainer)
					maxContainer = temp;
				tail--;
			}
			else
			{
				int temp = (tail - prior) * height[prior];
				if(temp > maxContainer)
					maxContainer = temp;
				prior++;
			}
		}
		return maxContainer;

	}

}S;


/*
class Solution
{
public:
	int maxArea(vector<int> &height)
	{
		int length = height.size();

		int topHeight = 0;
		int topPos = 0;
		for(int i=0; i<length; i++)	{							
			if (topHeight < height[i])
			{
				topPos = i;
				topHeight = height[i]; 
			}
		}
		
		int maxContainer = 0;
		int nowLine = 0;
		for(int i=1; i<=topPos; i++)
		{
			if(height[i] >= height[nowLine])
			{
				int temp = height[nowLine] * (i-nowLine);
				if(temp > maxContainer)
					maxContainer = temp;
				nowLine = i;
			}
		}

		nowLine = length - 1;
		for(int i = length - 1; i >= topPos; i--)
		{
			if(height[i] >= height[nowLine])
			{
				int temp = height[nowLine] * (nowLine-i);
				if(temp > maxContainer)
					maxContainer = temp;
				nowLine = i;
			}
		}

		return maxContainer;
	}
}S;
*/

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(7);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(1);
	cout<<S.maxArea(vec)<<endl;
	system("Pause");
}