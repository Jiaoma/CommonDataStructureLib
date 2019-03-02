#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int a[]={3,1,6,2,8,3}
	sort(a,a+6);
	for(int i=0;i<6;i++)
		cout<<a[i]<<' ';
	cout<<endl;
}