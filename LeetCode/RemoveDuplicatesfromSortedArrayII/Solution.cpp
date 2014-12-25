#include <iostream>
using namespace std;

class Solution{
public:
	int removeDuplicates(int A[], int n)
	{
		if (n == 0 || n == 1)
			return n;
		bool duplicate = false;
		int count = 1, j = 1;
		for (int i = 1; i < n; i++)
		{
			if (A[i] != A[i - 1]){
				count++;
				duplicate = false;
				A[j] = A[i];
				j++;
			}
			else if(!duplicate)
			{
				duplicate = true;
				count++;
				A[j] = A[i];
				j++;
			}
		}
		return count;
	}
};