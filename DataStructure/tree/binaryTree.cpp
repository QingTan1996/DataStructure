#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class treeNode
{
public:
	treeNode* left;
	treeNode* right;
	char element;

	treeNode() {}
	treeNode(treeNode* l, treeNode* r, char e) :left(l), right(r), element(e) {}
};
class binaryTree
{
public:	
	treeNode* root;
	binaryTree()
	{
		root = NULL;
	}
	~binaryTree()
	{
		del(root);
		root = NULL;
	}

	void creat(treeNode* &b,char* ele,int index);
	void creat(treeNode* &r);
	void del(treeNode* root);//删除
	//深度优先遍历+递归
	void preOrder(treeNode* root);//前序遍历
	void inOrder(treeNode* root);//中序遍历
	void postOrder(treeNode* root);//后序遍历
	treeNode* getPar(treeNode* root, treeNode* current);//ele的父节点
	//层次优先遍历+非递归
	void preOr(treeNode* root);
	void inOr(treeNode* root);
	void postOr(treeNode* root);
	void levelOrder(treeNode* root);//层次遍历（广度优先）
	treeNode* getLeftChild(treeNode* current);//当前结点左孩子
	treeNode* getRightChild(treeNode* current);//当前结点右孩子
	treeNode* getParents(treeNode* current);//当前结点父亲

	void Mirror(treeNode *r);
};
void binaryTree::creat(treeNode* &b,char* ele,int index)
{
	if (ele[index] != '#'&&ele[index] != '/0')
	{
		b = new treeNode(NULL,NULL,ele[index]);
		creat(b->left, ele,index);
		creat(b->right,ele,index);
	}
	else
	{
		b = NULL;
	}
}
void binaryTree::creat(treeNode* &r)
{
	char str;
	if ((str =getchar())== '#')
		r = NULL;
	else
	{
		r = new treeNode(NULL,NULL,str);
		creat(r->left);
		creat(r->right);
	}
}
void binaryTree::del(treeNode* root)
{
	if (root)
	{
		treeNode* leftNode = root->left, *rightNode = root->right;
		delete(root);
		del(leftNode);
		del(rightNode);
	}
}
void binaryTree::preOrder(treeNode* root)
{
	if (root)
	{
		cout << root->element;
		preOrder(root->left);
		preOrder(root->right);
	}
}
void binaryTree::inOrder(treeNode* root)
{
	if (root)
	{
		inOrder(root->left);
		cout << root->element;
		inOrder(root->right);
	}
}
void binaryTree::postOrder(treeNode* root)
{
	if (root)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->element;
	}
}
treeNode* binaryTree::getPar(treeNode* root,treeNode* current)
{
	if (!root)
		return NULL;
	if (root->left == current || root->right == current)
		return root;
	else
	{
		treeNode* l=getPar(root->left,current);
		treeNode* r=getPar(root->right, current);
		return l == NULL ? r : l;
	}
	
}
void binaryTree::preOr(treeNode* root)
{
	treeNode* t = root;
	stack<treeNode*> node;
	while (!node.empty() || t)
	{
		if (t)
		{
			cout << t->element;
			if (t->right)
				node.push(t->right);
			t = t->left;
		}
		else
		{
			t = node.top();
			node.pop();
		}
	}
}
void binaryTree::inOr(treeNode* root)
{
	treeNode* t = root;
	stack<treeNode*> node;
	while (!node.empty() || t)
	{
		if (t)
		{
			node.push(t);
			t = t->left;
		}
		else
		{
			t = node.top();
			node.pop();
			cout << t->element;
			t = t->right;
		}
	}
}
void binaryTree::postOr(treeNode* root)
{
	treeNode* pre = root,*point=root;
	stack<treeNode*> node;
	while (point)
	{
		for (;point->left!=NULL;point = point->left)
			node.push(point);
		while (point != NULL && (point->right == NULL || point->right == pre))
		{
			cout << point->element;
			pre = point;
			if (node.empty())
				return;
			point = node.top();
			node.pop();
		}
		node.push(point);
		point = point->right;
	}
}
void binaryTree::levelOrder(treeNode* root)
{
	if (root)
	{
		queue<treeNode* > node;
		treeNode* t = NULL;
		node.push(root);
		while (!node.empty())
		{
			t = node.front();
			cout << t->element;
			node.pop();
			if (t->left)
				node.push(t->left);
			if (t->right)
				node.push(t->right);
		}
	}
}
treeNode* binaryTree::getLeftChild(treeNode* current)
{
	treeNode* t = NULL;
	if (current)
	{
		t = current->left;
	}
	return t;
}
treeNode* binaryTree::getRightChild(treeNode* current)
{
	treeNode* t = NULL;
	if (current)
	{
		t = current->right;
	}
	return t;
}
treeNode* binaryTree::getParents(treeNode* current)
{
	treeNode* t = NULL;
	if(current!=root&&current)
	{
		queue<treeNode*> node;
		node.push(root);
		while (!node.empty())
		{
			t = node.front();
			node.pop();
			if (t->left)
			{
				if (t->left != current)
				{
					node.push(t->left);
				}
				else
				{
					break;
				}
			}
			if (t->right)
			{
				if (t->right != current)
				{
					node.push(t->right);
				}
				else
				{
					break;
				}
			}

		}
	}
	return t;
}
void binaryTree::Mirror(treeNode* r)
{
	if (r != NULL)
	{
		treeNode *temp = r->left;
		r->left = r->right;
		r->right = temp;
	}
	Mirror(r->left);
	Mirror(r->right);
}
int main()
{
	/*
	           A
			B     E
		 C      D    G
		      F   H
		ABC###EDF##H##G##
	*/
	int num = 0;
	binaryTree t;
	treeNode* n = NULL;
	cout << "输入前序遍历（叶子节点后输入“#”）：" << endl;
	t.creat(t.root);
	t.levelOrder(t.root);
	/*cout << "递归前序：" << endl;
	t.preOrder(t.root);
	cout << endl;
	cout << "递归中序：" << endl;
	t.inOrder(t.root);
	cout << endl;
	cout << "递归后序：" << endl;
	t.postOrder(t.root);
	cout << endl;
	cout << "层次遍历：" << endl;
	t.levelOrder(t.root);
	cout << endl;
	cout << "非递归前序：" << endl;
	t.preOr(t.root);
	cout << endl;
	cout << "非递归中序：" << endl;
	t.inOr(t.root);
	cout << endl;
	cout << "非递归后序：" << endl;
	t.postOr(t.root);
	cout << endl;
	n = t.root->right->left;
	if(t.getLeftChild(n))
		cout <<n->element<<"的左子节点："<<t.getLeftChild(n)->element<<endl;
	if(t.getRightChild(n))
		cout << n->element << "的右子节点：" << t.getRightChild(n)->element << endl;
	if(t.getPar(t.root,n))
		cout << n->element << "的父节点：" << t.getPar(t.root,n)->element << endl;*/
	cout << endl;
	t.Mirror(t.root);
	t.levelOrder(t.root);
	return 0;
}
