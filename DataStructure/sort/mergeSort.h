#pragma once
/*
归并排序：
额外空间：O（n）
最好情况：O（nlogn）
最坏情况：O（nlogn）
平均情况：O（nlogn）
稳定
*/
void merge(int *num, int start, int mid, int end)
{
	int i, j, k;
	int lenL = mid - start + 1, lenR = end - mid;

	int *left = new int[lenL];
	int *right = new int[lenR];
	
	for (i = 0;i < lenL;i++)
		left[i] = num[start+i];
	for (i = 0;i < lenR;i++)
		right[i] = num[i+mid+1];
	i = j = 0;
	for (k= start;k < end;k++)
	{
		if (lenL == i || lenR == j)
			break;
		if (left[i] <= right[j])
			num[k] = left[i++];
		else
			num[k] = right[j++];
	}
	while (i < lenL)
		num[k++] = left[i++];
	while (j < lenR)
		num[k++] = right[j++];
	delete[] left;
	delete[] right;
}
void mergeSort(int *num, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(num, start, mid);
		mergeSort(num, mid + 1, end);
		merge(num, start, mid, end);
	}
}