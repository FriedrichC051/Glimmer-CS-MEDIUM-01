#include<stdio.h>
#include<string.h>
#define maxn 11000
int a[maxn],len;
char s[maxn];
void read(int a[])
{
    scanf("%s",s);
    len=strlen(s);
    for(int i=0;i<=len-1;++i)a[len-1-i]=s[i]-'0';
}
void print(int a[])
{
    int i;
    for(i=len-1;i>=1;--i)
        if(a[i])break;
    for(;i>=0;--i)putchar(a[i]+'0');
    printf("\n");
}
int main()
{
    read(a);
    print(a);
    return 0;
}
