// the longest palindrome substring
// using dynamic programming


#include <iostream>
#include <math.h>
using namespace std;

#define MAXSIZE 10
#define max(a,b) (a)>(b)?(a):(b)

int LPS(const string &str)
{
	if (str.length() == 0)
		return 0;
	int array[MAXSIZE][MAXSIZE];
	for (int i=0; i<MAXSIZE; i++)
		for (int j=0; j<MAXSIZE; j++)
			array[i][j]=0;

	for (int i=0; i<str.length(); i++)
	{
		
		array[i][i] = 1;
		for (int j=i-1; j>=0; j--)
		{
			if (str[i] == str[j])
			{
				array[i][j] = array[i-1][j+1] + 2;
			}
			else
				array[i][j] = max(array[i][j+1], array[i-1][j]);
		}
	}
	return array[str.length()-1][0];
}

int main()
{
	string s = "civvic";
	int i = LPS(s);
	printf("%d",i);
	system("Pause");
}