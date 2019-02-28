#include<iostream>
using namespace std;

int main()
{
    int num;
    int n,a;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>n;
        a=3;
        for(int j=0;j<n;j++)
        {
            a=2*(a-1);
        }
        cout<<a<<endl;
    }
}
