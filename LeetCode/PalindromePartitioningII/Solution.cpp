#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int max = INT_MAX;

class Solution
{
public:
	int minCut(string s)
	{
		int n = s.length();
		vector<int> f(n + 1, 0);
		vector<vector<bool> > status(s.length(), vector<bool>(s.length(), false));
		for (int i = 0; i <= n; i++)
			f[i] = n - 1 - i;
		for (int i = n - 1; i >= 0; i--)
			for (int j = i; j < n; j++)
			{
				if (s[i] == s[j] && (j - i < 2 || status[i + 1][j - 1]))
				{
					status[i][j] = true;
					f[i] = min(f[i], f[j + 1] + 1);
				}
			}
		return f[0];
	}
}S;

int main()
{
	string str = "aa";
	S.minCut(str);
}