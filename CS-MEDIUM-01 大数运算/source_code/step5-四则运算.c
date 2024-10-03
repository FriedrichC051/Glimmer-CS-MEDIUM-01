#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 1100000
int a[maxn],b[maxn],c[maxn],d[maxn],LEN=0;
char s1[maxn],s2[maxn],ss[maxn*2];
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
void split()
{
    int len=strlen(ss);
    int i=0,cnt;
    for(;i<=len-1;++i)
    {
        if(isdigit(ss[i])||i==0)
        {
            s1[i]=ss[i];
        }
        else if(!isdigit(ss[i]))
        {
            op=ss[i];
            i++;
            cnt=i;
            break;
        }
    }
    for(;i<=len-1;++i)
    {
        s2[i-cnt]=ss[i];
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
void mul(int a[],int b[],int c[])
{
    LEN*=2;
    for(int i=0;i<=LEN-1;++i)
    {
        for(int j=0;j<=i;++j)
            c[i]+=(a[j]*b[i-j]);
        if(c[i]>=10)
        {
            c[i+1]+=(c[i]/10);
            c[i]%=10;
        }
    }
}
int grter(int a[],int b[],int last,int len)
{
    if(a[last+len]!=0)return 1;
    for(int i=len-1;i>=0;--i)
    {
        if(a[last+i]>b[i])return 1;
        else if(a[last+i]<b[i])return 0;
    }
    return 1;
}
void div(int a[],int b[],int c[],int d[])
{
    LEN+=20;
    int len1,len2;//被除数与除数的非零长度
    for(len1=LEN-1;len1>=1;--len1)
        if(a[len1-1])break;
    for(len2=LEN-1;len2>=1;--len2)
        if(b[len2-1])break;
    if(len2==0)return;//除数为0
    for(int i=0;i<=len1-1;++i)d[i]=a[i];
    for(int i=len1-len2;i>=0;--i)
    {
        while(grter(d,b,i,len2))
        {
            for(int j=0;j<=len2-1;++j)
            {
                d[i+j]-=b[j];
                if(d[i+j]<0)
                {
                   d[i+j+1]-=1;
                   d[i+j]+=10;
                }
            }
            c[i]+=1;
        }
    }
}
int main()
{
    scanf("%s",ss);
    split();
    sign1=read(a,s1);
    sign2=read(b,s2);
    if(op=='+')
    {
        sub_add();
    }
    else if(op=='-')
    {
        sign2=!sign2;
        sub_add();
    }
    else if(op=='*')
    {
        mul(a,b,c);
        if(sign1!=sign2)putchar('-');
        print(c);
    }
    else if(op=='/')
    {
        div(a,b,c,d);
        if(sign1!=sign2)putchar('-');
        print(c);
    }
    return 0;
}
