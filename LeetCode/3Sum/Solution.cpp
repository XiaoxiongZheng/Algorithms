#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
	//recursive binary search
	bool BinarySearch_R(const vector<int> &num, int begin, int end, int target)
	{

		if( begin == end ){
			if(target == num[begin])
				return true;
			else
				return false;
		}
		if(begin > end)
			return false;
		int mid = (begin + end) / 2;
		if(target > num[mid])
			return BinarySearch_R(num, mid+1, end, target);
		if(target == num[mid])
			return true;
		else
			return BinarySearch_R(num, begin, mid-1, target);
	}
	//non-recursive binary search
	bool BinarySearch(vector<int> &num, int begin, int end, int target)
	{
		while(begin <= end)
		{
			int mid = (begin + end)/2;		
			if(target > num[mid])
				begin = mid + 1;
			if(target < num[mid])
				end = mid - 1;
			if(target == num[mid])
				return true;
		}
		return false;

	}

	vector<vector<int> > threeSum(vector<int> &num)
	{
		vector<vector<int> > results;
		if(num.size() < 3) return results;
		sort(num.begin(), num.end());		//sort

		int length = num.size();

		for (int start = 0; start < (length - 2) && num[start] <= 0; start++)
		{
			if (start > 0 && num[start] == num[start - 1]) continue;													//this is critical !
			for (int end = length - 1; end != start && num[end] >= 0; end--)
			{
				if (end < length - 1 && num[end] == num[end + 1]) continue;
				int target = -(num[start] + num[end]);
				if (binary_search(num.begin()+start+1, num.begin()+end, target))
				{
					vector<int> result;
					result.push_back(num[start]);
					result.push_back(target);
					result.push_back(num[end]);
					results.push_back(result);
				}
			}
		}
		return results;
	}
};

int main()
{
	//int ttt[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	int ttt[] = {-1, 0 , 1, 1, -1};
	vector<int> vec(ttt, ttt+sizeof(ttt)/sizeof(ttt[0]));
	/*vec.push_back(-1);
	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(0);*/
	/*vec.push_back(1);
	vec.push_back(2);
	vec.push_back(4);*/
	Solution S;
	vector<vector<int> > g = S.threeSum(vec);
	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < g[i].size(); j++) printf("%d ", g[i][j]);
		putchar('\n');
	}
	return 0;
}