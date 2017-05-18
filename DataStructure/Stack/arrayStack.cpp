#include<iostream>
using namespace std;
class arrayStack
{
	int top;
	int* stack;
	int maxSize;
public:
	arrayStack() 
	{
		top = -1;
		maxSize = 0;
		stack = NULL;
	}
	arrayStack(int size)
	{
		top = -1;
		maxSize = size;
		stack = new int[maxSize];
	}
	~arrayStack()
	{
		Del();
	}

	void dis();//��ӡ
	void Del();//ɾ��ջ
	void Push(int item);//ѹջ,���Ļ���������
	void PushAdvance(int item);//ѹջ��ջ�������ݻ�Ϊԭ������
	void Pop();//��ջ
	void creat(int num);//���ɲ���ջ

	bool isEmpty();//�Ƿ��
	bool isFull();//�Ƿ���
	bool Top(int& val);//ջ��Ԫ��
};
void arrayStack::dis()
{
	if (!isEmpty())
	{
		for (int i = top;i>-1;i--)
		{
			if (i != 0)
				cout << stack[i] << "->";
			else
				cout << stack[i] << endl;
		}
	}
	else
	{
		cout << "��ջ��" << endl;
	}
}
void arrayStack::Del()
{
	delete[] stack;
	maxSize = 0;
	top = -1;
}
bool arrayStack::isEmpty()
{
	return (top == - 1);
}
bool arrayStack::isFull()
{
	return (top == maxSize - 1);
}
void arrayStack::Pop()
{
	if (!isEmpty())
	{
		top -= 1;
	}
	else
	{
		cout << "��ջ��" << endl;
	}
}
void arrayStack::Push(int item)
{
	if (!isFull())
	{
		stack[top + 1] = item;
		top += 1;
	}
	else
	{
		cout << "��ջ��" << endl;
	}
}
void arrayStack::PushAdvance(int item)
{
	if (isFull())
	{
		maxSize *= 2;
		int* newStack = new int[maxSize];
		for (int i = 0;i < top + 1;i++)
		{
			newStack[i] = stack[i];
		}
		delete[] stack;
		stack = newStack;
	}
	stack[top + 1] = item;
	top += 1;
}
bool arrayStack::Top(int& val)
{
	if (!isEmpty())
	{
		val = stack[top];
		return true;
	}
	else
	{
		cout << "��ջ��" << endl;
		return false;
	}
}
void arrayStack::creat(int num)
{
	if (num > 0)
	{
		for (int i = 0;i < num;i++)
			Push(i+1);
	}
}
int main()
{
	arrayStack t(10);
	t.creat(10);
	t.dis();
	return 0;
}