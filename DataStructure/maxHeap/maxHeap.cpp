#include<iostream>
using namespace std;
class MaxHeap
{
private:
	int *heapArray;
	int currentSize;
	int maxSize;
public:
	MaxHeap() {}
	MaxHeap(int *h, int c, int m) :heapArray(h), currentSize(c), maxSize(m) {}
	~MaxHeap() {}
	void dis();//打印
	void budildHeap();//建堆
	void remove(int pos);//删除指定下标元素
	void shiftDown(int left);//筛选法函数，参数left表示开始处理数组下标
	void shiftUp(int pos);//从pos位置开始调整，是序列成堆,序列已成堆
	void insert(int val);//插入val元素
	void moveMax();
};
void MaxHeap::budildHeap()
{
	for (int i = currentSize / 2 - 1;i >= 0;i--)
		shiftDown(i);
}
void MaxHeap::shiftDown(int left)
{
	int parent = left;
	int child = 2 * left + 1;

	int temp = heapArray[parent];
	while (child < currentSize)
	{
		if (child < (currentSize - 1) && (heapArray[child] < heapArray[child + 1]))
			child++;
		if (temp < heapArray[child])
		{
			heapArray[parent] = heapArray[child];
			parent = child;
			child = 2 * child + 1;
		}
		else
			break;
	}
	heapArray[parent] = temp;
}
void MaxHeap::shiftUp(int pos)
{
	for (;pos >= 1;pos--)
	{
		int parent = (pos - 1) / 2;
		int child = pos;
		while (parent >= 0 && child >= 1)
		{
			if (heapArray[parent] < heapArray[child])
			{
				heapArray[parent] = heapArray[child];
				child = parent;
				parent = (pos - 1) / 2;
			}
			else
				break;
		}
	}
}
void MaxHeap::dis()
{
	for (int i = 0;i < currentSize;i++)
		cout << heapArray[i] << " ";
}
void MaxHeap::remove(int pos)
{
	if (pos >= 0 && pos < currentSize)
	{
		heapArray[pos] = heapArray[currentSize - 1];
		currentSize--;
		if (heapArray[pos] > heapArray[(pos - 1) / 2])
			shiftUp(pos);
		else
			shiftDown(pos);
	}
}
void MaxHeap::insert(int val)
{
	if (currentSize < maxSize)
	{
		heapArray[currentSize] = val;
		currentSize++;
		shiftUp(currentSize - 1);
	}
}
void MaxHeap::moveMax()
{
	heapArray[0] = heapArray[currentSize - 1];
	currentSize--;
	shiftDown(0);
}
int main()
{
	int ele[20] = { 20,12,35,15,10,80,30,17,2,1};
	MaxHeap test(ele, 10, 20);
	test.budildHeap();
	test.dis();
	cout << endl;
	test.remove(3);
	test.dis();
	return 0;
}