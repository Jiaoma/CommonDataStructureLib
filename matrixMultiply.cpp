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

int main()
{
    int configs[MAXLEN];
    for(int i=0;i<MAXLEN;i++) configs[i]=0;
    int num;
    while(cin>>num)
    {
        for(int i=0;i<=num;i++) cin>>configs[i];
        int minCost[num][num];
        int *p=(int *)(*minCost);
        for(int i=0;i<(num)*(num);i++)
            *p++=0;
        for(int i=0;i<num;i++) minCost[i][i]=0;
        for(int stride=1;stride<=(num-1);stride++)
        {
			for(int i=0;i<num;i++)
			{
				int min=9999999;
				int temp;
				for(int j=i+1;j<=i+stride;j++)
				{
					temp=minCost[i][j-1]+minCost[j][i+stride]+configs[i]*configs[j]*configs[i+stride+1];
					if(temp<min)
						min=temp;
				}
				minCost[i][i+stride]=min;
			}
        }
		cout<<"complete"<<endl;
		cout<<"The minist cost is:"<<minCost[0][num-1]<<endl;
		for(int i=0;i<num;i++)
		{
			for(int j=0;j<num;j++)
				cout<<minCost[i][j]<<' ';
			cout<<endl;
		}
				
    }
}
