#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
#include<utility>
#include<vector>

#define Status int

using namespace std;
/*
我写这个文件是为了今后测试所有树算法。
*/
typedef struct Node
{
	int key;
	struct Node *left,*right;
}Node,*Tree;

void InOrder(Node *bt,void (*f)(Node *))
{
	if(bt==NULL)
		return;
	stack<Node *> s;
	Node *p=bt;

	while(!s.empty()||p)
	{
		while(p)
		{
			s.push(p);
			p=p->left;
		}
		if(!s.empty())
		{
			p=s.top();
			s.pop();
			f(p);
			p=p->right;
		}
	}
}

void InOrder_dg(Node *bt,void (*f)(Node *))
{	
	if(bt==NULL)
		return;
	InOrder_dg(bt->left,f);
	f(bt);
	InOrder_dg(bt->right,f);
}


void BFS(Tree &t,void (*f)(Node *))
{
	if(!t)
		return;
	queue<Node *> q;
	Node *it=t;
	q.push(it);
	while(!q.empty())
	{
		it=q.front();
		q.pop();
		f(it);
		if(it->left)
			q.push(it->left);
		if(it->right)
			q.push(it->right);
	}
}

void appendTree(Tree &t,int val)
{
	queue<Node *> q;
	Node *p=NULL,*a=NULL,*b=NULL;
	int counter=1;
	t=new Node;
	t->key=0;
	t->left=NULL;
	t->right=NULL;
	q.push(t);
	while(!q.empty()&& counter<val)
	{
		p=q.front();
		q.pop();
		a=new Node;
		b=new Node;
		a->key=counter++;
		b->key=counter++;
		a->left=NULL;
		a->right=NULL;
		b->left=NULL;
		b->right=NULL;
		p->left=a;
		p->right=b;
		q.push(a);
		q.push(b);
	}
}

void visit(Node *t)
{
	cout<<t->key<<endl;
}
Node *insertTree(Node *father,int isleft,int key)
{
	Node *p=new Node;
	if(isleft)
		{
			if(father->left)
				return NULL;
			else
			{
				p->key=key;
				p->left=NULL;
				p->right=NULL;
				father->left=p;
			}
		}
	else
	{
		if(father->right)
			return NULL;
		else
		{
			p->key=key;
			p->left=NULL;
			p->right=NULL;
			father->right=p;
		}
	}
	return p;
}


void SplitTree(Tree t,int x, Tree &small,Tree &big)
{
	//思路：从顶往下搜索，保持x一直位于根和子节点的值之间往下走，直到x位于两者的两侧
	//用两个栈（类型为指针），一个栈存位于x左侧的点的指针，另一个栈存位于右侧的
	//从栈底开始，把左侧的后者连到前者的指针上，栈底元素即为最后生成树的根节点
	stack<Node *> smaller,bigger;
	Node *p=t;
	do
	{
		if(x<p->key)
		{
			if(!p->left)
			{
				bigger.push(p);
				break;
			}
			else
			{
				if(x<p->left->key)
					p=p->left;
				else
				{
					bigger.push(p);
					p=p->left;
				}
			}
		}
		else
		{
			if(!p->right)
			{
				smaller.push(p);
				break;
			}
			else
			{
				if(x>p->right->key)
					p=p->right;
				else
				{
					smaller.push(p);
					p=p->right;
				}
			}
		}
	}while(p);

	
	if(bigger.size()>0)
	{
		while(!bigger.empty())
		{
			p=bigger.top();
			bigger.pop();
			if(!bigger.empty())
				bigger.top()->left=p;
			else
				big=p;
		}
	}
	else
		bigger=NULL;
	if(smaller.size()>0)
	{
		while(!smaller.empty())
		{
			p=smaller.top();
			smaller.pop();
			if(!smaller.empty())
				smaller.top()->right=p;
			else
				small=p;
		}
	}
	else
		smaller=NULL;
	//为了避免主树根丢失，需要加一段
	if(t->key<x)
		smaller=t;
	else
		bigger=t;
}

//用栈实现中序遍历
Status traverseIn(Tree &t,void (*f)(Node *))
{
	stack<Node *> s;
	Node *p;
	p=t;
	if(t==NULL)
		return 0;
	while(!s.empty()||p)
	{
		while(p)
		{
			s.push(p);
			p=p->left;
		}
		if(!s.empty())
		{
			p=s.top();
			s.pop();
			f(p);
			p=p->right;
		}
	}
	return 1;
}

