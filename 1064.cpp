#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    float sum=0;
    float input;
    for(int i=0;i<12;i++)
    {
        cin>>input;
        sum+=input;
    }
    sum=round(sum*100/12)/100;
    printf("$%.2f\n",sum);
}
