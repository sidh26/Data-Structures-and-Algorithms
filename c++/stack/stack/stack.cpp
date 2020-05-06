// stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "memory.h"

using namespace std;

class NodeString
{
public:
	char *str;
	NodeString *next;
	NodeString(char *item)
	{
		str = (char *)malloc (strlen(item)+1);
		strcpy(str, item);
		next = NULL;
	}
};


class Stack
{
	NodeString *first;
public:
	Stack()
	{
		first = NULL;
	}
	char * pop()
	{
		char *item = first->str;
		first = first->next;
		return item;
	}
	void push(char *strItem)
	{
		NodeString *oldfirst = first;
		first = new NodeString(strItem);
		first->next = oldfirst;
	}
	bool isEmpty()
	{ return first == NULL; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	char s[10];
	Stack stack;
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