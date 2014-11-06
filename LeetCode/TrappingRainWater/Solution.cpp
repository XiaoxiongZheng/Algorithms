#include <iostream>
#include <map>
using namespace std;

class Solution{
public:
	int trap(int A[], int n){
		if (n == 0 || n == 1 || n == 2)
			return 0;
		map<int, int> left;
		map<int, int> right;

		int maxValue = -1;
		int maxPos = -1;
		for (int i = 0; i < n; i++)
			if (maxValue < A[i])
			{
				maxValue = A[i];
				maxPos = i;
			}
		
		int leftMax = A[0];
		left.insert(pair<int, int>(0, A[0]));
		for (int i = 0; i < maxPos; i++)
		{
			if (A[i] > leftMax){
				left.insert(pair<int, int>(i, A[i]));
				leftMax = A[i];
			}
		}
		int rightMax = A[n - 1];
		right.insert(pair<int, int>(n - 1, A[n - 1]));
		for (int i = n - 1; i > maxPos; i--)
			if (A[i] > rightMax)
			{
				right.insert(pair<int, int>(i, A[i]));
				rightMax = A[i];
			}

		int leftArea = 0;
		map<int, int>::iterator p = left.begin();
		p++;
		map<int, int>::iterator pre = left.begin();

		for (; p != left.end(); p++, pre++)
			leftArea += (p->first - pre->first)*(pre->second);
		leftArea += (maxPos - pre->first) * (pre->second);
		p = right.begin();
		p++;
		pre = right.begin();
		int rightArea = 0;
		for (; p != right.end(); p++, pre++)
			rightArea += (p->first - pre->first)*(p->second);
		pre = right.begin();
		rightArea += (pre->first - maxPos) * (pre->second);
		int entityArea = 0;
		for (int i = 0; i < n; i++)
			entityArea += A[i];

		return leftArea + rightArea + maxValue - entityArea;
	}
}S;

int main()
{
	int A[] = { 4,2,3 };
	int result = S.trap(A, sizeof(A) / sizeof(A[0]));
	cout << result << endl;
	system("Pause");
}