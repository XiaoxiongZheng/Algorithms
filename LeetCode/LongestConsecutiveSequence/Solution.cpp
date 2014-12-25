#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
	int longestConsecutive(vector<int> &num)
	{
		unordered_set<int> s;
		int length = num.size();
		if (length == 0)
			return 0;
		if (length == 1)
			return 1;
		for (int i = 0; i < length; i++)
			s.insert(num[i]);
		int maxLength = 0;
		for (int i = 0; i < length; i++)
		{
			auto iter = s.find(num[i]);
			if (iter == s.end())
				continue;
			s.erase(iter);
			int leftLength = 0, leftValue = num[i] - 1;
			while ((iter = s.find(leftValue)) != s.end())
			{
				//auto iter1 = s.find(leftValue);
				s.erase(iter);
				leftValue--;
				leftLength++;
			}
			int rightLength = 0, rightValue = num[i] + 1;
			while ((iter = s.find(rightValue)) != s.end())
			{
				//auto iter1 = s.find(rightValue);
				s.erase(iter);
				rightValue++;
				rightLength++;
			}
			if (maxLength < leftLength + rightLength + 1)
				maxLength = leftLength + rightLength + 1;
		}
		return maxLength;
	}
}S;

int main()
{
	vector<int> vec = { -1, 1, 0};
	S.longestConsecutive(vec);
}