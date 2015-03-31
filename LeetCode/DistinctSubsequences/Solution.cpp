#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	int numDistinct(string S, string T)
	{
		if (S.size() == 0) return 0;

		vector<vector<int> > vec(S.size(), vector<int>(T.size()));

		if (S[0] == T[0]) vec[0][0] = 1;
		else vec[0][0] = 0;

		for (int i = 1; i < S.size(); i++)
		{
			if (S[i] == T[0]) vec[i][0] = vec[i - 1][0] + 1;
			else vec[i][0] = vec[i - 1][0];
		}

		for (int i = 0; i < S.size(); i++)
			for (int j = i + 1; j < T.size(); j++)
				vec[i][j] = 0;

		for (int i = 1; i < S.size(); i++)
			for (int j = 1; j < T.size(); j++)
			{
				if (S[i] != T[j])
					vec[i][j] = vec[i - 1][j];
				else
					vec[i][j] = vec[i - 1][j] + vec[i - 1][j - 1];
			}
		return vec[S.size() - 1][T.size() - 1];
	}
}S1;

int main()
{
	string S = "rabbbit";
	string T = "rabbit";
	S1.numDistinct(S, T);
}