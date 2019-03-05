
#include "stdafx.h"
#include<iostream>
using namespace std;



void	quickSort(int data[], int left, int right)
{
	if (left >= right)
		return;

	int i = left, j = right;
	int key = data[left];
	while (i < j)
	{
		while (i<j && data[j]>key)
			j--;
		if(i<j)
		data[i++] = data[j];
		while (i < j && data[i] < key)
			i++;
		if (i<j)
		data[j--] = data[i];
	}
		data[i] = key;
	
	quickSort(data, left, i - 1);
	quickSort(data, i + 1, right);

}

void show(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}
int main()
{

	int n;
	cin >> n;
	int* data = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		cin >> data[i];
	quickSort(data, 0, n - 1);
	show(data, n);
    return 0;
}

