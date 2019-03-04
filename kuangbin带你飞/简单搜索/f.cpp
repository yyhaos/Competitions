#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;

int dp[11][11][11][11];
bool is[11][11][11][11];
int s[5];
int e[5];

struct ps
{
    int k[5];
    int th;
};
bool done;
queue<ps > q;

void dfs()
{
    if(done)
        return;
    ps top=q.front();
    q.pop();

 //   printf("%d%d%d%d-%d\n",top.k[4],top.k[3],top.k[2],top.k[1],top.th);

    if(dp[top.k[4]][top.k[3]][top.k[2]][top.k[1]]>0)
    {
        dfs();
        return;
    }
    int flag=1;
    for(int i=1;i<=4;i++)
    {
        if(top.k[i]!=e[i])
            flag=0;
    }
    dp[top.k[4]][top.k[3]][top.k[2]][top.k[1]]=top.th;
  //  printf("flag=%d\n",flag);
    if(flag)
    {
        done=true;
    }

    ps tem;
    for(int i=0;i<=9;i++)
    {
      //  printf("i=%d\n",i);
        if(i!=0 && is[i][top.k[3]][top.k[2]][top.k[1]])
        {
            memcpy(tem.k,top.k,sizeof(top.k));
            tem.k[4]=i;
            tem.th=top.th+1;
            q.push(tem);
        }
        if(is[top.k[4]][i][top.k[2]][top.k[1]])
        {
            memcpy(tem.k,top.k,sizeof(top.k));
            tem.k[3]=i;
            tem.th=top.th+1;
            q.push(tem);
        }
        if(is[top.k[4]][top.k[3]][i][top.k[1]])
        {
            memcpy(tem.k,top.k,sizeof(top.k));
            tem.k[2]=i;
            tem.th=top.th+1;
            q.push(tem);
        }

        if(is[top.k[4]][top.k[3]][top.k[2]][i])
        {
            memcpy(tem.k,top.k,sizeof(top.k));
            tem.k[1]=i;
            tem.th=top.th+1;
            q.push(tem);
        }
    }
     dfs();
}

int main ()
{
    memset(is,true,sizeof(is));
    for(int i=1;i<=9;i++)
        for(int j=0;j<=9;j++)
            for(int k=0;k<=9;k++)
                for(int m=0;m<=9;m++)
                {
                    int num=i*1000+j*100+k*10+m;
                    for(int ch=2;ch<=sqrt(num)+5;ch++)
                    {
                        if(num%ch==0)
                        {
                            is[i][j][k][m]=false;
                        //    printf("%d%d%d%d\n",i,j,k,m);
                            break;
                        }
                    }
                }

    int t;
    scanf("%d",&t);

    while(t--)
    {
        memset(dp,0,sizeof(dp));
        while(!q.empty())
            q.pop();
        int n,m;
        scanf("%d%d",&n,&m);
        int th=1;
        while(n>0)
        {
            s[th++]=n%10;
            n/=10;
        }
        th=1;
        while(m>0)
        {
            e[th++]=m%10;
            m/=10;
        }
        //dp[s[4]][s[3]][s[2]][s[1]]=0;
        ps te;
        memcpy(te.k,s,sizeof(s));
        te.th=0;
        q.push(te);
        done=false;
        dfs();

        printf("%d\n",dp[e[4]][e[3]][e[2]][e[1]]);
    }
    return 0;
}
