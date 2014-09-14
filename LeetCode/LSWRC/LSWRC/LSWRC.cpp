#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

/* Longest Substring Without Repeating Characters */

class Solution
{
public:
	int lengthOfLongestSubstring(string s) {
		list<char> ele;
		int max = 0;
		
		for (int i = 0; i<s.length(); i++)
		{
			bool index = false;
			for (list<char>::iterator iter = ele.begin(); iter!=ele.end(); iter++)
				if (*iter == s[i])
					index = true;
			
			if (!index)
			{
				ele.push_back(s[i]);
				if (ele.size() > max)
					max = ele.size();
				
			}
			if (index)
			{
				list<char>::iterator iter = ele.begin();
				while ( *iter != s[i])
				
					ele.erase(iter++);
					
				ele.erase(iter);
				
				ele.push_back(s[i]);
			}
		}
		return max;
	}

};

int main()
{
	Solution s;
/*	int r = s.lengthOfLongestSubstring("abcabcbb");*/
	int result = s.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");

	cout<<result<<endl;
	system("Pause");
}