// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void merge(int data[], int left, int mid, int right,int temp[])
{
	int i = left, j = mid+1, m = mid, n = right,k=0;
	
	while (i <=m && j <= n)//最小合并时是否能够成功，等于号是否存在
	{
		if (data[i] < data[j])
			temp[k++] = data[i++];
		else
			temp[k++] = data[j++];
	}
	while (i <= m)
		temp[k++] = data[i++];
	while (j <= n)
		temp[k++] = data[j++];
	for (int i = 0; i < right - left + 1; i++)
	{
		data[left + i] = temp[i];
	
	}
}

void Sort(int data[], int left, int right, int temp[])
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		Sort(data, left, mid, temp);
		Sort(data, mid + 1, right, temp);
		merge(data, left, mid, right, temp);
	}
}
int main()
{
	int n;
	cin >> n;
	int* data = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		cin >> data[i];
	int* temp = new int[n];
	Sort(data, 0, n-1 , temp);
	for (int i = 0; i < n; i++)
		cout << data[i] << "  ";
	cout << endl;
	delete[]temp;
    return 0;
}

