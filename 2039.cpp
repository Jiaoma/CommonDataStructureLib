#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
void swap(double &a,double &b)
{
	double c;
	c=a;
	a=b;
	b=c;
}
void sort3(double (&data)[5])
{
	int max=0;
	for(int i=1;i<3;i++)
	{
		if(data[max]<data[i])
			max=i;
	}
	swap(data[2],data[max]);
	if(data[0]>data[1])
		swap(data[0],data[1]);
}
int main()
{
	double inputs[5];
	int n;
	while(cin>>n)
	{
		getchar();
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<3;i++)
			{
				cin>>inputs[i];
			}
			getchar();
			sort3(inputs);
			if(inputs[0]+inputs[1]>inputs[2])
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}