#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

bool isOK(int a,int b,int c)
{
    return (a*a==b*b+c*c)||(b*b==a*a+c*c)||(c*c==a*a+b*b);
}
int main()
{
    int t;
    while(cin>>t)
    {
        for(int it=0;it<t;it++)
        {
            int n;
            cin>>n;
            vector<int> lens(n);
            for(int it2=0;it2<n;it2++) cin>>lens[it2];
            sort(lens.begin(),lens.end());
            map<int,vector<int>> best;
            for(int i=0;i<n-2;i++)
                for(int j=i+1;j<n-1;j++)
                    for(int k=j+1;k<n;k++)
                    {
                        if(isOK(lens[i],lens[j],lens[k]))
                            best[i*j*k]=vector<int> {lens[i],lens[j],lens[k]};
                    }
            auto iter=best.end();
            iter--;
            auto v=iter->second;
            for(auto iter2=v.begin();iter2!=v.end();iter2++)
                cout<<*iter2<<" ";
            cout<<endl;
        }
    }
}
