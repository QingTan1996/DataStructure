#pragma once
/*
��ѡ������
����ռ䣺O��1��
��������O��n^2��
������O��n^2��
ƽ�������O��n^2��
���ȶ�
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
		if (k != i - 1)//����СԪ�ز��Ǵ�����λ��ʱ���ǵĻ����ö�
		{
			int t = num[k];
			num[k] = num[i-1];
			num[i - 1] = t;
		}
	}
}
/*
������
����ռ䣺O��1��
��������O��nlogn��
������O��nlogn��
ƽ�������O��nlogn��
���ȶ�
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
void buildHeap(int *num, int n)//����
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