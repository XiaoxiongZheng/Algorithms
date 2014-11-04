#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<vector<string> > solveQueens(int n)
	{
		vector<vector<string> > result;
		if (n == 0)
			return result;
		vector<string> vec;
		vector<int> index;
		index.resize(n);
		for (int i = 0; i < n; i++)
			index[i] = 0;
		getQueens(0, n, result, vec, index);
		return result;
	}
	bool isValid(int row, int col, vector<int> &index)
	{
		for (int i = 0; i < row; i++)
		{
			if (col == index[i])
				return 0;
			if (col - index[i] == row - i)
				return 0;
			if (col - index[i] == i - row)
				return 0;
		}
		return 1;
	}
	void getQueens(int depth, int max_depth, vector<vector<string> >& result, vector<string>& path, vector<int>& index)
	{
		if (depth == max_depth){
			result.push_back(path);
			return;
		}
		for (int i = 0; i < max_depth; i++)
		{
			if (isValid(depth, i , index)){
				vector<string> p = path;
				string s;
				s.resize(max_depth);
				for (int i = 0; i < max_depth; i++)
					s[i] = '.';
				vector<int> sign = index;
				sign[depth] = i;
				s[i] = 'Q';
				p.push_back(s);
				getQueens(depth + 1, max_depth, result, p, sign);
			}
		}
		
	}
}S;

int main()
{
	vector<vector<string> > vec = S.solveQueens(4);
	cout << vec.size() << endl;
	system("Pause");
}