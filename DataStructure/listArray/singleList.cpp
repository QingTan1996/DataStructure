#include<iostream>
using namespace std;
class listNode//链表结点
{
public:
	int element;
	listNode *next;
	//构造函数
	listNode() {}
	listNode(int ele, listNode *l) 
	{
		element = ele;
		next = l;
	}
};
class listArray//链表类
{	
	listNode* head;//头结点指针
public:	
	//构造、析构函数
	listArray() {}
	listArray(listNode *h)
	{
		head = h;
	}
	~listArray()
	{
		delete head;
	}
	void creat(int num);//创建num个结点的链表
	void insert(listNode* node,int pos);//把一个结点插入到pos位置
	void del();//删除所有节点
	void trans();//转置
	void dis();//正序打印
	void delByItem(int val);//按值删除结点
	void disDes(listNode* h);//倒序打印

	int length();//链表长度

	listNode* getHead();//返回链表头结点
};
void listArray::creat(int num)
{
	if (num > 0)
	{
		listNode* firstNode = new listNode(1,NULL);
		listNode* temp = firstNode;
		head = firstNode;
		for (int i = 1;i < num;i++)
		{
			listNode* newNode = new listNode(i+1,NULL);
			temp->next = newNode;
			temp = newNode;
		}
	}
}
void listArray::insert(listNode* node,int pos)
{
	int length = this->length();
	if (pos == 0)
	{
		node->next = head;
		this->head = node;
	}
	else if (pos > 0 && pos <= length)
	{
		listNode* t = head;
		for (int i = 1;i < pos;i++)
		{
			t = t->next;
		}
		node->next = t->next;
		t->next = node;
	}
	else
	{
		cout << "插入位置无效。" << endl;
	}
}
void listArray::del()
{
	listNode* t = head;
	while (head != NULL)
	{
		t = t->next;
		delete(head);
		head = t;
	}                                                                                                                                                                                                                                                                                                                                            
}
void listArray::trans()
{
	listNode* p = NULL, *q = head;
	while (head!=NULL)
	{
		q = q->next;
		head->next = p;
		p = head;
		head = q;
	}
	head = p;
}
void listArray::dis()
{
	listNode* t = head;
	if (head !=NULL)
	{
		while (t != NULL)
		{
			if (t->next != NULL)
				cout << t->element << "->";
			else
				cout << t->element << endl;
			t = t->next;
		}
	}
	else
		cout << "空链表。" << endl;
}
void listArray::delByItem(int val)//可以删除重复值
{
	listNode* t = head,*p=head;
	while (t)
	{
		if (t->element == val)
		{
			if (p == t)
			{
				head = head->next;
				delete(p);
				p = head;
				t = head;
			}
			else
			{
				p->next = t->next;
				delete(t);
				t = p->next;
			}
		}
		else
		{
			p = t;
			t = t->next;
		}
	}
}
void listArray::disDes(listNode* h)
{
	if (h != NULL)
	{
		if (h->next != NULL)
		{
			disDes(h->next);
		}
		if (h != head)
			cout << h->element << "->";
		else
			cout << h->element;
	}
}
int listArray::length()
{
	int length = 0;
	listNode* t = head;
	while (t != NULL)
	{
		length += 1;
		t = t->next;
	}
	return length;
}
listNode* listArray::getHead()
{
	return head;
}
//测试
int main()
{
	listArray test;
	test.creat(10);
	test.dis();
	test.disDes(test.getHead());
	return 0;
}