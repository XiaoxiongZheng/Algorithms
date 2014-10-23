#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char> > &board)
	{
		if(board.size() == 0)
			return;
		vector<vector<int> > index;
		for (int i = 0; i<board.size(); i++){
			vector<int> vec;
			for (int j = 0; j<board[0].size(); j++)
				vec.push_back(0);
			index.push_back(vec);
		}

		for (int i=0; i<board[0].size(); i++){
			if (board[0][i] == 'O')
				dfs(board, 0, i, index);
			if (board[board.size() - 1][i] == 'O')
				dfs(board, board.size() - 1, i, index);
		}
		for(int i=0; i<board.size(); i++)
		{
			if(board[i][0] == 'O')
				dfs(board, i, 0, index);
			if(board[i][board[0].size()-1] == 'O')
				dfs(board, i, board[0].size() - 1, index);
		}
		for(int i=0; i<board.size(); i++)
			for(int j=0; j<board[0].size(); j++){
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == 'A')
					board[i][j] = 'O';
			}

	}
	void dfs(vector<vector<char> > &board, int x, int y, vector<vector<int> > &index)
	{
		if (x >= board.size() || x < 0 || y >= board[0].size() || y < 0 || index[x][y] == 1 || board[x][y] == 'X')
			return;
		board[x][y] = 'A';
		index[x][y] = 1;
		dfs(board, x-1, y, index);
		dfs(board, x+1, y, index);
		dfs(board, x, y-1, index);
		dfs(board, x, y+1, index);
		
	}
}S;
int main()
{
	vector<vector<char> > vec;
	char *a = "XXXX";
	char *b = "XOOX";
	char *c = "XXOX";
	char *d = "XOXX";
	vector<char> av(a, a+4);
	vector<char> bv(b, b+4);
	vector<char> cv(c, c+4);
	vector<char> dv(d, d+4);
	vec.push_back(av);
	vec.push_back(bv);
	vec.push_back(cv);
	vec.push_back(dv);
	S.solve(vec);
	for(int i=0; i<vec.size(); i++){
		for(int j=0; j<vec[0].size(); j++)
			cout<<vec[i][j];
		cout<<endl;
	}
	system("Pause");
}