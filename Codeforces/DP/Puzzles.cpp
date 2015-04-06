#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
	int n, m;
	while (cin >> n >> m)
	{
		int a[1001], count = 0;
		while (count < m)
			cin >> a[count++];
		sort(a, a + m);
		int min_val = INT_MAX;
		for (int i = n - 1; i < m; i++)
			min_val = min(min_val, a[i] - a[i - n + 1]);
		cout << min_val << endl;
	}
	return 0;
}
