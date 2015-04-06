#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		string str;
		cin >> str;
		int i = 0;
		while(i < num && str[i] == '.') i++;
		int j = i + 1;
		for (; j < num; j++)
		{
			if (str[j] == '*')
			{
				int step = j - i;
				if ((num - j) % step != 0)
					continue;
				int k = 1;
				bool find = true;
				while (j + step * k < num)
				{
					if (str[num - step * j] != '*')
					{
						find = false;
						break;
					}
					k++;
				}
				if (find){
					cout << "yes" << endl;
					break;
				}
			}
		}
		if (j == num)
			cout << "no" << endl;
	}
}
