#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void rotate(vector<vector<int> > &matrix)
	{
		int n = matrix.size();
		for (int i = 0; i < n / 2; i++)
			for (int j = i; j < n - i - 1; j++)
			{
				int temp = matrix[n -1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = matrix[i][j];
				matrix[i][j] = temp;
			}
	}
}S;

int main()
{
	vector<int> vec1 = { 1, 2, 3 };
	vector<int> vec2 = { 4, 5, 6 };
	vector<int> vec3 = { 7, 8, 9 };
	vector<vector<int> > matrix;
	matrix.push_back(vec1);
	matrix.push_back(vec2);
	matrix.push_back(vec3);
	S.rotate(matrix);
	for (int i = 0; i < matrix.size(); i++){
		for (int j = 0; j < matrix.size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	system("Pause");
}