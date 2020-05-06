// Queue Dynamic Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "iostream"

using namespace std;

class DynCapacityQueue
{
	char **str;
	int start;
	int end;
	int capacity;
public:
	DynCapacityQueue()
	{
		str = new char * [1];
		start = 0;
		end = 0;
		capacity = 1;
	}

	bool isEmpty(){return end == 0;}

	void queue(char *item)
	{
		if (end == length()) 
			resize(2 * length());
		str[end] = (char *) malloc(strlen(item)+1);
		strcpy(str[end++], item);
		//cout<<"Queued: "<<item<<endl;
	}

	char * dequeue()
	{
		char * temp = str[start++];
		if((end-start)*4 == length() && end >= 2)
		{
			end = length() / 4;
			desize(length()/2, start);
			start = 0;
		}
		return temp;
	}

	int length(){return capacity;}

	void resize(int newsize)
	{
		char ** copy = new char * [newsize];
		capacity = newsize;
		for (int i = 0; i < end; i++)
			copy[i] = str[i];
		str = copy;
		cout << "resize called with : " << newsize << endl;
	}

	void desize(int newsize, int start)
	{
		char ** copy = new char * [newsize];
		for (int i = 0; i < length()/4; i++)
			copy[i] = str[i + start];
		capacity = newsize;
		str = copy;
		cout << "desize called with : " << newsize << endl;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	char s[10];
	DynCapacityQueue queue;
	cin >> s;
	while (s != NULL && (strcmpi(s, "quit")))
	{
		if (!strcmp(s, "-"))
			cout <<"Dequeued: "<< queue.dequeue() << endl;
		else queue.queue(s);
		cin >> s;
	}
	return 0;
}