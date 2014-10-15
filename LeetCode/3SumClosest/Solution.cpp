#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution{
public:
	int threeSumClosest(vector<int> &num, int target)
	{
		sort(num.begin(), num.end());
		
		int minNum = 30000;
		
		for( int i=0; i < num.size()-2 ; i++ )
		{
			if ( i>=1 && num[i] == num[i-1]) continue;
			
			for( int j = num.size() - 1; j >= 2 ; j-- )
			{
				if ( j < num.size() - 1 && num[j] == num[j + 1] ) continue;

				int temp = target - num[i] - num[j];
				int begin = i+1;
				int end = j-1;

				while(begin != end && begin < end)
				{
					int mid = ( begin + end ) / 2;
					if ( num[mid] < temp )
						begin = mid + 1;
					else if( num[mid] > temp )
						end = mid - 1;
					else
						return target;
				}
				
				int now = temp - num[begin];
				int previous;
				int next;
				if(begin >= i+2)
					previous = temp - num[begin - 1];
				else
					previous = 30001;
				if(begin <= j-2)
					next = temp - num[begin+1];
				else
					next = 30001;
				if(abs(previous) <= abs(now) && abs(previous) <= abs(next))
				{
					if ( abs(minNum) > abs(previous) )
						minNum = previous;
				}
				else if(abs(now) <= abs(previous) && abs(now) <= abs(next))
				{
					if ( abs(minNum) > abs(now) )
						minNum = now;
				}
				else {
					if( abs(minNum) > abs(next) )
						minNum = next;
				}
				
			}
		}
		return target - minNum;
	}
}S;
int main()
{
	int a[] = {-1, 2, 1, -4};
	int target = 1;
	vector<int> vec(a, a+sizeof(a)/sizeof(a[0]));
	cout<<S.threeSumClosest(vec, target)<<endl;
	system("Pause");
	return 0;
}