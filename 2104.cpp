#include<iostream>
using namespace std;

long int gcd(long int a,long int b)
{
    long int temp;
    while(b!=0)
    {
        temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}

int main()
{
    long int n,m;
    while(cin>>n>>m)
    {
        if(n==-1 && m==-1) break;
        if(gcd(n,m)==1) cout<<"YES"<<endl;
        else cout<<"POOR Haha"<<endl;
    }
}
