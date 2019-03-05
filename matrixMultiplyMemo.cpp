#include<iostream>
#define MAXSIZE 100
int m[MAXSIZE][MAXSIZE];
int s[MAXSIZE][MAXSIZE];
int p[MAXSIZE];
int LookupChain(int i,int j);
int Memo(int n)
{
    for(int i=0;i<MAXSIZE;i++)
        for(int j=0;j<MAXSIZE;j++)
            m[i][j]=0;
    return LookupChain(1,n);
}

int LookupChain(int i,int j)
{
    if(m[i][j]>0) return m[i][j];
    if(i==j) return 0;
    int u=LookupChain(i,i)+LookupChain(i+1,j)+p[i-1]*p[i]*p[j];
    s[i][j]=i;
    for(int k=i+1;k<j;k++)
    {
        int t=LookupChain(i,k)+LookupChain(k+1,j)+p[i-1]*p[k]*p[j];
        if(t<u){
            u=t;
            s[i][j]=k;
        }
    }
    m[i][j]=u;
    return u;
}
