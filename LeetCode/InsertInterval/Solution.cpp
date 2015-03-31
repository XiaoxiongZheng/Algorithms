#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval{
	int start;
	int end;
	Interval() :start(0), end(0){}
	Interval(int s, int e) :start(s), end(e){}
};
class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
	{
		vector<Interval> result;
		if (intervals.size() == 0)
		{
			result.push_back(newInterval);
			return result;
		}
		int length = intervals.size();
		if (newInterval.start > intervals[length - 1].end)
		{
			intervals.push_back(newInterval);
			return intervals;
		}
		int i = 0;
		while (i < length)
		{
			if (intervals[i].start > newInterval.end){
				result.push_back(newInterval);
				break;
			}
			else if (intervals[i].end < newInterval.start)
			{
				result.push_back(intervals[i]);
				i++;
			}
			else{
				newInterval.start = min(newInterval.start, intervals[i].start);
				newInterval.end = max(newInterval.end, intervals[i].end);
				if (i == length - 1){
					result.push_back(newInterval);
					return result;
				}
				i++;
			}
		}
		while (i < length){
			result.push_back(intervals[i]);
			i++;
		}
		return result;
	}
}S;

int main()
{
	Interval i1(0, 2);
	Interval i2(3, 5);
	Interval i3(6, 8);
	Interval i4(10, 12);
	Interval i5(13, 15);
	Interval n1(4, 7);
	vector<Interval> vec;
	vec.push_back(i1);
	vec.push_back(i2);
	vec.push_back(i3);
	vec.push_back(i4);
	vec.push_back(i5);
	S.insert(vec, n1);
}