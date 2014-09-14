#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class MatchMaker
{
public:
	vector<string> getBestMatches(vector<string>& vec,string& name, int i)
	{
		vector<string>::iterator target = vec.begin();
		for (vector<string>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		{
			istringstream stream(*iter);
			string word = NULL;
			stream>>word;
			if (word == name)
			{
				target = iter;
				break;
			}
		}

	}

};
