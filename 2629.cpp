#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    map<string,string> m;
    m["33"]="Zhejiang";
    m["11"]="Beijing";
    m["71"]="Taiwan";
    m["81"]="Hong Kong";
    m["82"]="Macao";
    m["54"]="Tibet";
    m["21"]="Liaoning";
    m["31"]="Shanghai";
    int len,num;
    string input;
    string place;
    string y;
    string mo;
    string d;
    while(cin>>num)
    {
        for(int i=0;i<num;i++)
        {
            cin>>input;
            place=input.substr(0,2);
            y=input.substr(6,4);
            mo=input.substr(10,2);
            d=input.substr(12,2);
            cout<<"He/She is from "<<m[place]<<",and his/her birthday is on "<<mo<<","<<d<<","<<y<<" based on the table."<<endl;
        }
    }
}
