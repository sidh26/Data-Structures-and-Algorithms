// stack_with_array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "iostream"

using namespace std;

class FixedCapacityStack
{
	char **str;		// char str[capacity = 10][10];
	int N;
public:
	FixedCapacityStack(int capacity)
	{
		str = new char * [capacity];
		N = 0;
	}
	bool isEmpty(){return N == 0;}
	void push(char *item)
	{
		str[N] = (char *) malloc(strlen(item)+1);
		strcpy(str[N], item);
		N++;
	}
	char *pop()
	{
		return str[--N];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	char s[10];
	FixedCapacityStack stack(10);
	cin >> s;
	while (s != NULL)
	{
		if (!strcmp(s, "-"))
			cout << stack.pop() << " ";
		else stack.push(s);
		cin >> s;
	}

	return 0;
}