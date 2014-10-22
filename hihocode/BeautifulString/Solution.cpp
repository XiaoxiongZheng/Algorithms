#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{

public:
	bool isBeautifulString(string &str)
	{
		if (str.size() < 3)
			return false;
		int num = 0;
		int distinctNum = 1;

		char first = str[0];
		int i=0;
		bool index = true;
		while (first == str[i])
		{
			num++;
			i++;
		}
		int j = i;
		while( j < str.size())
		{
			char next = str[j];
			if (next - first != 1)
				return false;
			int k = 0;
			for(; k<num; k++)
				if(str[j+k] != next)
					return false;
			j = j+num;
			distinctNum++;
			first = next;
		}
		if (distinctNum < 3)
			return false;
		return true;
	}
}S;

int main()
{
	int n;
	cin>>n;
	bool isRightLength = true;
	vector<bool> vec;
	while(n>0)
	{
		int length;
		string s;
		cin>>length;
		cin>>s;
		if(length != s.size())
		{
			isRightLength = false;
			break;
		}
		vec.push_back(S.isBeautifulString(s));
		n--;
	}
	if (isRightLength)
	{
		for (int i=0; i<vec.size(); i++)
			if ( vec[i] == 1)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
	}
	system("Pause");
	return 0;
}