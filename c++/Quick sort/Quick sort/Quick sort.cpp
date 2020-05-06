// Quick sort.cpp : Defines the entry point for the console application.
//


#include <iostream>


using namespace std;
int a[10] = {4,5,3,7,8,5,1,0,9,2};

void quick( int * p, int l, int u);
int main()
{
	int n;
	int * p;

	cin>>n;
	p = new int [n];
	for (int i= 0; i <n; i++)
		cin>>p[i];
	quick(p, 0, n-1);
	cout<<endl;
	for(int i =0; i <n; i++)
		cout<<p[i]<<" ";
	return 0;
}

void quick(int * p, int l, int u)
{
	if (l<u)
	{
		int i = l+1;
		int j = u;
		int pi = l;
		while (i < j)
		{
			while ((p[i]<p[pi])&&(i<u))
				i++;
			while((p[j]>p[pi])&&(l<j))
				j--;
			if(i<j)
			{
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
				i++;
				j--;
			}
		}
		if(p[pi]>p[j])
		{
			int temp = p[pi];
			p[pi] = p[j];
			p[j] = temp;
		}
		cout<<"pivot "<<pi<<endl;
		cout<<"i "<<i<<endl;
		cout<<"j "<<j<<endl;
		for(int i =0; i <u; i++)
			cout<<p[i]<<" ";
		cout<<endl;
		quick(p, l, j-1);
		quick(p, j+1, u);
	}
}