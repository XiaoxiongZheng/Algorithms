#include <iostream>
#include <string>
using namespace std;

const int MAXSIZE = 500;

/*

//BigGod of Yibo codes
class Solution {
	public:
		string longestPalindrome(string s) ;
} F;

string s ;
bool visited[MAXSIZE][MAXSIZE] ;
int a[MAXSIZE][MAXSIZE];

bool Finda(int i,int j) {
	if ( visited[i][j] ) return a[i][j] ;
	else                 visited[i][j] = true ;
	if      ( i     == j ) a[i][j] = 1 ;
	else if ( i     >  j ) a[i][j] = 0 ;
	else if ( i + 1 == j ) a[i][j] = (s[i] == s[j]) ;
	else                   a[i][j] = (s[i] == s[j]) && Finda(i+1,j-1) ;
	return a[i][j] ;
}

//Dynamic Programming
string Solution::longestPalindrome(string _s) {
	s = _s ;
	memset( visited , false , sizeof(visited)) ;
	for (int i=0; i < s.size(); i++)
		for (int j = 0; j < s.size(); j++)
			Finda(i,j) ;
	int maxLen = 0, sta = 0;
	for (int i=0; i<s.size(); i++)
		for(int j=0; j<s.size(); j++)
			if ( a[i][j] && j-i+1 > maxLen ) maxLen = j-i+1 , sta = i ;
	return s.substr(sta, maxLen);
}
*/

class Solution{
public:
	//Dynamic Programming
	string DP_longestPalindrome(string str)
	{
		int length = str.size();
		bool isP[MAXSIZE][MAXSIZE];
		int maxLen = 1, sta = 0;
		memset(isP, false, sizeof(isP));
		for(int i=0; i<length; i++) isP[i][i] = true;
		for(int i=0; i<length-1; i++)
			if(str[i] == str[i+1])
				isP[i][i+1] = true, maxLen=2, sta = i;
		
		for(int len=3; len<=length; len++) 
			for(int i=0; i<length-len+1; i++)
			{
				int j = i+len-1;
				if (str[i] == str[j]) isP[i][j] = isP[i+1][j-1];
				if (isP[i][j] && j-i+1 > maxLen ) maxLen = j-i+1 , sta = i ;
			}
			return str.substr(sta, maxLen);
	}
	//Manacher Algorithm
	string M_longestPalindrome(string str)
	{
		int length = 2*str.size()+1;
		/*int *range = new int[length];
		char *s = new char[length];*/

		int range[10000];
		char s[10000];

		//initialize
		for(int i=0; i<length; i++)
		{
			range[i] = 1;
			if((i&1)==0) s[i]='#';
			else         s[i] = str[i/2];
		}
		s[length]=0;
		//cout<<s<<"\n";
		//loop
		int id=0,max=1;
		range[0]=1;
		for(int i=1; i<length; i++)
		{
			if(max>i)
				range[i] = min(range[2*id-i], max-i);//不加一是因为，max = i+range[i]，max是i到恰好到不了的那个位置
			else
				range[i] = 1;
			
			for(;(i+range[i])<length &&(i-range[i])>=0 && s[i+range[i]] == s[i-range[i]] ; range[i]++);
			if(i+range[i]>max) max = i+range[i], id = i;
		}
		int maxLen = 0, pos = 0;
		for(int i=0; i<length; i++)
			if(maxLen<range[i]) 
			{
				maxLen = range[i];
				pos=i;
			}
		cout<< maxLen<<endl;
		return str.substr((pos-maxLen+1)/2, maxLen-1);
	}
}S;

int main(){
	
		cout << S.M_longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") <<"\n" ;
	/*string str;
	while(cin>>str) cout<<S.M_longestPalindrome(str)<<endl;*/
	
	system("Pause");
}