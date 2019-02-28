#include<iostream>
using namespace std;

int main()
{
    int mat[30][30];
    int n;
    for(int i=0;i<30;i++)
        for(int j=0;j<30;j++)
            mat[i][j]=1;
    for(int i=2;i<30;i++)
        for(int j=1;j<=(i-1);j++)
            mat[i][j]=mat[i-1][j]+mat[i-1][j-1];
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                cout<<mat[i][j];
                if(j!=i)
                    cout<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
