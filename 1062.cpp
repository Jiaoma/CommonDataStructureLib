#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
void traverse(char *data,int b,int e)
{
	char temp;
	if(e<=b) return;
	for(int i=b;i<=(b+e)/2;i++)
	{
		temp=data[i];
		data[i]=data[e-i+b];
		data[e-i+b]=temp;
	}
}

int main()
{
	int t;
	char a[1000];
	char *p=a;
	int len,start,end;
	while(cin>>t)
	{
		getchar();
		for(int i=0;i<t;i++)
		{
			gets(a);
			len=strlen(a);
			start=0;
			end=0;
			for(int j=0;j<len;j++)
			{
				end=j;
				if(a[j]==' ')
				{   
					traverse(p,start,end-1);
					start=end+1;
				}
				else if(j==(len-1))
				{
					traverse(p,start,end);
				}
			}
			cout<<a<<endl;
		}
	}
	return 0;
}