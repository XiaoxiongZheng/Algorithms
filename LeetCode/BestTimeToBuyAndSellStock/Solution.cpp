#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//small fat's version
class Solution {
private:
	vector<int> L, R;
public:
	int maxProfit(vector<int> &A) {
		L.resize(A.size() + 2); R.resize(A.size() + 2);
		L[0] = INT_MAX, R[A.size() + 1] = INT_MIN;
		for (int i = 0; i < A.size(); i++) L[i + 1] = min(L[i], A[i]);
		for (int i = A.size(); i >= 1; i--) R[i] = max(R[i + 1], A[i - 1]);
		int ans = 0;
		for (int i = 1; i < A.size(); i++) ans = max(ans, R[i + 1] - L[i]);
		return ans;
	}
};


//brother two's version
class Solution{
public:
	int maxProfit(vector<int> &prices)
	{
		if (prices.size() == 0)
			return 0;
		int result = 0;
		int start = INT_MAX;
		int end = INT_MIN;
		for (int i = 0; i < prices.size(); i++)
		{	
			if (prices[i] < start){
				start = prices[i];
				end = start;
			}
			if (prices[i] > end){
				end = prices[i];
				if (result < end - start)
					result = end - start;
			}
		}
		return result;
	}
};