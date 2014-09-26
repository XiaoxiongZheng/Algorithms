#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
	int maxProduct(int A[], int n) {
		int result = A[0];
		int minNum = A[0];
		int maxNum = A[0];
		for (int i=1; i<n; i++)
		{
			int a = min(minNum*A[i], maxNum*A[i]);
			int b = max(minNum*A[i], maxNum*A[i]);
			int minTemp = min(a, A[i]);
			int maxTemp = max(b, A[i]);
			minNum = minTemp;
			maxNum = maxTemp;
			result = max(result, maxNum);
		}
		return result;
	}
};

int main(){
	int A[] = {2,3,-2,4};
	Solution s;
	cout<<s.maxProduct(A,4)<<endl;
	system("Pause");
}