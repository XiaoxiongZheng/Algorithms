#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	
	bool isMatch(const char *s, const char *p)
	{
		if(*p == 0) return *s == 0;
		if(*(p+1) != '*')
		{
			if(*s != 0 && (*p == *s || *p == '.')) return isMatch(s+1, p+1);
			else return false;
		}
		else
		{
			while(*s != 0 && (*s == *p || *p == '.'))
			{
				if(isMatch(s,p+2)) return true;
				s++;
			}
			return (isMatch(s, p+2));
		}
	}
}S;

int main()
{
	string s;
	string p;
	while(cin>>s>>p)
		cout<<S.isMatch(s.c_str(), p.c_str())<<endl;
	
}

