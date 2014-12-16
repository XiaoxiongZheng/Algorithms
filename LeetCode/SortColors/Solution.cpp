#include <iostream>
using namespace std;

class Solution{
public:
	void sortColors(int A[], int n)
	{
		int i = 0, j = 0, k = n - 1;
		while (j <= k)
		{
			if (A[j] == 0)
			{
				swap(A[i], A[j]);
				while (A[i] == 0)
					i++;
				if (j < i)
					j = i;
			}
			else if (A[j] == 1) {
				j++;
			}
			else 
			{
				swap(A[k], A[j]);
				while (A[k] == 2)
					k--;
			}
		}
	}
}S;

int main(){
	int A[] = { 0, 1, 2, 0, 1, 2, 1, 0, 1, 2, 0};
	S.sortColors(A, 11);
	system("Pause");
}