#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> searchRange(int A[], int n, int target)
	{
		if (n == 0)
		{
			return{ -1, -1 };
		}
			
		int start = 0, end = n - 1;
		int mid;
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (A[mid] == target)
				break;
			if (A[mid] < target)
				start = mid + 1;
			else
				end = mid - 1;
		}
		if (A[mid] != target)
			return{ -1, -1 };
		vector<int> result;
		int left = mid;
		while (left >= 0 && A[left] == target )
			left--;
		result.push_back(left + 1);
		int right = mid;
		while (right < n && A[right] == target)
			right++;
		result.push_back(right - 1);
		return result;
	}
}S;

int main()
{
	int A[] = { 0, 0, 2, 3, 4, 4, 4, 5 };
	vector<int> vec = S.searchRange(A, sizeof(A) / sizeof(A[0]), 5);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	system("Pause");
}