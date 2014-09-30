#include <iostream>
#include <algorithm>
using namespace std;


class Solution
{
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		if ( m<=2 || n<=2)
		{
			int* result = new int[m+n];
			for (int i = 0; i < m; i++)
				result[i] = A[i];
			for(int j=m; j<m+n; j++)
				result[j] = B[j-m];
			sort(result, result+m+n);
			if ((m+n)%2 == 0)
				return double((result[(m+n)/2-1]+result[(m+n)/2]))/2;
			else
				return result[(m+n)/2];
		}

		else
		{
			if (A[m/2] <= B[n/2])
			{
				return findMedianSortedArrays(A+m/2, m-m/2, B, n-n/2);
			}
			else
			{
				return findMedianSortedArrays(A, m-m/2, B+n/2, n-n/2);
			}

		}
		
	}
};

int main()
{
	Solution s;
	int A[] = {1};
	int B[] = {5,6,7,8};
	cout<<s.findMedianSortedArrays(A,0,B,4)<<endl;
	system("Pause");
}