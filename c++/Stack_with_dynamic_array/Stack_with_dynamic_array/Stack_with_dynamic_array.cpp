// Stack_with_dynamic_array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "iostream"

using namespace std;

class DynCapacityStack
{
	char **str;
	int N;
	int capacity;
public:
	DynCapacityStack()
	{
		capacity = 1;
		str = new char * [1];
		N = 0;
	}
	bool isEmpty(){return N == 0;}
	void push(char *item)
	{
		if (N == length()) resize(2 * length());
		str[N] = (char *) malloc(strlen(item));
		strcpy(str[N++], item);
	}
	char *pop()
	{
		return str[--N];
	}
	int length(){return capacity;}
	void resize(int newsize)
	{
		char ** copy = new char * [newsize];
		capacity = newsize;
		for (int i = 0; i < N; i++)
			copy[i] = str[i];
		str = copy;
		cout << "resize called with : " << newsize << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	char s[10];
	DynCapacityStack stack;
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