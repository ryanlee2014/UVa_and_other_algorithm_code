#include <stdio.h>
#include <string.h>
#define MAXN 10000

char n[10000];

int lastdigit(char* buf)
{
    const int mod[21]={6,6,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2,1};
    int len=strlen(buf),a[MAXN],i,c,ret=1;
    if(len==1) return mod[(buf[0]-'0')<=1?20:(buf[0]-'0')];
    for (i=0;i<len;i++) a[i]=buf[len-1-i]-'0';
    for (;len;len-=!a[len-1])
    {
        ret=ret*mod[a[1]%2*10+a[0]]%10;
        for (c=0,i=len-1;i>=0;i--)
            c=c*10+a[i],a[i]=c/5,c%=5;
    }
    return ret;
}


int main()
{
    while(scanf("%s",n)!=EOF)
        printf("%d\n",lastdigit(n));
    return 0;
}