#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	int numDecodings(string s)
	{
		int a[100000] = { 0 };

		if (s.size() == 0)
			return 0;
		if (s.size() == 1 )
			return s[0];
		a[0] = 1;
		if (s[0] > '2' || (s[0] == '2' && s[1] > '6'))
			a[1] = 2;
		else
			a[1] = 3;
		for (int i = 2; i < s.size(); i++)
		{
			if (s[i-1] > '2' ||( s[i-1] == '2' && s[i] > '6'))
				a[i] = a[i - 1] + 1;
			else
			{
				a[i] = a[i - 1] + 2;
			}
		}
		return a[s.size() - 1];
	}
};