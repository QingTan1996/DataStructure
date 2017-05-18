#include<iostream>
using namespace std;
class arrayQueue
{
	int front;
	int rear;
	int* queue;
	int maxSize;
public:
	arrayQueue() {}
	arrayQueue(int maxS) 
	{
		front = rear = 0;
		queue = new int[maxS+1];
		maxSize = maxS+1;
	}
	~arrayQueue()
	{
		del();
	}
	void dis();//��ӡ����Ԫ��
	void del();//ɾ��
	void push(int item);//item���
	void pop();//����
	void creat(int num);//����num��Ԫ�صĶ���
	void delByItem(int val);//��ֵɾ��
	void shift(int begin,int end);
	bool isEmpty();//�Ƿ��
	bool isFull();//�Ƿ��

	bool getFront(int &val);//��ȡ��ͷԪ��
	bool getRear(int &val);//��ȡ��βԪ��
	bool getEle(int& val, int pos);//��ȡָ��λ��Ԫ��
};
void arrayQueue::dis()
{
	if (!isEmpty())
	{
		for (int i = front;i != rear;i=(i+1)%maxSize)
		{
			if ((i + 1) % maxSize != rear)
			{
				cout << queue[i] << "->";
			}
			else
				cout << queue[i] << endl;
		}
	}
	else
		cout << "���пա�" << endl;
}
void arrayQueue::del()
{
	delete[] queue;
	front = rear = maxSize = 0;
}
void arrayQueue::push(int item)
{
	if (!isFull())
	{
		queue[rear] = item;
		rear =(rear+1)%maxSize;
	}
	else
	{
		cout << "��������" << endl;
	}
}
void arrayQueue::shift(int begin,int end)
{
	for (int i = 0;i < end - begin-1;i++)
	{
		queue[begin + i] = queue[begin + i + 1];
	}
	rear -= 1;
}
void arrayQueue::pop()
{
	if (!isEmpty())
	{
		front = (front +1) % maxSize;
	}
	else
	{
		cout << "���пա�" << endl;
	}
}
void arrayQueue::creat(int num)
{
	for (int i = 0;i < num;i++)
		push(i+1);
}
void arrayQueue::delByItem(int val)
{
	for (int t = front;t < rear;)
	{
		if (queue[t] == val)
		{
			if (t != front)
			{
				shift(t,rear);
			}
			else
			{
				front = (front + 1) % maxSize;	
				t = front;
			}

		}
		else
		{
			t += 1;
		}
	}
}
bool arrayQueue::isEmpty()
{
	return front == rear;
}
bool arrayQueue::isFull()
{
	return (rear + 1) % maxSize == front;
}
bool arrayQueue::getFront(int& val)
{
	if (!isEmpty())
	{
		val = queue[front];
		return true;
	}
	else
	{
		cout << "���пա�" << endl;
		return false;
	}
}
bool arrayQueue::getRear(int& val)
{
	if (!isEmpty())
	{
		val = queue[(rear-1+maxSize)%maxSize];
		cout << val << endl;
		return true;
	}
	else
	{
		cout << "���пա�" << endl;
		return false;
	}
}
bool arrayQueue::getEle(int& val,int pos)
{
	int length = rear - front;
	if (0 < pos&&pos <= length)
	{
		val = queue[pos - 1 + front];
		cout << val << endl;
		return true;
	}
	else
	{
		cout << "λ�ô���" << endl;
		return false;
	}
}
int main()
{
	int a;
	arrayQueue t(3);
	t.creat(3);
	t.getRear(a);
	t.dis();
	//t.getRear(a);
	return 0;
}