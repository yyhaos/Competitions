#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n;
LL dp[5][700000+5]; //长度+十进制
char tem[1<<18+5];
char tem1[1<<18+5];
LL dfs(char str2[])
{
    int len=strlen(str2);
    char str[len+5];
    strcpy(str,str2);
    int a[4];
    int flag=1;
    memset(a,0,sizeof(a));
     if(len<=20)
    {
        int th;
        for(int i=0;i<len;i+=2)
        {
            int t1=str[i]-'0',t2=str[i+1]-'0';
            if(flag==0)
            {
                for(int k=1;k<=3;k++)
                    a[k]*=2;
            }
            flag=0;
            a[1]+=t1^t2;
            a[2]+=t1&t2;
            a[3]+=t1|t2;
        }
        th=-1;
        while(len>1)
        {
            th++;
            len/=2;
        }
        if(th==-1)
            th=0;
        return dp[th][a[1]]+dp[th][a[2]]+dp[th][a[3]];
    }
    int th=0;
    LL ans=0;
    for(int k=1;k<=3;k++)
   {
       th=0;
       for(int i=0;i<=len-1;i+=2)
        {
            int t1=str[i]-'0';
            int t2=str[i+1]-'0';
            if(k==1) tem1[th++]=(t1^t2)+'0';
            if(k==2) tem1[th++]=(t1&t2)+'0';
            if(k==3) tem1[th++]=(t1|t2)+'0';

        }
            tem1[th]='\0';
            ans+=dfs(tem1);
   }
   return ans;

}
int main ()
{
   // freopen("test.txt","r",stdin);
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    scanf("%s",tem);
    long long ans=0;
    dp[0][1]=1;
    dp[0][0]=0;
    for(int i=1;i<=4;i++)
    {
        int th=1<<i;
        int maxn=1<<th;
        for(int j=0;j<maxn;j++)
        {
            int a[4];
            memset(a,0,sizeof(a));
            int jj=j;
            int flag=1;
            int t1,t2;
            while(jj>0)
            {
                t1=jj%2;
                jj/=2;
                t2=jj%2;
                jj/=2;
                a[1]+=flag*(t1^t2);
                a[2]+=flag*(t1&t2);
                a[3]+=flag*(t1|t2);
                flag*=2;
            }
            dp[i][j]=dp[i-1][a[1]]+dp[i-1][a[2]]+dp[i-1][a[3]];
        }

    }
    printf("%lld",dfs(tem));
    return 0;
}
