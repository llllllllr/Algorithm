// insertionSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;


void insertionSort(int data[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i, target = data[j];
		while (j > 0 && data[j - 1] > target)
		{
			     //data[j] = data[--j];不行，因为先执行后面的--j，赋值的时候前面的j改变了
			data[j] = data[j - 1];
			j--;
		}
		data[j] = target;
	}
}

void showArr(int data[], int n)
{
	for (int i = 0; i < n; i++)
		cout << data[i] << "  ";
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	int* data = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		cin >> data[i];
	insertionSort(data, n);
	showArr(data, n);
	free(data);
    return 0;
}

