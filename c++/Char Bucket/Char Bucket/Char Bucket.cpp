// Char Bucket.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <fstream>
//16 no from 1 to 24, 3buks
int ofar[8]={1,2,4,8,16,32,64,128};
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream f("C://Users//Sidh Satam//Desktop//NOS.txt");
	if (!f)
	{
		cout << "Error";
		return 0;
	}
	char buk[2500];
	int i,ind,ofs;
	int x;
	memset(buk, 0, 2500);
	
	for (i = 0; i < 1000; ++i) 
	{
		f>>x;
		ind = (x - 1) / 8;
		ofs = (x - 1) % 8;

		buk[ind]=buk[ind]|ofar[ofs];
		//std::cout<<buk[ind]<<std::endl;
	}
	int c=0;
	for (i = 0; i < 2500; ++i) 
	{
		//std::cout<<buk[i]<<std::endl;
		for(int j=0; j<8; j++)
		{
			if (buk[i]&ofar[j])
			{
				//and with 1 in bucket array
				cout<< (i*8)+j+1<<endl;
				c++;
			}
		}
	}
	cout<<"Number of Numbers"<<c;
	return 0;
}

