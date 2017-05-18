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
	
	void dis();//打印队列元素
	void del();//删除
	void push(int item);//item入队
	void pop();//出队
	void creat(int num);
	void delByItem(int val);
	bool isEmpty();//是否空

	bool getFront(int &val);//读取队头元素
	bool getRear(int &val);//读取队尾元素
	bool getEle(int& val,int pos);//获取指定位置元素
	
	
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
		cout << "队列空。" << endl;
	}
}
void queList::del()
{
	if (!isEmpty())
	{
		while (front != NULL)//每轮循环开始时，t与front的值相等，不存在访问空指针内容
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
		cout << "位置错误。" << endl;
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