#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	string longestCommonPrefix(vector<string> &strs)
	{
		if (strs.size() == 0)
			return "";
		if (strs.size() == 1)
			return strs[0];
		bool longPrefix = true;
		int pos = 0;
		while(longPrefix)
		{
			char temp = strs[0][pos];
			for (int i = 1; i < strs.size(); i++)
			{
				if(temp == strs[i][pos])
					continue;
				else{
					longPrefix = false;
					break;
				}
			}
			if (!longPrefix)
				break;
			pos++;
		}
		return strs[0].substr(0,pos);
	}
}S;

int main()
{
	/*string s1 = "hello";
	string s2 = "hello1";
	string s3 = "haha";*/
	vector<string> vec;
	/*vec.push_back(s1);
	vec.push_back(s2);
	vec.push_back(s3);*/
	S.longestCommonPrefix(vec);
	/*cout<<S.longestCommonPrefix(vec)<<endl;*/
	system("Pause");
}