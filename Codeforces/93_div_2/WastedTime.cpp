#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

int main ()
{
	int n, k;
	while (cin >> n >> k)
	{
		int x[1001] = {0}, y[1001] = {0};	
		int i = 0;
		while (i < n)
		{
			cin >> x[i] >> y[i];
			i++;
		}
		double sum = 0;
		for (int i = 1; i < n; i++)
		{
			sum += sqrt(double(pow(x[i] - x[i - 1], 2))+ pow(y[i] - y[i - 1], 2));	
		}
		cout.setf(ios::fixed);
		cout << setprecision(9) << double(k) * sum / 50 << endl;
	}
}
