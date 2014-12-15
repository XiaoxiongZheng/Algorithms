#include <iostream>
using namespace std;

class Solution{
public:
	int removeDuplicates(int A[], int n)
	{
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		int j = 1;
		for (int i = 1; i < n; i++)
		{
			if (A[i] == A[i - 1])
				continue;
			A[j] = A[i];
			j++;
		}
		return j;
	}
}S;

int main()
{
	int A[] = {1, 1, 1, 2};
	S.removeDuplicates(A, 4);
}