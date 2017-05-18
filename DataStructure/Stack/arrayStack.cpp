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

	void dis();//´òÓ¡
	void Del();//É¾³ýÕ»
	void Push(int item);//Ñ¹Õ»,ÂúµÄ»°²»×ö²Ù×÷
	void PushAdvance(int item);//Ñ¹Õ»£¬Õ»ÂúÀ©´óÈÝ»ýÎªÔ­À´Á½±¶
	void Pop();//³öÕ»
	void creat(int num);//Éú³É²âÊÔÕ»

	bool isEmpty();//ÊÇ·ñ¿Õ
	bool isFull();//ÊÇ·ñÂú
	bool Top(int& val);//Õ»¶¥ÔªËØ
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
		cout << "¿ÕÕ»¡£" << endl;
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
		cout << "¿ÕÕ»¡£" << endl;
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
		cout << "ÂúÕ»¡£" << endl;
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
		cout << "¿ÕÕ»¡£" << endl;
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