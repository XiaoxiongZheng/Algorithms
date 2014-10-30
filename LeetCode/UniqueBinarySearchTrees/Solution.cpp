#include <iostream>
using namespace std;

class Solution{
public:
	

	int numTrees(int n)
	{

		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		
		int a[1000] = { 0 };

		a[0] = 1;
		a[1] = 2;

		for (int j = 2; j <= n; j++){
			a[j - 1] = 2 * a[j - 2];
			for (int i = 1; i < j - 1; i++)
				a[j - 1] += a[i - 1] * a[j - i - 2];
		}
		return a[n-1];
	}
}S;

int main()
{
	int n;
	while (cin >> n)
		cout << S.numTrees(n) << endl;
}