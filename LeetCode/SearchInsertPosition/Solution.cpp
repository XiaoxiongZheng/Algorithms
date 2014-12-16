#include <iostream>
#include <windows.h>
using namespace std;

class Solution{
public:
	int searchInsert(int A[], int n, int target)
	{
		if (target > A[n - 1]) return n;
		if (target < A[0]) return 0;
		int start = 0, end = n-1;
		while (start < end)
		{
			int mid = (start + end) / 2;
			if (target == A[mid])
				return mid;
			if (target > A[mid])
			{
				start = mid + 1;
				continue;
			}
			else{
				end = mid - 1;
				continue;
			}
		}
		if (start == end)
		{
			if (target > A[start]) return start + 1;
			else return start ;
		}
	}
}S;

int main(){
	int A[] = { 1, 3, 5, 6 };
	cout<<S.searchInsert(A, 4, 7)<<endl;
	system("Pause");
}