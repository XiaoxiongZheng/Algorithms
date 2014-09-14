#include <iostream>
using namespace std;

#define MAXSIZE 101

int solution(int array[], int n, int m)
{
	if (m >= n)
		return 100;
	int a[MAXSIZE];
	a[0] = array[0]-1;
	for (int i=1; i<n; i++)
		a[i] = array[i]-array[i-1]-1;
	a[n] = 100 - array[n-1];

	int max = 0;
	for (int i = 0; i<=n-m; i++)
	{
		int result = 0;
		for (int j=i; j<=i+m; j++)
		{
			result +=a[j];
		}
		if (result>=max)
			max = result;

	}
	return max+m;

}
int main(){
	int num;
	cin>>num;
	int *result = new int[num];
	for(int j=0; j<num; j++)
	{
		int n, m;
		cin>>n>>m;
		int *array = new int[n];
		for(int i=0; i<n ; i++)
			cin>>array[i];
		result[j] = solution(array, n, m);
		delete[] array;
	}

	for(int i=0; i<num; i++)
		cout<<result[i]<<endl;

	system("Pause");
}