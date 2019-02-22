#include<iostream>
using namespace std;
int main()
{
	int n,sum;
	while(cin>>n)
	{
		sum=0;
		while(n>0)
			sum+=n--;
		cout<<sum<<endl;
		cout<<endl;
	}
	return 0;
}