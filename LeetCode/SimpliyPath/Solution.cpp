#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
	string simplifyPath(string path)
	{
		stack<string> s;
		size_t i = 1;
		string result = "";
		while (i < path.size())
		{
			string str = "";
			while (i < path.size() && path[i] != '/')
				str += path[i++];
			if (str == ".." && !s.empty())
				s.pop();
			else if (str != "." && str != "" && str != "..")
				s.push(str);
			i++;
		}
		if (s.empty()) result = "/";
		while (!s.empty())
		{
			result = "/" + s.top() + result;
			s.pop();
		}
		return result;
	}
}S;

int main()
{
	string path = "/.";
	S.simplifyPath(path);
}