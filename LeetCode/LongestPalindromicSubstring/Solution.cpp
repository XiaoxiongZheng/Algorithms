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
	string longestPalindrome(string str)
	{
		int length = str.size();
		bool isP[MAXSIZE][MAXSIZE];
		memset(isP, false, sizeof(isP));
		for(int i=0; i<length; i++) isP[i][i] = true;
		for(int i=0; i<length-1; i++)
			if(str[i] == str[i+1])
				isP[i][i+1] = true;
		for(int len=2; len<=length; len++) 
			for(int i=0; i<length-len+1; i++)
			{
				int j = i+len-1;
				if (str[i] == str[j]) isP[i][j] = isP[i+1][j-1] && true;
			}
		int maxLen = 0, sta = 0;
		for (int i=0; i<length; i++)
			for(int j=0; j<length; j++)
				if ( isP[i][j] && j-i+1 > maxLen ) maxLen = j-i+1 , sta = i ;
		return str.substr(sta, maxLen);
	}
}S;

int main(){
	string str ;
	while ( cin >> str ) cout << S.longestPalindrome(str) <<"\n" ;
}