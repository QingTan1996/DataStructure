#pragma once
/*
�򵥲�������
�������ռ䣺O��1��
��������O(n)
������O��n^2��
ƽ�������O��n^2��
�ȶ�
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
�۰��������
�������ռ䣺O��1��
��������O��nlogn��
������O��n^2��
ƽ�������O��n^2��
�ȶ�
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
shell����
����ռ䣺0
��������O��nlogn��
������O��n^2��
ƽ�������O��n^1.3��
���ȶ�
*/
void shellSort(int *num, int n)
{
	for (int len = n / 2;len >= 1;len /= 2)//��������
	{
		for (int i = 0;i < len;i++)//���ֵ������е�һ��Ԫ��
		{
			for (int j = i + len;j < n;j += len)//�����еڶ���Ԫ���Լ�֮��
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