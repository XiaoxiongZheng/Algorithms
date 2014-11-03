#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		vector<int> result;
		if (digits.size() == 0)
			return result;
		int index = 1;
		int temp = 0;
		int i = digits.size() - 1;
		while (i >= 0)
		{
			if (i == digits.size() - 1)
				temp += 1;
			temp = digits[i] + index;
			if (temp >= 10){
				index = 1;
				temp = temp % 10;
				digits[i] = temp;
				i--;
			}
			else{
				index = 0;
				digits[i] = temp;
				break;
			}
		}
		if (index && i == -1)
		{
			vector<int>::iterator iter = digits.begin();
			digits.insert(iter, index);
		}
		return digits;
	}
};