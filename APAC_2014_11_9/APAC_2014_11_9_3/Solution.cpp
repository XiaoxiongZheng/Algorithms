#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

struct Link{
	string s1, s2;
	Link *next;
	Link *prior;
	Link(string x, string y) :s1(x), s2(y), next(nullptr), prior(nullptr){}
};

int main()
{
	FILE *in = freopen("large.txt", "r", stdin);
	FILE *out = freopen("output.txt", "w", stdout);
	int testCases;
	fscanf(in, "%d", &testCases);
	for (int caseIdx = 1; caseIdx <= testCases; ++caseIdx)
	{
		if (caseIdx == 100)
			printf("end");
		int N;
		vector<Link *> vec;
		fscanf(in, "%d", &N);
		for (int i = 1; i <= N; i++)
		{
			char pos1[4];
			char pos2[4];
			fscanf(in, "%s", pos1);
			fscanf(in, "%s", pos2);
			Link *l = new Link(pos1, pos2);
			vec.push_back(l);
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (vec[i]->s2 == vec[j]->s1){
					vec[i]->next = vec[j];
					vec[j]->prior = vec[i];
				}
			}
		Link* h = new Link("", "");
		for (int i = 0; i < N; i++)
			if (vec[i]->prior == nullptr)
				h->next = vec[i];
		fprintf(out, "Case #%d: ", caseIdx);
		Link *p = h->next;
		
		while (p)
		{
			fprintf(out, "%s-%s ", (p->s1).c_str(), (p->s2).c_str());
			p = p->next;
		}
		fprintf(out, "\n");
	}
	fclose(in);
	fclose(out);
}