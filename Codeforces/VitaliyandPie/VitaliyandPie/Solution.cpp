#include <iostream>
#include <string>
using namespace std;

int vitaliy_and_pie(const string &str)
{
	int key[26] = { 0 };
	int door[26] = { 0 };
	int len = str.size();
	int sum = 0;
	for (int i = 1; i <= len; i++)
	{
		if (i & 1)
			key[str[i - 1] - 'a']++;
		else
		{
			if (key[str[i - 1] - 'A'] == 0)
			{
				door[str[i - 1] - 'A']++;
				sum++;
			}
			else
				key[str[i - 1] - 'A']--;
		}
	}
	return sum;
}

int main()
{
	int num;
	while (cin >> num)
	{
		string str;
		cin >> str;
		int sum = vitaliy_and_pie(str);
		cout << sum << endl;
	}
	return 0;
}