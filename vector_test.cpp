#include<vector>
#include<iostream>
using namespace std;
//把vector的所有操作在这个文件里面必须全部用一遍
int main()
{
    vector<int> a;
    a.push_back(1);
    for (auto i=a.begin();i!=a.end();i++)
        cout<<*i<<endl;
}
