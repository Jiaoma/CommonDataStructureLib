#include<iostream>
#include<string>
#include<algorithm>
#define MAXLEN 100

using namespace std;


char A[MAXLEN];
char B[MAXLEN];
int longLen[MAXLEN][MAXLEN];

int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=n;j++)
			{
				longLen[i][j]=0;
			}
		}
		for(int i=1;i<=m;i++) cin>>A[i];
		for(int i=1;i<=n;i++) cin>>B[i];

		int a,b;
		for(a=1;a<=m;a++)
		{
			for(b=1;b<=n;b++)
			{
				if(A[a]==B[b])
					longLen[a][b]=longLen[a-1][b-1]+1;
				else
					longLen[a][b]=max(longLen[a-1][b],longLen[a][b-1]);
			}
		}
		cout<<longLen[m][n]<<endl;
	}
}