#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int num;
    char c;
    int a,b;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>c>>a>>b;
        switch(c)
        {
            case '+':cout<<a+b<<endl;break;
            case '-':cout<<a-b<<endl;break;
            case '*':cout<<a*b<<endl;break;
            case '/':
                    if((a-a/b*b)==0)
                        cout<<a/b<<endl;
                    else
                        printf("%.2f\n",a*1.0/b);
        }
    }
}
