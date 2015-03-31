#include <iostream>
using namespace std;

class Solution
{
public:
	int lengthOfLastWord(const char *s)
	{
		int pos = -1, i = 0;
		int len = strlen(s);
		len--;
		while (len >= 0 && s[len--] == ' ');
		if (len < 0) return 0;

		while (s[i] != '\0' && i < len){
			if (s[i] == ' ')
				pos = i;
			i++;
		}
		if (pos == -1) return len + 1;
		return len - pos;
	}
};