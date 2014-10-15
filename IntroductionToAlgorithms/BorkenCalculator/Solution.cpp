#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;



class Solution{
public:
	int steps(int target, int a[])
	{
		if (target < 10)
		{
			if(a[target] == 1) return 2;
			int primeNumber[] = {0, 1, 2, 3, 5, 7};
			for (int i=0; i<6; i++)
			{
				if(primeNumber[i] == target && a[i] == 0)
					return 0;
				if(primeNumber[i] == target && a[i] != 0)
					return 2;
			}
		}
		int temp = target;
		vector<int> num;
		vector<int> isOK;

		for (int i=0; i< 10; i++)
			if (a[i] == 1)
				isOK.push_back(i);
		bool isIn = true;
		while(temp != 0)
		{
			int temp1 = temp%10;
			num.push_back(temp1) ;
			temp = temp/10;
			if(a[temp1] != 1)
				isIn = false;
		}
		if (isIn)
			return num.size()+1;

		bool isDivide = false;
		int min = 9999;
		for (int i = 0; i < isOK.size(); i++)
		{
			if (isOK[i] != 0 && isOK[i] != 1 && target % isOK[i] == 0)
			{
				int temp2 = target / isOK[i];
				isDivide = true;
				int x = steps(temp2, a) + 2;
				if ( x>0 && min > x)
					min = x;
			}
			else
				continue;
		}
		if(!isDivide)
			return -99999;
		return min;
	}

}S;

int main()
{	int sample;
	int target;
	int a[10];
	ifstream ifs("D:/C-small-practice.in");
	ofstream ofs("D:/output1.txt");
	string line;
	getline(ifs,line);
	sample = atoi(line.c_str());
	int *result = new int[sample];
	int j =0;
	while(getline(ifs, line)){
		istringstream iss(line);
		string word;
		int i = 0;
		while(iss>>word){
			a[i] = atoi(word.c_str());
			i++;
		}
		getline(ifs,line);
		target = atoi(line.c_str());
		result[j] = S.steps(target, a);
		j++;
	}
	for (int j=0; j<sample; j++){
		if ( result[j] <= 0 || result[j] > 2000){
			ofs<<"Case #"<<j+1<<":"<<" Impossible"<<endl;
			continue;
		}
		ofs<<"Case #"<<j+1<<":"<<" "<< result[j]<<endl;
	}
	ifs.close();
	ofs.close();
	


	/*int target;
	int a[10];
	for (int i = 0; i<10; i++)
		cin>>a[i];
	cin>>target;
	cout<<S.steps(target, a)<<endl;*/
	system("Pause");
}