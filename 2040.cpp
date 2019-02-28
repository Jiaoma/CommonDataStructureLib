#include<iostream>
#include<math.h>
using namespace std;

int getFactorSum(int n)
{
    int i;
    int sum=1;
    for(i=2;i<sqrt(n);i++)
    {
        if(n%i==0)
            sum+=i+n/i;
    }
    if(i*i==n)
        sum+=i;
    return sum;
}

int main()
{
    int a,b;
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>a>>b;
        if(getFactorSum(a)==b && getFactorSum(b)==a)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
