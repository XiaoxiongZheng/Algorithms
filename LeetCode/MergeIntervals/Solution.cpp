#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() :start(0), end(0){}
	Interval(int s, int e) :start(s), end(e){}
};

class Solution
{
public:
	vector<Interval> merge(vector<Interval> &intervals)
	{
		if (intervals.size() == 0)
			return intervals;
		if (intervals.size() == 1)
			return intervals;
		sort(intervals.begin(), intervals.end(), sortInterval);
		vector<Interval> result;
		result.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i].start <= result[result.size() - 1].end)
				result[result.size() - 1].end = result[result.size() - 1].end > intervals[i].end ? result[result.size() - 1].end : intervals[i].end;
			else
				result.push_back(intervals[i]);
		}
		return result;
	}
private:
	static bool sortInterval(const Interval &i1, const Interval &i2)
	{
		return i1.start < i2.start;
	}
}S;

int main()
{
	Interval i1(1, 3);
	Interval i2(2, 6);
	Interval i3(8, 10);
	Interval i4(15, 18);
	vector<Interval> vec;
	vec.push_back(i1);
	vec.push_back(i2);
	vec.push_back(i3);
	vec.push_back(i4);
	S.merge(vec);

}