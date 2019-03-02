#include<stdio.h>
#include<string.h>

using namespace std;
void change(char *&o,char *&p)
{
    if(strchr(o,'.')==NULL)
    {
        p=o+strlen(o);
        char *pp=o;
        for(;*pp!='\0' && *pp=='0';pp++);
        o=pp;
    }
    else
    {
        char *i=strchr(o,'.');
        *i='\0';
        p=i+1;
        char *pp=o;
        for(;*pp!='\0' && *pp=='0';pp++);
        o=pp;
        for(pp=p+strlen(p)-1;*pp!='\0' && *pp=='0';pp--);
        *(++pp)='\0';
    }

}
void strip(char *&a)
{
    if(*a=='+' || *a=='-')
        a+=1;
}
int main()
{
    char a[1000000];
    char b[1000000];
    char *pa=NULL;
    char *pb=NULL;
    char *oa=NULL;
    char *ob=NULL;
    while(~scanf("%s %s",a,b))
    {
        oa=a;
        ob=b;
        strip(oa);
        strip(ob);
        change(oa,pa);
        change(ob,pb);

        if(strcmp(oa,ob)==0 && strcmp(pa,pb)==0 && !((a[0]=='-' &&b[0]!='-')||(a[0]!='-' &&b[0]=='-')))
            printf("YES\n");

        else if(((a[0]=='-' &&b[0]!='-')||(a[0]!='-' &&b[0]=='-')) && strlen(oa)==0 && strlen(ob)==0 &&strlen(pa)==0 && strlen(pb)==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
