#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int stick[101] = {0};
		int count = 0;
		while (count < n)
		{
			cin >> stick[count];
			count++;
		}
		sort(stick, stick + n);
		int sum = 0, i = 0;
		while (i < n - 1)
		{
			if (stick[i] == stick[i + 1])	
			{
				i = i + 1;
				sum++;
			}
			i++;
		}
		cout << sum / 2 << endl;
	}
}
