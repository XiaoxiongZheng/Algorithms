#include <iostream>
using namespace std;

class Solution {
public:
	int jump(int A[], int n)
	{
		int i = 0;
		int count = 0;
		while (i < n - 1)
		{
			int val = A[i];
			if (val + i >= n - 1)
				return count + 1;
			int maxvalue = 0;
			int index = 0;
			for (int j = 0; j <= val; j++)
				if (maxvalue < i + j + A[i + j]){
					maxvalue = i + j + A[i + j];
					index = i + j;
				}
			i = index;
			count++;
		}
		return count;
	}
};