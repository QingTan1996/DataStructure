#pragma once
/*
简单选择排序：
额外空间：O（1）
最好情况：O（n^2）
最坏情况：O（n^2）
平均情况：O（n^2）
不稳定
*/
void selectSort(int *num, int n)
{
	for (int i = 1;i < n;i++)
	{
		int k = i - 1;
		for (int j = i;j < n;j++)
		{
			if (num[k] > num[j])
				k = j;
		}
		if (k != i - 1)//当最小元素不是带排序位置时，是的话不用动
		{
			int t = num[k];
			num[k] = num[i-1];
			num[i - 1] = t;
		}
	}
}
/*
堆排序：
额外空间：O（1）
最好情况：O（nlogn）
最坏情况：O（nlogn）
平均情况：O（nlogn）
不稳定
*/
void siftDown(int *num, int pos, int n)
{
	int child = 2 * pos + 1;
	int parent = pos;
	int temp = num[parent];
	while (child<n)
	{
		if (child < (n - 1) && num[child] < num[child + 1])
			child += 1;
		if (num[child] > num[parent])
		{
			num[parent] = num[child];
			parent = child;
			child = 2 * child + 1;
		}
		else
			break;
	}
	num[parent] = temp;
}
void buildHeap(int *num, int n)//建堆
{
	for (int i = n / 2 - 1;i >= 0;i--)
	{
		siftDown(num,i,n);
	}
}
void heapSort(int *num, int n)
{
	buildHeap(num, n);
	for (int i = n - 1;i > 0;i--)
	{
		int temp = num[i];
		num[i] = num[0];
		num[0] = temp;
		siftDown(num, 0, i);
	}
}