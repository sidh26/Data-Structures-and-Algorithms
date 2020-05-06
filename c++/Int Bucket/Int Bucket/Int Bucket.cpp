// Int Bucket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "math.h"
#include<fstream>
#define ARRAY_SIZE 500
#define maxNum 20000

using namespace std;

unsigned int WHICHBIT[32];
int count = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	for (int i = 0; i <32; i++)
	{
		WHICHBIT[i] = pow(2.0, i);

	}
	/*for (int i = 0; i < 32; i++)
	{
		cout << WHICHBIT[i] << endl;
	}*/
	int index, offset, x;
	unsigned int buk[625];
	for (int i = 0; i < 625; i++)
	{
		buk[i] = 0;
	}
	//memset(buk, 0, 625);

	ifstream f("C:/Users/Sidh Satam/Desktop/num.txt");

	if (!f)
	{
		cout << "Error";
		return 1;
	}
	for (int i = 1; i <= ARRAY_SIZE; i++)
	{
		f >> x;
		//scanf_s("%d", &x);
		cout<<x<<endl;
		index = (x - 1) / 32;
		offset = (x - 1) % 32;
		buk[index] = buk[index] | WHICHBIT[offset];
	}
	printf("\n Solution \n");

	for (int i = 1; i < maxNum; i++)
	{
		index = (i - 1) / 32;
		offset = (i - 1) % 32;
		if (buk[index] & WHICHBIT[offset])
		{
			printf("%d\n", i);
			count++;
		}
	}
	printf("count %d", count);
 	return 0;
}