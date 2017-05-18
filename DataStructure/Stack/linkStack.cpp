#include<iostream>
using namespace std;
class stackNode
{
public:
	int element;
	stackNode* next;

	stackNode() {}
	stackNode(int e, stackNode* n) :element(e), next(n) {}
};
class linkStack
{
	stackNode* top;
	int length;
public:
	~linkStack()
	{
		del();
	}

	void del();//���ջ
	void dis();//��ӡ
	void pop();//��ջ
	void push(int item);//��ջ
	void creat(int num);//���ɲ���ջ

	bool isEmpty();
	bool Top(int& val);
};
void linkStack::del()
{
	if (!isEmpty())
	{
		stackNode* t = top;
		while (t != NULL)
		{
			top = top->next;
			delete t;
			t = top;
		}
		length = 0;
	}
}
void linkStack::dis()
{
	if (!isEmpty())
	{
		stackNode* t = top;
		while (t!= NULL)
		{
			if (t->next != NULL)
			{
				cout << t->element << "->";
			}
			else
			{
				cout << t->element << endl;
			}
			t = t->next;
		}
	}
	else
	{
		cout << "��ջ��" << endl;
	}
}
void linkStack::pop()
{
	if (!isEmpty())
	{
		top = top->next;
		length -= 1;
	}
	else
	{
		cout << "�ӿա�" << endl;
	}
}
void linkStack::push(int item)
{
	stackNode* newNode = new stackNode(item,NULL);
	newNode->next = top;
	top = newNode;
	length += 1;
}
void linkStack::creat(int num)
{
	if (num > 0)
	{
		for (int i = 0;i < num;i++)
			push(i+1);
	}
}
bool linkStack::isEmpty()
{
	return (length==0);
}
bool linkStack::Top(int& val)
{
	if (!isEmpty())
	{
		val = top->element;
		return true;
	}
	else
	{
		cout << "ջ�ա�" << endl;
		return false;
	}
}
int main()
{
	linkStack t;
	t.creat(10);
	t.dis();
	return 0;
}