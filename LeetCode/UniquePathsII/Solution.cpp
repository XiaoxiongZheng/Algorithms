#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
	{
		int grid[100][100];
		if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
			return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		bool rowIndex = false;
		bool colIndex = false;
		for (int i = 0; i < n; i++)
		{
			if (colIndex || obstacleGrid[0][i] == 1){
				grid[0][i] = 0;
				colIndex = true;
			}
			else
				grid[0][i] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			if (rowIndex || obstacleGrid[i][0] == 1){
				grid[i][0] = 0;
				rowIndex = true;
			}
			else
				grid[i][0] = 1;
		}
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++){
				if (obstacleGrid[i][j] == 1)
					grid[i][j] = 0;
				else
					grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
			}
		return grid[m - 1][n - 1];
	}
};