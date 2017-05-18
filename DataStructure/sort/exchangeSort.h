#pragma once
/*
ð������
����ռ䣺O��n��
��������O��n��
������O��n^2��
ƽ�������O��n^2��
�ȶ�
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
//�Ľ�ð��
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
��������
����ռ䣺O��n��
��������O��nlogn��
������O��n^2��
ƽ�������O��nlogn��
���ȶ�
*/
int partition1(int *num, int start, int end)//��һ�ַָ����
{
	int pivot = num[start];//�����Ϊ��Ԫ��
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
		quikSort(num, left, pos - 1);//�ݹ����
		quikSort(num, pos + 1, right);//�ݹ��ұ�
	}
}