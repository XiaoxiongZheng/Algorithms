#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int findMin(vector<int> &num)
	{
		int start = 0, end = num.size() - 1;
		if (num[start] < num[end])
			return num[start];
		//int end = rail;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (num[mid] == num[end])
				return num[mid];
			if (num[mid] > num[end])
			{
				start = mid;
				continue;
			}
			if (num[mid] < num[end])
			{
				end = mid;
				continue;
			}
		}
	}
}S;

int main(){
	vector<int> vec = { 2, 1 };
	int result = S.findMin(vec);
	system("Pause");
}