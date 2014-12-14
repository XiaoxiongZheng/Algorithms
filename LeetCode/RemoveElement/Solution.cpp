#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int removeElement(int A[], int n, int elem)
	{
		if (n == 0)
			return 0;
		int i = 0, j = n - 1;
		while (i < j)
		{
			if (A[j] == elem){
				j--;
				continue;
			}
			if (A[i] != elem){
				i++;
				continue;
			}
			A[i] = A[j];
			A[j] = elem;
			i++;
			j--;
		}
		int length = 0;
		for (; length < n; length++)
			if (A[length] == elem)
				return length;
		return n;
	}
}S;

int main()
{
	int A[] = { 1, 3, 3, 3 };
	S.removeElement(A, 4, 3);
}