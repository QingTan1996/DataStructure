#include<iostream>
using namespace std;
class queNode
{
public:
	int element;
	queNode* next;

	queNode() {}
	queNode(int e, queNode* n) :element(e), next(n) {}
};
class queList
{
	
public:
	queNode* front;
	queNode* rear;
	int length;

	queList() {}
	~queList()
	{
		del();
	}
	
	void dis();//��ӡ����Ԫ��
	void del();//ɾ��
	void push(int item);//item���
	void pop();//����
	void creat(int num);
	void delByItem(int val);
	bool isEmpty();//�Ƿ��

	bool getFront(int &val);//��ȡ��ͷԪ��
	bool getRear(int &val);//��ȡ��βԪ��
	bool getEle(int& val,int pos);//��ȡָ��λ��Ԫ��
	
	
};
void queList::dis()
{
	if (!isEmpty())
	{
		queNode* t = front;
		while (t != NULL)
		{
			if (t->next != NULL)
			{
				cout << t->element<< "<-";
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
		cout << "���пա�" << endl;
	}
}
void queList::del()
{
	if (!isEmpty())
	{
		while (front != NULL)//ÿ��ѭ����ʼʱ��t��front��ֵ��ȣ������ڷ��ʿ�ָ������
		{
			rear = front;
			front = front->next;
			delete(rear);
		}
		rear = NULL;
		length = 0;
	}
}
void queList::push(int item)
{
	queNode* newNode = new queNode(item, NULL);
	if (length != 0)
	{
		rear->next = newNode;
		rear = newNode;
	}
	else
	{
		front = rear = newNode;
	}
	length += 1;
}
void queList::pop()
{
	if (!isEmpty())
	{
		queNode* t = front;
		front = front->next;
		length -= 1;
		if (length == 0)
			rear = NULL;
		delete(t);
	}
}
void queList::creat(int num)
{
	if (num > 0)
	{
		for (int i = 1;i <= num;i++)
			push(i);
	}
}
void queList::delByItem(int val)
{
	for (queNode**t = &front;*t;)
	{
		queNode* n = *t;
		if (n->element == val)
		{
			*t = n->next;
			delete(n);
		}
		else
		{
			t = &n->next;
		}	
	}
}
bool queList::isEmpty()
{
	return (length == 0);
}
bool queList::getFront(int& val)
{
	if (!isEmpty())
	{
		val = front->element;
		return true;
	}
	else
		return false;
}
bool queList::getRear(int& val)
{
	if (!isEmpty())
	{
		val = rear->element;
		return true;
	}
	else
		return false;
}
bool queList::getEle(int& val, int pos)
{
	if (0 < pos&&pos <= length)
	{
		queNode* t = front;
		for (int i = 1;i < pos;i++)
			t = t->next;
		val = t->element;
		return true;
	}
	else
	{
		cout << "λ�ô���" << endl;
		return false;
	}
}
//int main()
//{
//	queList t;
//	t.creat(10);
//	t.dis();
//	t.delByItem(11);
//	t.dis();
//	return 0;
//}