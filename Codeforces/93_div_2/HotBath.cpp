#include <iostream>
using namespace std;

int main()
{
	int t1, t2, x1, x2, t0;
	while (cin >> t1 >> t2 >> x1 >> x2 >> t0)
	{
		if (t0 == t1 && t0 == t2)
		{
			if (x1 > x2)
				cout << x1 << " " << 0 << endl;
			else
				cout << 0 << " " << x2 << endl;
			continue;
		}
		if (t0 == t1)
		{
			cout << x1 << " " << 0 << endl;
			continue;
		}
		if (t0 == t2)
		{
			cout << 0 << " " << x2 << endl;
			continue;
		}
		if (abs(t1 - t0) > abs(t0 - t2))
		{
			int val = abs(t1 - t0) / abs(t0 - t2);	
			int y2 = min((x1 / val) * val, x2);
			int y1 = y2 / val;
			cout << y1 << " " << y2 << endl;
		}
		else
		{
			int val = abs(t0 - t2) / abs(t1 - t0);
			int y1 = min((x2 /val) * val, x1);
			int y2 = y1 / val;
			cout << y1 << " " << y2 << endl;
		}
	}
}
