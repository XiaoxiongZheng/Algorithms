#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	string convert(string s, int nRows)
	{
		if (nRows == 1)
			return s;
		vector< vector<char> > arr;
		for(int i=0; i<nRows; i++)
		{
			vector<char> c;
			arr.push_back(c);
		}
		int i = 0, j = 0;

		while(1)
		{
			while(i<s.size() &&j < nRows)
			{
				arr[j].push_back(s[i]);
				i++;
				j++;
			}
			if( i == s.size() )
				break;
			j = j-2;
			while(i < s.size() && j >= 0)
			{
				arr[j].push_back(s[i]);
				i++;
				j--;
			}
			if( i == s.size() )
				break;
			j=j+2;
		}

		string result="";
		for (int i=0; i<nRows; i++)
			for(int j=0; j<arr[i].size(); j++)
				result+=arr[i][j];
		
		return result;
	}
}S;
int main()
{
	string s = "AB";
	cout<<S.convert(s,1)<<endl;
	system("Pause");
}