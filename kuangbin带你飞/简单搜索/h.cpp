#include<stdio.h>

#include<queue>

#include<map>

#include<string>

#include<string.h>

using namespace std;
struct state
{
    int a,b,th;
};
queue<state> s;
int A,B,C;
int dp[115][115];

int in(int a,int b,int th)
{
    if(a>A || b>B || a<0 || b<0)
        return 0 ;
    if(dp[a][b]<99999998)
        return 0;

    if(a==b && a==0)
        return 0;
    state tt;
    tt.a=a;
    tt.b=b;
    tt.th=th;
    s.push(tt);
    return 1;
}

int th,flag,type[115][115][15],vis[115][115];

void myPrint(int a,int b)
{
    if(a==b && a==0)
        return;
    myPrint(type[a][b][2],type[a][b][3]);
    switch (type[a][b][0])
    {
        case 1:
            if(type[a][b][1]==1)
                printf("DROP(1)\n");
            else
                printf("DROP(2)\n");
            break;
        case 2:
            if(type[a][b][1]==1)
                printf("FILL(1)\n");
            else
                printf("FILL(2)\n");
            break;
        case 3:
            if(type[a][b][1]==1)
                printf("POUR(1,2)\n");
            else
                printf("POUR(2,1)\n");
            //printf("POUR(%d,%d)\n",type[a][b][1],3-type[a][b][1]);
            break;
    }
    return ;
}

int main ()
{
    //freopen("test.txt","r",stdin);
   while(~scanf("%d%d%d",&A,&B,&C))
    {
        memset(vis,0,sizeof(vis));
        memset(type,0,sizeof(type));
        state tem;
        tem.a=tem.b=tem.th=0;
        s.push(tem);

        int ans=-1,fa,fb;
        for(int i=0;i<=100;i++)
            for(int j=0;j<=100;j++)
                dp[i][j]=99999999;
        while(!s.empty())
        {
            if(ans>=0)
            {
                s.pop();
                continue;
            }
            state top=s.front();
            s.pop();
            int ta=top.a,tb=top.b,th=top.th;

            if(dp[ta][tb]<99999998)
                continue;
            dp[ta][tb]=th;
            if(ta==C || tb==C)
            {
                fa=ta;
                fb=tb;
                ans=th;
                printf("%d\n",ans);
                myPrint(fa,fb);
                continue;
            }
            //printf("%d %d %d\n",ta,tb,dp[ta][tb]);
            th++;
            if(in(0,tb,th))
            {
                if(!vis[0][tb])
                {
                    vis[0][tb]=1;
                    type[0][tb][0]=1;
                    type[0][tb][1]=1;
                    type[0][tb][2]=ta;
                    type[0][tb][3]=tb;
                }
            }
            //in(ta,0,th);
            if(in(ta,0,th))
            {
                if(!vis[ta][0])
                {
                    vis[ta][0]=1;
                    type[ta][0][0]=1;
                    type[ta][0][1]=2;
                    type[ta][0][2]=ta;
                    type[ta][0][3]=tb;
                }
            }
            if(in(ta,B,th))
            {
                if(!vis[ta][B])
                {
                    vis[ta][B]=1;
                    type[ta][B][0]=2;
                    type[ta][B][1]=2;
                    type[ta][B][2]=ta;
                    type[ta][B][3]=tb;
                }
            }
            if(in(A,tb,th))
            {
                if(!vis[A][tb])
                {
                    vis[A][tb]=1;
                    type[A][tb][0]=2;
                    type[A][tb][1]=1;
                    type[A][tb][2]=ta;
                    type[A][tb][3]=tb;
                }
            }
            if(in(ta+tb,0,th))
            {
                if(!vis[ta+tb][0])
                {
                    vis[ta+tb][0]=1;
                    type[ta+tb][0][0]=3;
                    type[ta+tb][0][1]=2;
                    type[ta+tb][0][2]=ta;
                    type[ta+tb][0][3]=tb;
                }
            }
            if(in(0,ta+tb,th))
            {
                if(!vis[0][ta+tb])
                {
                    vis[0][ta+tb]=1;
                    type[0][ta+tb][0]=3;
                    type[0][ta+tb][1]=1;
                    type[0][ta+tb][2]=ta;
                    type[0][ta+tb][3]=tb;
                }
            }
            if(in(A,tb-A+ta,th))
            {
                if(!vis[A][ta-A+tb])
                {
                    vis[A][ta-A+tb]=1;
                    type[A][ta-A+tb][0]=3;
                    type[A][ta-A+tb][1]=2;
                    type[A][ta-A+tb][2]=ta;
                    type[A][ta-A+tb][3]=tb;
                }
            }
            if(in(ta-B+tb,B,th))
            {
                if(!vis[ta-B+tb][B])
                {
                    vis[ta-B+tb][B]=1;
                    type[ta-B+tb][B][0]=3;
                    type[ta-B+tb][B][1]=1;
                    type[ta-B+tb][B][2]=ta;
                    type[ta-B+tb][B][3]=tb;
                }
            }
        }
        if(ans==-1)
        {
            printf("impossible\n");
        }

    }

    return 0;
}
