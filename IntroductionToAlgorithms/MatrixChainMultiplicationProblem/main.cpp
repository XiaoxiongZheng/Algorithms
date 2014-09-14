#include <iostream>
using namespace std;

class Solution
{
public:
	/*int sqrt1(int x){
		int initial = 2;
		int temp = 0;
		while (true)
		{
			
			temp = initial/2 + x/(2*initial);
			if (abs(x-temp*temp)<2)
				return temp;
			else
			{
				initial = temp;
				continue;
			}
			
		}
	}*/

	int sqrt1(int x){
		long long left = 0;
		long long right = x;

		while (left<right)
		{
			long long mid = left + (right-left)/2;
			if (mid*mid<=x && (mid+1)*(mid+1)>x)
			{
				return mid;
			}
			else if(mid*mid<x)
			{
				 left = mid+1;
			}
			else
			{
				 right = mid-1;
			}
		}
	}

};
int main(){
	Solution s;
	int result = s.sqrt1(14);
	cout<<result<<endl;
	system("Pause");
}