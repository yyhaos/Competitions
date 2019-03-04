#include<stdio.h>
#include <string.h>
#include<iostream>
#include<queue>

using namespace std ;
int dp[2000005];
struct qs
{
    int pos,th;
};
queue <qs> q;
int main ()
{
    int n,k,th=1;
    scanf("%d%d",&n,&k);
    if(n==k)
    {
        printf("0");
        return 0;
    }
    qs tem;
    tem.pos=n;
    tem.th=0;
    q.push(tem);
    memset(dp,0,sizeof(dp));
    while(1)
    {
        qs top=q.front();
        q.pop();

        if(dp[top.pos]>0)
            continue;

        dp[top.pos]=top.th;
        th=top.th+1;
        tem.th=th;

        if(top.pos==k)
            break;

        if(top.pos+1<=2000000)
        {
            tem.pos=top.pos+1;
            q.push(tem);
        }

        if(top.pos-1>=0)
        {
            tem.pos=top.pos-1;
            q.push(tem);
        }

        if(top.pos*2<=200000)
        {
            tem.pos=top.pos*2;
            q.push(tem);
        }

    }
    dp[n]=1;

    printf("%d",dp[k]);
    return 0;
}
