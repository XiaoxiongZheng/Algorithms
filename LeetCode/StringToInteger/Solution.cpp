#include <iostream>
#include <string>
using namespace std;


class Solution{
public:
	int atoi(const char *str)
	{
		long long result = 0;
		int i = 0, a[20];
		bool isPositive = true;
		while( isspace(*str) ) str++;
		if(*str == '-') 
		{
			isPositive = false;
			str++;
		}
		else if(*str == '+')
			str++;
		
		while(*str >= '0' && *str <= '9')
		{
			result = result*10 + *str - 48;
			i++;
			str++;
		}
		if(!isPositive)
			 result *= -1;
		if(result >= INT_MAX) return INT_MAX;
		if(result <= INT_MIN) return INT_MIN;
		return result;
	}
}S;

int main()
{
	string str;
	cout<<S.atoi("2147483648")<<endl;
	system("Pause");

}