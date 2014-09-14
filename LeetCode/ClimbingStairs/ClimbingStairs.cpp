#include <iostream>
using namespace std;

class Solution
{
public:
	int climbStairs(int n){
		int *array = new int[n];
		memset(array, 0, n*sizeof(int));
		array[0]=1;
		array[1]=2;
		for (int i=2; i<n; i++)
		{
			array[i]=array[i-1]+array[i-2];
		}
		return array[n-1];
	}
};

int main(void){
	Solution s;
	int result = s.climbStairs(9);
	cout<<result<<endl;
	system("Pause");
}