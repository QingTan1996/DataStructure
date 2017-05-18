#include<iostream>
using namespace std;
int search(int *num, int n, int key)
{
	int i;
	for (i = 0;i < n;i++)
	{
		if (num[i] == key)
			break;
	}
	if (i == n - 1 && num[i] != key)
		return -1;
	else
		return i;
}
int biSearch(int *num, int n, int key)
{
	int left = 0, right = n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (num[mid] > key)
			right = mid - 1;
		else if (num[mid] < key)
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}
int main()
{
	int num[10] = { 0,1,2,3,4,5,6,7,8,9};
	cout << search(num, 10, 5) << endl;
	cout << biSearch(num, 10, 4) << endl;
	return 0;
}