#include<iostream>
using namespace std;
class listNode//������
{
public:
	int element;
	listNode *next;
	//���캯��
	listNode() {}
	listNode(int ele, listNode *l) 
	{
		element = ele;
		next = l;
	}
};
class listArray//������
{	
	listNode* head;//ͷ���ָ��
public:	
	//���졢��������
	listArray() {}
	listArray(listNode *h)
	{
		head = h;
	}
	~listArray()
	{
		delete head;
	}
	void creat(int num);//����num����������
	void insert(listNode* node,int pos);//��һ�������뵽posλ��
	void del();//ɾ�����нڵ�
	void trans();//ת��
	void dis();//�����ӡ
	void delByItem(int val);//��ֵɾ�����
	void disDes(listNode* h);//�����ӡ

	int length();//������

	listNode* getHead();//��������ͷ���
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
		cout << "����λ����Ч��" << endl;
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
		cout << "������" << endl;
}
void listArray::delByItem(int val)//����ɾ���ظ�ֵ
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
//����
int main()
{
	listArray test;
	test.creat(10);
	test.dis();
	test.disDes(test.getHead());
	return 0;
}