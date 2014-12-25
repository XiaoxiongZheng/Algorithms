#include <iostream>
using namespace std;

class Solution {
public:
	bool canJump(int A[], int n)
	{
		int i = 0;
		while (i < n - 1)
		{
			int val = A[i];
			if (val == 0)
				return false;
			int maxvalue = 0;
			int index = 0;
			for (int j = 1; j <= val; j++)
				if (maxvalue < i + j + A[i + j]){
					maxvalue = i + j + A[i + j];
					index = i + j;
				}
			i = index;
		}
		return true;
	}
};