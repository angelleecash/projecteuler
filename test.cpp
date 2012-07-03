// Routes.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

long long grid[22][22];
class Point
{
public:
	int x;
	int y;
	Point(int x, int y):x(x),y(y)
	{}
	Point(){}
};

long long count(int indexX,int indexY)
{
	memset(grid,0,sizeof(grid));
	queue<Point> q;
	q.push(Point(0,0));
	grid[0][0] = 1;
	Point temp;
	do{
		temp = q.front();
		q.pop();
		if(temp.x < indexX)
		{
			if(grid[temp.y][temp.x +1] == 0)
			{
				q.push(Point(temp.x + 1,temp.y));
			}
			grid[temp.y][temp.x + 1] += grid[temp.y][temp.x];
			
		}
		if(temp.y < indexY)
		{
			if(grid[temp.y + 1][temp.x ] == 0)
			{
				q.push(Point(temp.x,temp.y + 1));
			}
			grid[temp.y + 1][temp.x] += grid[temp.y][temp.x];
			
		}
	}while(!q.empty());


	return grid[indexY][indexX];
}

int main(int argc, char* argv[])
{
	//cout << count(1,1) << endl;
  //	cout << " 2 * 2 " << count(2,2) << endl;
  //	cout << count(3,3) << endl;
  //	cout << count(20,20) << endl;
  count(20, 20);
  //	ofstream outf("grid.html");
	//	outf << "<table>" << endl;
	for(int i = 0; i < 21; i++)
	{
		for(int j = 0; j < 21; j++)
		{
		  //outf << "<td>" << grid[i][j] << "</td>" << endl;
		  printf("%d, %d %lld \n", i, j, grid[i][j]);
		}
		//		outf << "</tr>" << endl;
	}
	//outf << "</table>" << endl;
	//system("pause");
	return 0;
}

