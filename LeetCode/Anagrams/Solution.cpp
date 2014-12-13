#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<string> anagrams(vector<string> &strs)
	{
		vector<string> result;
		if (strs.size() == 0 || strs.size() == 1)
			return result;
		map<string, string> words;
		map<string, int> num;
		for (int i = 0; i < strs.size(); i++)
		{
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			if (words.count(temp) > 0){
				result.push_back(strs[i]);
				if (num[temp] == 0)
				{
					result.push_back(words[temp]);
					num[temp] = 1;
				}
			}
			else{
				words[temp] = strs[i];
				num[temp] = 0;
			}
		}
		return result;
	}
}S;

int main(){
	vector<string> strs;
	strs.push_back("eel");
	strs.push_back("lee");
	S.anagrams(strs);
}