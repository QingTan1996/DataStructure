#pragma once
/*
冒泡排序：
额外空间：O（n）
最好情况：O（n）
最坏情况：O（n^2）
平均情况：O（n^2）
稳定
*/
void bubbleSort(int *num, int n)
{
	for (int i = 0;i < n ;i++)
	{
		for (int j = 1;j < n-i;j++)
		{
			if (num[j] < num[j - 1])
			{
				int t = num[j];
				num[j] = num[j - 1];
				num[j - 1] = t;
			}
		}
	}
}
//改进冒泡
void advBubbleSort(int *num, int n)
{
	bool flag = true;
	for (int i = 0;i < n;i++)
	{
		for (int j = 1;j < n-i;j++)
		{
			if (num[j] < num[j - 1])
			{
				flag = false;
				int t = num[j];
				num[j] = num[j - 1];
				num[j - 1] = t;
			}
		}
		if (flag)
			break;
	}
}
/*
快速排序：
额外空间：O（n）
最好情况：O（nlogn）
最坏情况：O（n^2）
平均情况：O（nlogn）
不稳定
*/
int partition1(int *num, int start, int end)//第一种分割策略
{
	int pivot = num[start];//最左边为轴元素
	while (start < end)
	{
		while (start<end&&num[end]>pivot)
			end--;
		num[start] = num[end];
		while (start < end&&num[start] < pivot)
			start++;
		num[end]=num[start];
	}
	num[start] = pivot;
	return start;
}
int partition2(int *num, int start, int end)
{
	int pivot = num[start];
	while (start <= end)
	{
		while (start <= end&&num[start] <= pivot)
			start++;
		while (start <=end&&num[end] > pivot)
			end--;
		if (start < end)
		{
			int t = num[start];
			num[start] = num[end];
			num[end] = t;
			start++;
			end--;
		}
		
	}
	int temp = num[end];
	num[end] = num[start];
	num[start] = temp;
	return end;
}
void quikSort(int *num, int left,int right)
{
	if (left < right)
	{
		int pos = partition2(num, left, right);
		quikSort(num, left, pos - 1);//递归左边
		quikSort(num, pos + 1, right);//递归右边
	}
}