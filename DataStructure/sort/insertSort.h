#pragma once
/*
简单插入排序：
所需额外空间：O（1）
最好情况：O(n)
最坏情况：O（n^2）
平均情况：O（n^2）
稳定
*/
void insertSort(int *num, int n)
{
	for (int i = 1;i < n;i++)
	{
		int temp = num[i];
		int j = i - 1;
		while (j >= 0 && num[j] > temp)
		{
			num[j + 1] = num[j];
			j--;
		}
		num[j+1] = temp;
	}
}
/*
折半插入排序：
所需额外空间：O（1）
最好情况：O（nlogn）
最坏情况：O（n^2）
平均情况：O（n^2）
稳定
*/
void inserWithDicSort(int *num, int n)
{
	for (int i = 1;i < n;i++)
	{
		int temp = num[i];
		int left=0,mid,right=i-1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (num[mid]>temp)
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (int j = i - 1;j>= left;j--)
			num[j + 1] = num[j];
		num[left] = temp;
	}
}
/*
shell排序：
额外空间：0
最好情况：O（nlogn）
最坏情况：O（n^2）
平均情况：O（n^1.3）
不稳定
*/
void shellSort(int *num, int n)
{
	for (int len = n / 2;len >= 1;len /= 2)//划定步长
	{
		for (int i = 0;i < len;i++)//划分的子序列第一个元素
		{
			for (int j = i + len;j < n;j += len)//子序列第二个元素以及之后
			{
				int temp = num[j];
				int k = j - len;
				while (k >= i && num[k] > temp)
				{
					num[k + len] = num[k];
					k -= len;
				}
				num[k + len] = temp;
			}
		}
	}
}