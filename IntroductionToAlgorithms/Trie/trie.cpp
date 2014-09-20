/**
   build trie data structure
 */

#include <iostream>
#include <string>
using namespace std;

const int Max = 26;

struct TrieNode
{
	bool isWord;
	TrieNode *next[26];
};

//insert trie node
void insert(TrieNode *root, const string& str)
{
	if (root == NULL || str.length() == 0)
		return;
	TrieNode *pt = root;
	for (int i = 0; i < str.length(); i++)
	{
		if (pt->next[str[i]-'a'] == NULL)
		{
			pt->next[str[i]-'a'] = new TrieNode;
			pt = pt->next[str[i]-'a'];
			for (int i = 0; i < Max; i++)
			{
				pt->next[i] = NULL;
			}
		}
		else
		{
			pt = pt->next[str[i]-'a'];
		}
	}
	pt->isWord = true;
}

//judge if the word is exist
bool exist(TrieNode *root, const string& str)
{
	if (str.length() == 0)
		return true;
	if (root == NULL)
		return false;
	TrieNode *pr = root;
	for (int i =0; i<str.length(); i++)
	{
		if (pr->next[str[i]-'a'] == NULL)
			return false;
		else
		{
			pr = pr->next[str[i]-'a'];
		}
	}
	if (pr->isWord)
		return true;
	return false;
}

int main()
{
	TrieNode *root = new TrieNode;
	root->isWord = false;
	for (int i = 0; i < Max; i++)
	{
		root->next[i] = NULL;
		
	}
	int num = 0;
	cin>>num;
	for (int i = 0; i < num; i++)
	{
		string s;
		cin>>s;
		insert(root,s);
	}
	cout<<endl<<"please input the word which you want to look up:"<<endl;
	string s;
	while(cin>>s)
	{
		if (exist(root,s))
			cout<<"Yes, it is!"<<endl;
		else
		{
			cout<<"Sorry, it isn't"<<endl;
		}
	}
	system("Pause");
	return 0;
}