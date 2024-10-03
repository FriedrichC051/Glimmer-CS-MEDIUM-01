#include<stdio.h>
#include<string.h>
#define maxn 11000
int a[maxn],b[maxn],c[maxn],LEN=0;
char s[maxn];
int max(int a,int b)
{
    return (a>b)?a:b;
}
void read(int a[])
{
    scanf("%s",s);
    int len=strlen(s);
    LEN=max(LEN,len);
    for(int i=0;i<=len-1;++i)a[len-1-i]=s[i]-'0';
}
void print(int a[])
{
    int i;
    for(i=LEN-1;i>=1;--i)
        if(a[i])break;
    for(;i>=0;--i)putchar(a[i]+'0');
    printf("\n");
}
void add(int a[],int b[],int c[])
{
    for(int i=0;i<=LEN-1;++i)
    {
        c[i]+=(a[i]+b[i]);
        if(c[i]>=10)
        {
            c[i+1]+=1;
            LEN=max(LEN,i+2);
            c[i]-=10;
        }
    }
}
int main()
{
    read(a);
    read(b);
    add(a,b,c);
    print(c);
    return 0;
}
