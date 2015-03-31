#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
	string simplifyPath(string path)
	{
		if (path.size() == 0) return "";
		if (path.size() == 1) return "/";

		stack<string> s;
		for (int i = 0; i < path.size(); i++)
		{
			if (path[i])
			
		}
	}
};