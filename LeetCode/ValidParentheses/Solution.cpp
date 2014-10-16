#include <iostream>
#include <stack>
#include <map>
using namespace std;

class Solution{
public:
	bool isValid(string s)
	{
		stack<char> left;
		bool result = true;
		map<char, char> m;
		m['('] = ')';
		m['['] = ']';
		m['{'] = '}';
		for(int i = 0; i < s.size(); i++)
		{
			if ( s[i] == '(' || s[i] == '[' || s[i] == '{')
				left.push(s[i]);
			else
			{
				if( !left.empty() && s[i] == m[left.top()])
				{
					left.pop();
					continue;
				}
				else 
				{
					result = false;
					break;
				}
			}
		}
		if (!left.empty())
			result = false;
		return result;
	}
}S;

int main()
{
	string s = "[";
	cout<<S.isValid(s)<<endl;
	system("Pause");
}