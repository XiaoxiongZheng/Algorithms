#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;


int main() {

	FILE *in = freopen("input.txt", "r", stdin);
	FILE *out = freopen("output.txt", "w", stdout);

	int index[1000][2] = { 0 };
	int p[1000] = { 0 };
	int caseNum;
	fscanf(in, "%d", &caseNum);
	for (int caseIdx = 1; caseIdx <= caseNum; ++caseIdx) {
		int numCities;
		fscanf(in, "%d", &numCities);
		int city1;
		int city2;
		vector<int> determineCity;
		for (int i = 0; i < numCities; i++)
		{
			fscanf(in, "%d", &index[i][0]);
			fscanf(in, "%d", &index[i][1]);
		}
		int determineCityNums;
		fscanf(in, "%d", &determineCityNums);
		int city3;
		fprintf(out, "Case #%d: ", caseIdx);
		for (int i = 0; i < determineCityNums; i++)
		{
			fscanf(in, "%d", &city3);
			int num = 0;
			for (int j = 0; j < numCities; j++)
			{
				if (city3 >= index[j][0] && city3 <= index[j][1])
					num++;
			}
			fprintf(out, "%d ", num);
		}
		fprintf(out, "\n");
	}
	fclose(in);
	fclose(out);
}