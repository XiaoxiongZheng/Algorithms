#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
	void merge(int A[], int m, int B[], int n)
	{
		for (int i = 0; i < n; i++)
			A[m] = B[i];
		sort(A, A + m + n);
	}
};