#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <cstdio>
using namespace std;

template<class T> struct StackNode
{
	T data;
	struct StackNode<T> *under;
};
template<class T> struct Stack
{
	StackNode<T> *bottom;
	StackNode<T> *top;
};

typedef struct StackNode<char> charNode;
typedef struct Stack<char> charStack;

template<class T>
void StackInit(Stack<T> &Stack)
{
	Stack.bottom = new StackNode<T>();
	Stack.bottom->under = NULL;
	Stack.top = Stack.bottom;
}
template<class T>
void push(Stack<T> *Stack, T tar)
{
	if (Stack==NULL || Stack->bottom==NULL ||Stack->bottom->under!=NULL)
	{
		cout << "使用了未初始化的栈或者该栈不存在" << endl;
		exit(0);
	}
	StackNode<T> *temp= new StackNode<T>();
	temp->data = tar;
	temp->under = Stack->top;
	Stack->top = temp;
}
template<class T>
T pop(Stack<T> *Stack)
{
	if (Stack == NULL || Stack->bottom == NULL || Stack->bottom->under != NULL)
	{
		cout << "使用了未初始化的栈或者该栈不存在" << endl;
		exit(0);
	}
	else if (Stack->top==Stack->bottom)
	{
		cout << "该栈已经为空" << endl;
		exit(0);
	}
	StackNode<T> *temp = Stack->top;
	Stack->top = Stack->top->under;
	T re = temp->data;
	delete temp;
	return re;
}

template<class T>
bool isEmpty(Stack<T> *Stack)
{
	return Stack->bottom == Stack->top;
}
typedef struct TreeNode
{
	bool isOp;
	double value;
	char oprt;
	struct TreeNode *parent, *lchild, *rchild;
}TreeNode;

TreeNode *CreateTreeNode(bool isOP, double value, char oprt)
{
	TreeNode *result = new TreeNode();
	result->isOp = isOP;
	result->value = value;
	result->oprt = oprt;
	result->parent = NULL;
	result->lchild = NULL;
	result->rchild = NULL;
	return result;
}

//全局变量
int posi = 0;
char priority[7][7] = {
	//   '+' '-' '*' '/' '(' ')' '#'
	{ '>','>','<','<','<','>','>' },//+
	{ '>','>','<','<','<','>','>' },//-
	{ '>','>','>','>','<','>','>' },//*
	{ '>','>','>','>','<','>','>' },///
	{ '<','<','<','<','<','=',' ' },//(
	{ '>','>','>','>',' ','>','>' },//)
	{ '<','<','<','<','<',' ','=' },//#
};

//tools
//1.判断是数字还是运算符
bool isNumber(char t)
{
	if (t == '+' || t == '-' || t == '*' || t == '/' || t == '(' || t == ')' || t == '#'||t==' ') {
		return false;
	}
	else
		return true;
}
//2.把字符转化为数字
double changeToNum(string &exp)
{
	double sum = 0;
	bool small = false;
	int smallpo = 0;
	while (isNumber(exp[posi])) {
		if (exp[posi]=='.')
		{
			small = true;
			posi++;
			continue;
		}
		if (!small)
		{
			sum = sum * 10.0 +1.0*(exp[posi++] - '0');
		}
		else
		{
			sum += 1.0*(exp[posi++] - '0')*pow(10.0, -(++smallpo));
		}
	}
	return sum;
}
//3.运算符转序号
int changeToVex(char oprt)
{
	switch (oprt) {
	case '+':
		return 0;
		break;
	case '-':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '/':
		return 3;
		break;
	case '(':
		return 4;
		break;
	case ')':
		return 5;
		break;
	case '#':
		return 6;
		break;
	default:
		return 6;
		break;
	}
}
//4.优先级比较
char PriorityCompare(char oprt1, char oprt2)
{
	int vex1 = changeToVex(oprt1);
	int vex2 = changeToVex(oprt2);
	return priority[vex1][vex2];
}
//5.计算结果
double calculate(double num1, char oprt, double num2)
{
	double result;
	switch (oprt) {
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1*num2;
		break;
	case '/':
		result = num1 / num2;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

string PrintcharStack(charStack *stack)
{
	string res;
	charNode *ptr = stack->top;
	while (ptr!=stack->bottom)
	{
		res+=(ptr->data);
		ptr = ptr->under;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main(int argc, const char * argv[]) {
	string inp;
	string houzhui;
	charStack oprts;
	StackInit(oprts);
	char oprt[2];
	oprt[1] = '\0';
	cin >> inp;
	cout << "输入的表达式为：" << inp << endl;
	posi = 0;
	inp += '#';
	cout << "为输入串添加结束符:" << inp << endl;
	push(&oprts, '#');
	cout << "开始生成后缀表达式" << endl;
	//生成后缀表达式
	while (posi<inp.length()) {
		if (isNumber(inp[posi])) {
			double temp = changeToNum(inp);
			//string temmp{ inp[posi] };
			houzhui.append(to_string(temp));
			houzhui.append(" ");
			cout << "当前获取输入为:" << temp << endl;
			cout << "当前运算符栈为：" << PrintcharStack(&oprts) << endl;
			cout << "当前的后缀表达式为:" << houzhui << endl;
			cout << endl;
		}
		else
		{
			switch (PriorityCompare(oprts.top->data, inp[posi])) {
			case '=':
				pop(&oprts);
				posi++;
				break;
			case '<':
				push(&oprts, inp[posi]);
				posi++;
				break;
			case '>':
				oprt[0] = pop(&oprts);
				houzhui.append(oprt);
				houzhui.append(" ");
				break;
			default:
				cout << "输入的表达式格式非法" << endl;
				exit(0);
			}
		}
	}
	cout << "后缀表达式为: " << houzhui << endl;
	cout << endl;
	cout << endl;
	cout << "利用生成的后缀表达式求值" << endl;
	//后缀表达式求值
	//建立一个树节点栈，从左向右扫描后缀表达式，
	//将数值存入节点然后存入树节点栈，遇到运算符则取出两个节点，
	//将运算符存入节点，以该节点为取出节点的根节点，再将该节点存入堆栈
	//完成后栈顶的节点即为根节点
	Stack<TreeNode *>TreeNodeStack;
	StackInit<TreeNode *>(TreeNodeStack);
	posi = 0;
	int step = 1;
	while (posi<houzhui.length())
	{
		if (isNumber(houzhui[posi])) {
			double temp = changeToNum(houzhui);
			push(&TreeNodeStack, CreateTreeNode(false, temp, '@'));
		}
		else if (houzhui[posi] == ' ')
		{
			posi++;
		}
		else
		{
			//若posi位置处为运算符
			TreeNode *p = CreateTreeNode(true, 0, houzhui[posi]);
			p->rchild = pop(&TreeNodeStack);
			p->rchild->parent = p;
			p->lchild = pop(&TreeNodeStack);
			p->lchild->parent = p;
			cout << "读到的数为:" << p->lchild->value << "," << p->rchild->value << endl;
			cout << "读到的符号为:" << p->oprt << endl;
			p->value = calculate(p->lchild->value, p->oprt, p->rchild->value);
			cout << "步骤" << step++ << ":" << p->lchild->value << p->oprt << p->rchild->value << "=" << p->value << endl;
			cout << endl;
			push(&TreeNodeStack, p);
			posi++;
		}
	}

	cout << "计算结果为" << setiosflags(ios::fixed) << setprecision(2) << TreeNodeStack.top->data->value << endl;
	printf("%.2f\n",TreeNodeStack.top->data->value);
	return 0;
}
