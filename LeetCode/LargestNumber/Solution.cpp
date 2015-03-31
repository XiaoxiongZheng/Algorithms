#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <utility>
using namespace std;

class Solution
{
public:
	static bool compare(const string &str1, const string &str2)
	{
		return str1 + str2 > str2 + str1;
	}
	string largestNumber(vector<int> &num)
	{
		if (num.size() == 0) return "";
		if (num.size() == 1) return convert(num[0]);
		vector<string> vec;
		for (int key : num)
			vec.push_back(convert(key));
		sort(vec.begin(), vec.end(), compare);

		string result = "";
		for (string key : vec)
			result += key;
		size_t i = 0;
		for (; i < result.length() - 1; i++){
			if (result[i] != '0')
				break;
		}
		if (i == 0) return result;
		result.erase(result.begin(), result.begin() + i);
		return result;

	}
private:
	string convert(int i)
	{
		stringstream ss;
		ss << i;
		return ss.str();
	}
}S;

int main()
{
	vector<int> vec = {1, 2};
	S.largestNumber(vec);
}