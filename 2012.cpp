#include<iostream>
#include<math.h>
using namespace std;
//求素数方法大全
//朴素法的极限
int isPrime(int n)
{
    int i;
    if(n<=1)
        return 0;
    if(n==2)
        return 1;
    if(n%2==0)
    	return 0;
    for(i=3;i<=sqrt(n);i+=2)
        if(n%i==0)
            return 0;
    return 1;
}

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a==0 && b==0)
            break;
        for(int i=a;i<=b;i++)
        {
            if(!isPrime(i*i+i+41))
            {
                cout<<"Sorry"<<endl;
                goto ll;
            }
        }
        cout<<"OK"<<endl;
        ll:
        {}
    }
}
