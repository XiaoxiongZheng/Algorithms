#include <iostream>
#include <vector>
using namespace std;

class Solution{

public:
	int maxProfit(vector<int> &prices)
	{
		if (prices.size() == 0 || prices.size() == 1)
			return 0;
		vector<int> spread;
		for (int i = 1; i < prices.size(); i++)
			spread.push_back(prices[i] - prices[i - 1]);
		int result = 0;
		for (int i = 0; i < spread.size(); i++)
			if (spread[i]>0)
				result += spread[i];
		return result;
	}
};