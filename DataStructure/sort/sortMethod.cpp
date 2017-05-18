#include<iostream>
#include"exchangeSort.h""
#include"insertSort.h"
#include"mergeSort.h"
#include"selectSort.h"
using namespace std;
void dis(int *num,int n)
{
	for (int i = 0;i < n;i++)
		cout << num[i] << " ";
	cout << endl;
}
int main()
{
	int num[6] = {32,18,65,48,27,9};
	dis(num, 6);
	//²åÈëÅÅÐò²âÊÔ
	//insertSort(num, 6);
	//inserWithDicSort(num, 6);
	//shellSort(num, 6);
	//Ñ¡ÔñÅÅÐò²âÊÔ
	//selectSort(num, 6);
	//heapSort(num, 6);
	//½»»»ÅÅÐò²âÊÔ
	//BubbleSort(num, 6);
	//advBubbleSort(num, 6);
	//quikSort(num, 0, 5);
	//¹é²¢ÅÅÐò²âÊÔ
	mergeSort(num,0,5);
	dis(num, 6);
	return 0;
}