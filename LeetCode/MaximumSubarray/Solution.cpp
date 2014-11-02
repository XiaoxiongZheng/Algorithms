#include <iostream>
using namespace std;

class Solution
{
public:
	int maxSubArray(int A[], int n)
	{
		if (n == 0)
			return 0;
		int maxResult = INT_MIN;
		int result = 0;
		
		for (int i = 0; i < n; i++)
		{
			if (result < 0)
				result = A[i];
			else
				result += A[i];
			maxResult = maxResult > result ? maxResult : result;
		}
		return maxResult;
	}
}S;

int main()
{
	int a[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << S.maxSubArray(a, sizeof(a) / sizeof(a[0])) << endl;
	system("Pause");
}