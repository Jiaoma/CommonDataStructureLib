#include<iostream>
#define MAXLEN 1000
using namespace std;

void matrixMultiply(int **ma,int **mb,int **result,int ra,int ca,int rb,int cb)
{
    if(ca!=rb)
    {
        cout<<"ERROR: Mat a can't multiply Mat b"<<endl;
        return;
    }
    for(int i=0;i<ra;i++)
    {
        for(int k=0;k<cb;k++)
        {
            int localSum=0;
            for(int j=0;j<ca;j++)
            {
                localSum+=ma[i][j]*mb[j][k];
            }
            result[i][k]=localSum;
        }
    }
}

int memo[MAXLEN][MAXLEN];
int configs[MAXLEN];

int lookUp(int start,int end)
{
    if (memo[start][end]!=0)
        return memo[start][end];
    if (start>=end)
        return 0;
    int min=lookUp(start,start)+lookUp(start+1,end)+configs[start]*configs[start+1]*configs[end+1];
    int temp;
    for(int i=start+1;i<end;i++)
    {
        temp=lookUp(start,i)+lookUp(i+1,end)+configs[start]*configs[i+1]*configs[end+1];
        //cout<<temp<<endl;
        if(min>temp)
            min=temp;
    }
    memo[start][end]=min;
    return min;
}

int main()
{
    for(int i=0;i<MAXLEN;i++) configs[i]=0;
    int num;
    while(cin>>num)
    {
        for(int i=0;i<=num;i++) cin>>configs[i];
        int *p=(int *)(*memo);
        for(int i=0;i<(num)*(num);i++)
            *p++=0;
		cout<<"The minist cost is:"<<lookUp(0,num-1)<<endl;
		for(int i=0;i<num;i++)
		{
			for(int j=0;j<num;j++)
				cout<<memo[i][j]<<' ';
			cout<<endl;
		}
				
    }
}
