
#include<bits/stdc++.h>
using namespace std;
const int maxn=75321+5;
int is[maxn+5];
char num[1005];
int has[4000];
int tem[50];
int flag=0;
int dfs(int tk,int aim,int len)
{


    int tcnt=0;
    for(int i=0;i<len;i++)
    {
        if(has[i]==1)
            tcnt++;
    }
    if(tk>=aim+3)
    {
        return 1;
    }
    if(tcnt<aim)
    {
        has[tk]=1;
        flag=min(flag,dfs(tk+1,aim,len));

        has[tk]=0;
        flag=min(flag,dfs(tk+1,aim,len));
        return 0;
    }
    if(tcnt==aim)
    {
        int t=0;
        for(int i=len-1;i>=0;i--)
        {
            if(has[i]==1)
            {
                t*=10;
                t+=tem[i];
            }
        }
        //printf("t=%d\n",t);
        if(is[t]==1)
            return 1;
        else
            return -1;
    }

}
int p[maxn];
int pp=0;
int ok[maxn+5];
int main ()
{
    int sum=0;
    memset(is,0,sizeof(is));
    is[1]=1;
    for(int i=2;i<=maxn;i++)
    {
        if(is[i]==0)
        {
            is[i]=1;
            sum++;
            for(int j=2*i;j<=maxn;j+=i)
            {
                is[j]=-1;
            }
        }
    }
    for(int i=2;i<=maxn;i++)
    {
        if(is[i]==-1)
            continue;
        else
        {
            if(i==13)
            {
                i=13;
            }
            //printf("i=%d\n",i);
            ok[i]=1;
            int th=0;
            memset(tem,0,sizeof(tem));
            int ti=i;
            while(ti>0)
            {
                tem[th++]=ti%10;
                ti/=10;
            }
            //int flag=0;
            flag=0;
            for(int len=1;len<=th;len++)
            {
                memset(has,0,sizeof(has));
                flag=min(flag,dfs(0,len,th));
            }
            if(flag==-1)
                ok[i]=-1;
            else
            {
                ok[i]=1;
                p[pp++]=i;
            }
        }
    }
    //printf("sum=%d\n",sum);

    int t;
    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {
        int  ans=0;
        scanf("%s",num);
        if(strlen(num)>=4)
        {
            ans=317;
        }
        else
        {
            int n=0;
            for(int i=0;i<=strlen(num)-1;i++)
            {
                n*=10;
                n+=num[i]-'0';
            }
            //printf("%d\n",n);
            if(n>=317)
            {
                ans=317;
            }
            if(n<=1)
            {
                ans=n;
            }
            else
            {
                int pos=upper_bound(p,p+pp,n)-p;
                ans=p[pos-1];
            }
        }
        printf("Case #%d: %d\n",ii,ans);
    }
    return 0;
}
