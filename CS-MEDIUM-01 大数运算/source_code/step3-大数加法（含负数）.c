#include<stdio.h>
#include<string.h>
#define maxn 11000
int a[maxn],b[maxn],c[maxn],LEN=0;
char s1[maxn],s2[maxn];
int sign1,sign2;
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
    int ok=1;
    scanf("%s",s);
    int len=strlen(s);
    LEN=max(LEN,len);
    for(int i=0;i<=len-1;++i)
    {
        if(s[i]=='-')
        {
            ok=0;
            continue;
        }
        a[len-1-i]=s[i]-'0';
        if(!ok)s[i-1]=s[i];
    }
    if(!ok)s[len-1]='\0';
    return ok;
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
void sub(int a[],int b[],int c[])
{
    for(int i=0;i<=LEN-1;++i)
    {
        c[i]+=(a[i]-b[i]);
        if(c[i]<0)
        {
            c[i+1]-=1;
            c[i]+=10;
            LEN=max(LEN,i+2);
        }
    }
}
void sub_cmp(char s1[],char s2[],int a[],int b[])
{
    int mark=cmp(s1,s2);
    if(mark)
        sub(a,b,c);
    else
    {
        putchar('-');
        sub(b,a,c);
    }
    print(c);
}
void sub_add()
{
    if(sign1&&sign2)
    {
        add(a,b,c);
        print(c);
    }
    else if(!sign1&&sign2)
    {

        sub_cmp(s2,s1,b,a);

    }
    else if(sign1&&!sign2)
    {
        sub_cmp(s1,s2,a,b);
    }
    else
    {
        putchar('-');
        add(a,b,c);
        print(c);
    }
}
int main()
{
    sign1=read(a,s1);
    sign2=read(b,s2);
    sub_add();
    return 0;
}
