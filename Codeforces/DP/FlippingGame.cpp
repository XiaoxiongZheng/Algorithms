#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{	
		int a[100], count = 0;
		while (count < n)
			cin >> a[count++];
		int status[102][102] = {0};
		for (int i = 1; i <= n; i++)
			status[i][i] = a[i - 1];
		for (int l = 2; l <= n; l++)
			for (int i = 1; i <= n - l + 1; i++)
				status[i][i + l - 1] =a[i + l - 2] + status[i][i + l - 2];
		int max_val = INT_MIN;
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				max_val = max(max_val, status[1][i - 1] + j - i + 1 - status[i][j] + status[j + 1][n]);
		cout << max_val << endl;
	}
}
