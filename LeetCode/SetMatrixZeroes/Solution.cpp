#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	void setZeroes(vector<vector<int>> &matrix)
	{
		int row = matrix.size();
		int column = matrix[0].size();
		if (row == 0 || column == 0)
			return;
		bool rflag = false;
		for (int i = 0; i < column; i++)
			if (matrix[0][i] == 0)
			{
				rflag = true;
				break;
			}
		bool cflag = false;
		for (int i = 0; i < row; i++)
			if (matrix[i][0] == 0){
				cflag = true;
				break;
			}
		for (int i = 1; i < row; i++)
			for (int j = 1; j < column; j++)
				if (matrix[i][j] == 0)
				{ 
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
		for (int i = 1; i < column; i++)
			if (matrix[0][i] == 0)
				for (int j = 1; j < row; j++)
					matrix[j][i] = 0;
		for (int i = 1; i < row; i++)
			if (matrix[i][0] == 0)
				for (int j = 1; j < column; j++)
					matrix[i][j] = 0;
		if (rflag)
			for (int i = 0; i < column; i++)
				matrix[0][i] = 0;
		if (cflag)
			for (int i = 0; i < row; i++)
				matrix[i][0] = 0;
	}
};