Status traversePre(Tree &t,void (*f)(Node *))
{
	stack<Node *> s;
	Node *p=t;
	if(t==NULL)
		return 0;
	while(!s.empty()||p)
	{
		while(p)
		{
			f(p);
			if(p->right)
				s.push(p->right);
			p=p->left;
		}
		if(!s.empty())
		{
			p=s.top();
			s.pop();
			f(p);
			if(!s.empty())
			{
				p=s.top();
				s.pop();
			}
		}
	}
	return 1;
}
/*
Status traverseR(Tree &t,void (*f)(Node *))
{
	if(!t)
		return 0;
	stack<Node *>s;
	Node *p=t,*r=NULL;
	while(!s.empty()||p)
	{
		while(p)
		{
			s.push(p);
			p=p->left;
		}
		if(!s.empty())
		{
			p=s.top();
			if(p->right && p->right !=r)
			{
				p=p->right;
				s.push(p);
			}
			else
			{
				s.pop();
				f(p);
				r=p;
				p=NULL;
			}
		}
	}
	
	return 1;
}
*/
//更简单的非递归前序遍历
void preorderTraversalNew(Node *root, void (*f)(Node *))
{
    stack< pair<Node *, bool> > s;
    s.push(make_pair(root, false));
    bool visited;
    while(!s.empty())
    {
        root = s.top().first;
        visited = s.top().second;
        s.pop();
        if(root == NULL)
            continue;
        if(visited)
        {
            f(root);
        }
        else
        {
            s.push(make_pair(root->right, false));
            s.push(make_pair(root->left, false));
            s.push(make_pair(root, true));
        }
    }
}

/*
stack<pair<Node *,bool>> s;
bool visited;
while(!s.empty())
{
	root=s.top().first();
	visited=s.top().second;
	s.pop();
	if(root==NULL)
		continue;
	if(visited)
	{
		f(root);
	}
	else
	{
		s.push(make_pair(root->right,false));
		s.push(make_pair(root->left,false));
		s.push(make_pair(root,true));
	}
}
*/

//更简单的非递归中序遍历
void inorderTraversalNew(Node *root, void (*f)(Node *))
{
    stack< pair<Node *, bool> > s;
    s.push(make_pair(root, false));
    bool visited;
    while(!s.empty())
    {
        root = s.top().first;
        visited = s.top().second;
        s.pop();
        if(root == NULL)
            continue;
        if(visited)
        {
            f(root);
        }
        else
        {
            s.push(make_pair(root->right, false));
            s.push(make_pair(root, true));
            s.push(make_pair(root->left, false));
        }
    }
}
/*
--------------------- 
作者：czy47 
来源：CSDN 
原文：https://blog.csdn.net/czy47/article/details/81254984 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/


//惊了，真的不会这个玩意

//更简单的非递归后序遍历
void postorderTraversalNew(Tree &root,void (*f)(Node *))
{
    stack< pair<Node *, bool> > s;
    s.push(make_pair(root, false));
    bool visited;
    while(!s.empty())
    {
        root = s.top().first;
        visited = s.top().second;
        s.pop();
        if(root == NULL)
            continue;
        if(visited)
        {
            f(root);
        }
        else
        {
            s.push(make_pair(root, true));
            s.push(make_pair(root->right, false));
            s.push(make_pair(root->left, false));
        }
    }
}


//考研笔记第46题
//判断一棵以二叉链表形式存储的二叉树是否为完全二叉树
bool IsComplete(Tree t)
{
	if(!t)
		return false;
	queue<Node *> q;
	Node *p=t;
	q.push(p);
	bool alarm=false;
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		if(!p->left && p->right)
			return false;
		if(alarm && (p->left || p->right))
			return false;

		if(!p->left || !p->right)
			alarm=true;
		if(p->left) q.push(p->left);
		if(p->right) q.push(p->right);
	}
	return true;
}

bool IsComplete2(Tree t)
{
	if(!t)
		return false;
	queue<Node *> q;
	Node *p=t;
	q.push(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		if(p)
		{
			q.push(p->left);
			q.push(p->right);
		}
		else
		{
			while(!q.empty())
			{
				p=q.front();
				q.pop();
				if(p)
					return false;
			}
		}
	}
	return true;
}
//48 在二叉树中查找值为x的结点（最多有一个x）的所有祖先
//方法一，递归深搜
bool Search1(Node *t,int value)
{
	if(!t)
		return false;
	if(t->key==value)
		return true;
	else if(Search1(t->left,value) || Search1(t->right,value))
	{
		cout<<t->key<<endl;
		return true;
	}
	return false;
}







int main()
{
	Tree tree=NULL;
	appendTree(tree,8);
	cout<<"前序遍历"<<endl;
	traversePre(tree,visit);
	preorderTraversalNew(tree,visit);
	cout<<"中序遍历"<<endl;
	traverseIn(tree,visit);
	inorderTraversalNew(tree,visit);
	cout<<"后序遍历"<<endl;
	postorderTraversalNew(tree,visit);
	cout<<endl;
	//InOrder(tree,visit);
	cout<<endl;
	cout<<IsComplete2(tree)<<endl;
	cout<<"Search1"<<endl;
	Search1(tree,7);
	//BFS(tree,visit);
	//cout<<endl;
	//InOrder_dg(tree,visit);
	return 0;
}
