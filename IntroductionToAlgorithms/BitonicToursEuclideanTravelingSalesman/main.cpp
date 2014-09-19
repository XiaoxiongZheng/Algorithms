//Bitonic Tours Euclidean Traveling Salesman
//POJ 2677

#include <iostream>
#include <math.h>
#include <iomanip> 
using namespace std;

const int LENGTH = 6;
const int MAX = 9999;

struct dot{
	double x, y;
};

double distance(dot *points, int i, int j)
{
	return sqrt(pow((points[i].x - points[j].x), 2) + pow((points[i].y - points[j].y), 2));
}

double tour(dot *points, int n)
{
	double array[LENGTH][LENGTH];

	//初始化
	for(int i=0; i<LENGTH; i++)
		for(int j=0; j<LENGTH; j++)
			array[i][j] = 0;

	array[1][2] = distance(points, 1, 2);

	//对每个点求小于它的最短距离
	for (int j=3; j<=n; j++)
	{
		for(int i=1; i<j-1; i++)
		{
			array[i][j] = array[i][j-1]+distance(points, j-1, j);
		}
		array[j-1][j] = MAX;
		for(int i=1; i<j-1; i++ ){
			double temp = array[i][j-1] + distance(points,i,j);
			if (temp < array[j-1][j])
			{
				array[j-1][j] = temp;
			}
		}
	
	}
	array[n][n] = array[n-1][n] + distance(points,n-1,n);
	return array[n][n];
}

int main(){
	int num;
	dot *points = new dot[5];
	points[1].x = 4;
	points[1].y = 2;
	points[2].x = 2;
	points[2].y = 3;
	points[3].x = 3;
	points[3].y = 1;
	points[4].x = 1;
	points[4].y = 1;

	double min = tour(points, 4);
	cout << min <<endl;
	system("Pause");

}



















