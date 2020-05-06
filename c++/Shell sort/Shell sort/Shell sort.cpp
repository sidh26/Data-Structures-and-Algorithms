// Shell sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <array>
#include <iostream>
#include <ctime>
using namespace std;
int temp = 0;
int arr[200000];
void merge(int arr[], int l, int r, int m)
{
	int n1 = m-l;
	int n2 = r-m;
	int * L = new int [n1];
	int * R = new int[n2];
	for (int i = 0; i < n1; i++)
		L[i] = arr[i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + j];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
		k++;
	}
}
void merge_sort(int arr[], int l, int r)
{
	if (l < r)
	{
		double m = (l + r) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m+1, r);
		merge(arr, l, r, m);
	}
}
int compare(int m, int n)
{
	if (m == n) return 0;
	else if (m < n) return 1;
	else return -1;
}

void shell_sort()
{
	//char arr[] = { 'M','I','T','A','L','I','N','I','D','H','I','A','M','R','U','S','H','A','G','A','Y','A','T','H','R','I' };
	int N = sizeof(arr) / sizeof(arr[0]);
	int h = 1;
	while (h < N / 3)
		h = h * 3 + 1;
	while (h >= 1)
	{
		//cout << h << " - sort" << endl;
		for (int i = h; i < N; i++)
		{
			int temp = arr[i];
			int j;
			for (j = i - h; j >= h; j -= h)
			{
				if (arr[j]<arr[j - h])
				{
					arr[j+h]=arr[j];
				}  
			}
			arr[j+h] = temp;
			/*for (int s = 0; s < N; s++)
				cout << arr[s] << " ";
			cout << endl;*/
		}
		cout << endl;
		h = h / 3;
	}
}

void selection_sort(int arr[])
{
	for(int i=0;i<9;i++)
	{
		int min_index = i;//To store the minimum value
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[j] < arr[min_index] )
				min_index = j;
		}   
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
}
void insertionSort(int arr[])
{
	for (int i = 1; i<10; ++i)
	{
		int m = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > m)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = m;
	}
}

int main()
{
	for (int i = 0; i < 200000; i++)
	{
		arr[i] = rand();
	}
	double start=clock();
	cout<<start<<endl;
	//merge_sort(arr, 0, 10);
	shell_sort();
	cout<<(clock()-start)/CLOCKS_PER_SEC;
	/*int arr[] = { 90, 89, 88, 87, 86, 85, 84, 83, 82, 81};
	insertionSort(arr);*/
	for (int i = 0; i < 10; i++)
	cout << arr[i] << "\n";
	return 0;
}