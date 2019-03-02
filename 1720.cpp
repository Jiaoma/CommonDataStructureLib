#include<iostream>
#include<stdio.h>
#include<string>
#include<math.h>
using namespace std;
int change(char a)
{
	if(a>='a' and a<='z')
		a=a-'a'+10;
	else if(a>='A' and a<='Z')
		a=a-'A'+10;
	else
		a=a-'0';
	return int(a);
}
int getDec(string a)
{
	int sum=0;
	for(int i=a.size()-1;i>=0;i--)
		sum+=pow(16,a.size()-1-i)*change(a[i]);
	return sum;
}
int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		cout<<getDec(a)+getDec(b)<<endl;
		a.clear();
		b.clear();
	}
}