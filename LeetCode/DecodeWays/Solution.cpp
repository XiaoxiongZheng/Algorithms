#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	int numDecodings(string s)
	{
		//vector<int> vec(s.size() + 1, 0);
		int prev = 0, curr = 0;
		for (int i = 1; i <= s.size; i++)
		{
			if (s[i - 1] == '0') curr = 0;
			if (i < 2 || !(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
				prev = 0;
			int temp = curr;
			curr += prev;
			prev = curr;
		}
		return curr;
	}
};