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
    for(i=3;i<=sqrt(n);i+=2)
        if(n%i==0)
            return 0;
    return 1;
}


//筛法求素数
//sieve of Eratosthenes
void EraPrime(int *storage,int n)
{
    int cur;
    storage=new int(n+5);
    int i;
    for(i=0;i<=n;i++)
    {
        storage[i]=1;
    }
    storage[0]=0;
    storage[1]=0;
    for(i=2;i<=sqrt(n);i++)
    {
        if(storage[i])
        {
            cur=i;
            for(int j=2;j<=n/cur;j++)
                storage[j*cur]=0;
        }
    }
    for(int k=0;k<=n;k++)
        if(storage[k])
            cout<<k<<endl;
}
void printArray(int *s,int len)
{
    for(int i=0;i<len-5;i++)
    {
        cout<<*(s+i)<<endl;
    }
}
int main()
{
    int *nums;
    EraPrime(nums,100);
    //printArray(nums,100);
    //cout<<*nums<<endl;
}
