#include<stdio.h>
#include<string.h>
#define maxn 11000
int a[maxn],b[maxn],c[maxn],LEN=0;
char s1[maxn],s2[maxn];
int sign1,sign2;
char op;
int max(int a,int b)
{
    return (a>b)?a:b;
}
int cmp(char s1[],char s2[])
{
    int len1=strlen(s1),len2=strlen(s2);
    if(len1>len2)return 1;
    else if(len1<len2)return 0;
    else
    {
        int x=strcmp(s1,s2);
        if(x>=0)return 1;
        else return 0;
    }
}
int read(int a[],char s[])
{
    int ok=1,brk=1;
    int len=strlen(s);
    LEN=max(LEN,len);
    for(int i=0;i<=len-1;++i)
    {
        if(s[i]=='('||s[i]==')')
        {
            brk=0;
            continue;
        }
        if(s[i]=='-')
        {
            ok=0;
            continue;
        }
        if(brk)a[len-1-i]=s[i]-'0';
        else if(!brk)a[len-2-i]=s[i]-'0';
        if(!ok&&brk)s[i-1]=s[i];
        else if(!ok&&!brk)s[i-2]=s[i];
    }
    if(!ok&&brk)s[len-1]='\0';
    else if(!ok&&!brk)
    {
        s[len-3]='\0';
        s[len-2]='\0';
        s[len-1]='\0';
    }
    return ok;
}
void print(int a[])
{
    int i;
    for(i=LEN-1;i>=1;--i)
        if(a[i])break;
    for(;i>=0;--i)
    {
        putchar(a[i]+'0');
    }
    printf("\n");
}
int main()
{

    //说明：由于样例输入存在有空格，因此本程序的提取方法是针对有空格的输入
    //无空格的输入的提取方法见 Part4 代码

    scanf("%1100[^ ]",s1);
    sign1=read(a,s1);
    scanf(" %c",&op);
    scanf("%1100s",s2);
    sign2=read(b,s2);
    if(!sign1)putchar('-');
    print(a);
    if(!sign2)putchar('-');
    print(b);
    printf("%c\n",op);
    return 0;
}
