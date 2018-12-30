#include<iostream>
#include<iomanip>
#include<stack>

using namespace std;

typedef struct Node
{
	int n=0;
	int tag=0;//1为左，2位右
}Node;

int Fibnacci(int n)
{
	int sum=0;
	stack<Node> s;
	Node w;
	do
	{
		while(n>1)//先依次压入栈
		{
			w.n=n;
			w.tag=1;
			s.push(w);
			cout<<"入栈"<<"("<<n<<","<<1<<")"<<endl;
			n--;
		}
		printf("%d\n",sum);
		sum+=n;
		while(!s.empty())
		{
			w=s.top();
			s.pop();
			cout<<"出栈"<<"("<<w.n<<","<<w.tag<<")"<<endl;

			if(w.tag==1)
			{
				w.tag=2;
				s.push(w);
				cout<<"入栈"<<"("<<w.n<<","<<w.tag<<")"<<endl;
				n=w.n-2;
				break;
			}
		}
	}while(!s.empty());
	return sum;
}

int Fibnacci2(int n)
{
	stack<int> s;
	int sum=0;
	s.push(n);
	while(!s.empty())
	{
		n=s.top();
		s.pop();
		while(n>1)
			s.push(n--);
		sum+=1;
		while(!s.empty()&&s.top()<=2) s.pop();
		if(!s.empty())
		{
			n=s.top()-2;
			s.pop();
			s.push(n);
		}
	}
	return sum;
}

int main()
{
	int input;
	while(true)
	{
		cin>>input;
		printf("%d\n",Fibnacci(input));
		printf("%d\n",Fibnacci2(input));
	}
	return 0;
}