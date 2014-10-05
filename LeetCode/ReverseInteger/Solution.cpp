#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int reverse(int x)
	{
		if (x==0) return 0;
		int result = 0, i=0;
		int a[20];
		while(x !=0 )
		{
			a[i] = x%10;
			x = x/10;
			i++;
		}
		i=i-1;
		for(int j=i; j>=0; j--) result += a[j]*pow(10,i-j);
		return result;
	}
}S;
int main()
{
	int x;
	while(cin>>x) cout<<S.reverse(x)<<endl;
	return 0;
}