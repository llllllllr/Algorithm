// heapSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;


void max_heapify(int data[], int start, int end) {
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end)
	{
		if (son + 1 <= end && data[son + 1] > data[son])
			son++;
		if (data[son] < data[dad])
			return;
		else
		{
			swap(data[son], data[dad]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int data[], int len) {
	for (int i = len / 2 - 1; i >= 0; i--)//从最后一个父节点开始从下往上
		max_heapify(data, i, len - 1);
	for (int i = len - 1; i > 0; i--)
	{
		swap(data[0], data[i]);
		max_heapify(data, 0, i - 1);
	}
}

int main() {
	int data[] = { 88,97,15,3,2,100,15,32,65 };
	int n = sizeof(data) / sizeof(int);
	heap_sort(data, n);
	for (int i = 0; i < n; i++)
		cout << data[i] << ' ';
	cout << endl;
	return 0;
}

