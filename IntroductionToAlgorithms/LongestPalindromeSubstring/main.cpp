// the longest palindrome substring
// using dynamic programming


#include <iostream>
#include <math.h>
using namespace std;

#define MAXSIZE 10

int LPS(const string &str)
{
	if (str.length() == 0)
		return 0;
	
/*
	int **array;
	array = new int *[str.length()];
	for(int i=0; i<str.length(); i++)
	{
		array[i] = new int[str.length()];
	}
	for(int i=0; i<str.length(); i++)
		for (int j = 0; j < str.length(); j++)
		{
			array[i][j] = 0;
		}
*/
	int array[MAXSIZE][MAXSIZE];
	for (int i=0; i<MAXSIZE; i++)
		for (int j=0; j<MAXSIZE; j++)
			array[i][j]=0;

	for (int i = 1; i <= str.length(); i++)
	{
		for (int j = 1; j<=str.length()-i; j++)
		{
			if (str[i-1] == str[str.length()-j])
			{
				array[i][j] = array[i-1][j-1]+2;
			}
			else
			{
				if (array[i-1][j]>array[i][j-1])
				{
					array[i][j] = array[i-1][j];
				}
				else
					array[i][j] = array[i][j-1];
			}
		}
	}
	int max = array[str.length()-1][str.length()];
	if (str.length()%2 == 1)
		max++;
	return max;
}

int main()
{
	string s = "character";
	int i = LPS(s);
	printf("%d",i);
	system("Pause");
}