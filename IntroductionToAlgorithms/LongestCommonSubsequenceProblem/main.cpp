#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int LCS(const string &s1, const string &s2){
		if (s1.length() == 0 || s2.length() == 0)
			return 0;
		int a[10][10];
		for (int i=1; i<10; i++)
			a[i][0] = 0;
		for (int j=0; j<10; j++)
			a[0][j]=0;
		for (int i=1; i<=s1.length(); i++)
			for (int j=1; j<=s2.length(); j++)
			{
				if (s1[i-1] == s2[j-1])
					a[i][j] = a[i-1][j-1]+1;
				else
				{
					if (a[i-1][j] >= a[i][j-1])
						a[i][j] = a[i-1][j];
					else
						a[i][j] = a[i][j-1];
				}
			}
		return a[s1.length()][s2.length()];
	}
};
int main()
{
	Solution s;
	string s1 = "bcdb", s2 = "abcbdab";
	cout<<s.LCS(s1,s2)<<endl;
	system("Pause");

}