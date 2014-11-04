#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> result;
		if (n <= 0)
			return result;
		stack<char> status;
		status.push('(');
		string path = "(";
		parentheses(n - 1, status, result, path);
		return result;
	}
	void parentheses(int n, stack<char> status, vector<string> &result, string path)
	{
		if (n == 0 && status.empty()){
			result.push_back(path);
			return;
		}
		else if (n == 0 && !status.empty())
		{
			path.append(")");
			status.pop();
			parentheses(0, status, result, path);
		}
		else if (n != 0 && status.empty())
		{
			path.append("(");
			status.push('(');
			parentheses(n - 1, status, result, path);
		}
		else if (n != 0 && !status.empty())
		{
			string temp = path;
			path.append("(");
			status.push('(');
			parentheses(n-1, status, result, path);
			status.pop();
			temp.append(")");
			status.pop();
			parentheses(n, status, result, temp);
		}
	}
}S;

int main(){
	vector<string> vec;
	vec = S.generateParenthesis(1);
	cout << vec.size() << endl;
	system("Pause");
}