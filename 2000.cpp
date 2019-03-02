#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
void swap(int &a,int &b)
{
	int c;
	c=a;
	a=b;
	b=c;
}
int main()
{
	char inputs[5];
	int max;
	while(scanf("%s",inputs)!=EOF)
	{
		getchar();
		max=0;
		for(int i=1;i<3;i++)
		{
			if(inputs[max]<inputs[i]) max=i;
		}
		swap(inputs[max],inputs[2]);
		if(inputs[0]>inputs[1])
			swap(inputs[0],inputs[1]);
		cout<<inputs[0]<<' '<<inputs[1]<<' '<<inputs[2]<<endl;
	}
	return 0;
}