#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char inputs[256];
    int sum;
    while(cin.getline(inputs,256))
    {
        if(strlen(inputs)==1 && inputs[0]=='#')
            break;
        sum=0;
        for(int i=0;i<strlen(inputs);i++)
        {
            if(inputs[i]!=' ')
                sum+=(i+1)*(inputs[i]-'A'+1);
        }
        cout<<sum<<endl;
    }
}
