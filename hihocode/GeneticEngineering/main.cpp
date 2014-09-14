#include <iostream>
#include <istream>
#include <string>
using namespace std;

int solution(const string &s, int k)
{
	int repeat = 2*k - s.length();
	if (repeat<=0)
	{
		int result = 0;
		for (int i=0; i<k; i++)
		{
			if (s[i] != s[s.length()-i-1])
				result++;
		}
		return result;
	}
	else
	{
		int result = 0;
		int gap = s.length()-k;
		for(int i=0; i<gap; i++)
		{
			int j = i;
			int a[4];
			for (int k=0; k<4; k++)
				a[k]=0;
			while (j<s.length())
			{
				
				switch (s[j])
				{
					case 'A':
						a[0]++;
						break;
					case 'T':
						a[1]++;
						break;
					case 'C':
						a[2]++;
						break;
					case 'G':
						a[3]++;
						break;
				} 
				j=j+gap;
			}
			int max=0;
			for (int k=0; k<4; k++)
			{
				if (a[k]>=max)
					max = a[k];
			}
			result = result+a[0]+a[1]+a[2]+a[3]-max;
		}
		return result;
	}
}
int main(){
	int num;
	cin>>num;
	int *result = new int[num];
	for(int i=0; i<num; i++)
	{
		string s;
		cin>>s;
		int k;
		cin>>k;
		result[i] = solution(s,k);
	}
	for(int i=0; i<num; i++)
		cout<<result[i]<<endl;
	system("Pause");
}