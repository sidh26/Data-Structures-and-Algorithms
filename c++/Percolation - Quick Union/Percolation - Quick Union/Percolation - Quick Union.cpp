// Percolation - Quick Union.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "stdlib.h"
#include<fstream>
#include "stdio.h"
using namespace std;

#define ROW_SIZE 50
#define COL_SIZE 50

int id[ROW_SIZE*COL_SIZE+2];
int connectGrid[ROW_SIZE*COL_SIZE+2];

//Check location of number in the grid
bool right(int a)
{
	if (a % ROW_SIZE == 0)
		return true;
	else
		return false;
}
bool left(int a)
{
	if ((a - 1) % ROW_SIZE == 0)
		return true;
	else
		return false;
}
bool bottom(int a)
{
	if (a >= ROW_SIZE*COL_SIZE-(ROW_SIZE-1) && a <= ROW_SIZE*COL_SIZE)
		return true;
	else
		return false;
}
bool top(int a)
{
	if (a > 0 && a <= ROW_SIZE)
		return true;
	else
		return false;
}
bool top_right(int a)
{
	if (top(a) && right(a))
		return true;
	else
		return false;
}
bool top_left(int a)
{
	if (top(a) && left(a))
		return true;
	else
		return false;
}
bool bottom_left(int a)
{
	if (bottom(a) && left(a))
		return true;
	else
		return false;
}
bool bottom_right(int a)
{
	if (bottom(a) && right(a))
		return true;
	else
		return false;
}
//----------------------------------------------------------------------------------------------------
int root(int p)
{
	while (connectGrid[p] != p)
	{
		connectGrid[p] = connectGrid[connectGrid[p]];
		p = connectGrid[p];
	}
	return p;
}
//----------------------------------------------------------------------------------------------------
bool Open(int x)//Is x uncovered/opened?
{
	if (id[x])
		return true;
	else
		return false;
}
//----------------------------------------------------------------------------------------------------
void mark(int a)//Mark box as open
{
	if (!Open(a))
		id[a] = 1;
}
//----------------------------------------------------------------------------------------------------
bool check_Connected(int p, int q)//Check if 2 boxes are connected in the connectGrid
{
	if (root(p) == root(q))
		return true;
	return false;
}
//----------------------------------------------------------------------------------------------------
void connect(int p, int q)//connect 2 boxes in connectGrid
{
	if (!check_Connected(p, q))
		connectGrid[root(p)] = connectGrid[root(q)];
}
//----------------------------------------------------------------------------------------------------
int main(int argc, _TCHAR* argv[])
{
	for (int i = 0; i <= ROW_SIZE * COL_SIZE; i++)//Intitialise the grids
	{
		connectGrid[i] = i;
		id[i] = 0;
	}
	id[0] = 1;
	id[ROW_SIZE*COL_SIZE + 1] = 1;
	int x = 1;
	int count = 0;
	char s[50];
	ifstream f("C://Users//Srivalli//Desktop//file7.txt");//Read file
	if (!f)
	{
		cout << "Error";
		return 0;
	}
	for (int j = 0; j < COL_SIZE; j++)
	{
		// reading the lines
		f >> s;
		for (int k = 0; k < ROW_SIZE; k++)
		{
			// reading the digits in each line
			int m = int(s[k]) - 48;
			if (m == 1)
			{
				//cout << "Random no : " << x << endl;
				mark(x);
				count++;
				if (top_left(x))
				{
					if (Open(x + 1))
						connect(x, x + 1);
					if (Open(x + ROW_SIZE))
						connect(x, x + ROW_SIZE);
				}
				else if (top_right(x))
				{
					if (Open(x - 1))
						connect(x, x - 1);
					if (Open(x + ROW_SIZE))
						connect(x, x + ROW_SIZE);
				}
				else if (bottom_left(x))
				{
					if (Open(x + 1))
						connect(x, x + 1);
					if (Open(x - ROW_SIZE))
						connect(x, x - ROW_SIZE);
				}
				else if (bottom_right(x))
				{
					if (Open(x - 1))
						connect(x, x - 1);
					if (Open(x - ROW_SIZE))
						connect(x, x - ROW_SIZE);
				}
				else if (top(x))
				{
					if (Open(x - 1))
						connect(x, x - 1);
					if (Open(x + 1))
						connect(x, x + 1);
					if (Open(x + ROW_SIZE))
						connect(x, x + ROW_SIZE);
				}
				else if (bottom(x))
				{
					if (Open(x - 1))
						connect(x, x - 1);
					if (Open(x + 1))
						connect(x, x + 1);
					if (Open(x - ROW_SIZE))
						connect(x, x - ROW_SIZE);
				}
				else if (left(x))
				{
					if (Open(x + 1))
						connect(x, x + 1);
					if (Open(x + ROW_SIZE))
						connect(x, x + ROW_SIZE);
					if (Open(x - ROW_SIZE))
						connect(x, x - ROW_SIZE);
				}
				else if (right(x))
				{
					if (Open(x - 1))
						connect(x, x - 1);
					if (Open(x + ROW_SIZE))
						connect(x, x + ROW_SIZE);
					if (Open(x - ROW_SIZE))
						connect(x, x - ROW_SIZE);
				}
				else
				{
					if (Open(x + 1))
						connect(x, x + 1);
					if (Open(x - 1))
						connect(x, x - 1);
					if (Open(x + ROW_SIZE))
						connect(x, x + ROW_SIZE);
					if (Open(x - ROW_SIZE))
						connect(x, x - ROW_SIZE);
				}
			}
			x++;
		}
	}
//----------------------------------------------------------------------------------------------------
	for (int p = 1; p <= ROW_SIZE; p++)//Check if first and last row are check_Connected
	{
		for (int q = ROW_SIZE * COL_SIZE - (ROW_SIZE - 1); q <= ROW_SIZE * COL_SIZE; q++)
		{
			if (check_Connected(p, q))
			{
				cout << "Connected" << endl;
				cout << "probability = " << (float)count / (2500.0) << endl;
				goto done;
			}
		}
	}
	cout << "Not Connected";
   done:return 0;
}