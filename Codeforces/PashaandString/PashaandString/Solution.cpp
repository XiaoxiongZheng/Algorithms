#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	
	while (cin >> str)
	{
		int len = str.size();
		int num;
		cin >> num;
		vector<int> str_pos;
		while (num--)
		{
			int pos;
			cin >> pos;
			str_pos.push_back(pos);
		}
		sort(str_pos.begin(), str_pos.end());
		int sum = 0, j = 1;
		for (int i = 1; i <= len / 2; i++)
		{
			while (j <= str_pos.size() && str_pos[j - 1] <= i)
				j++;
			if ((j - 1) & 1)
				swap(str[i - 1], str[len - i]);
		}
		cout << str << endl;
	}
	return 0;
}