#include<iostream>
using namespace std;

int sumall(int n,int z)
{
    int sum=0;
    int temp;
    while(n>0)
    {
        temp=n%z;
        n=(n-n%z)/z;
        sum+=temp;
    }
    return sum;
}

int main()
{
    cout<<2992;
    int t1,t2;
    for(int i=2993;i<10000;i++)
    {
        t1=sumall(i,16);
        t2=sumall(i,12);
        if(sumall(i,10)==t2 && t1==t2)
        {
            cout<<endl;
            cout<<i;
        }
    }
    cout<<endl;
}
