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


//筛法求素数
//sieve of Eratosthenes
void EraPrime(int *&storage,int n)
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
}
void printArray(int *s,int len)
{
    for(int i=0;i<len;i++)
    {
        if(s[i])
             cout<<i<<endl;
    }
}
int main()
{
    int *nums;
    EraPrime(nums,100);
    printArray(nums,100);
    cout<<isPrime(4)<<endl;
    for(int i=0;i<100;i++)
    	if((nums[i]==1 && not isPrime(i)) || (nums[i]==0 && isPrime(i)))
    	{
    		cout<<"Error"<<endl;
    		cout<<i<<endl;
    		return 0;
    	}
    cout<<"OK"<<endl;

    //cout<<*nums<<endl;
}

