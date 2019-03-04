// shellSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void insertionSort(int data[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int j = i+1;
		int target = data[j];
		while (j >0 && data[j-1] > target)
		{
			data[j] = data[j-1];
			j--;
		}
		data[j] = target;
	}
}

int main()
{
	int n;
	cin >> n;
	int* data = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		cin >> data[i];
	insertionSort(data, n); 
	for (int i = 0; i < n; i++)
		cout << data[i] << "  ";
	cout << endl;
    return 0;
}

