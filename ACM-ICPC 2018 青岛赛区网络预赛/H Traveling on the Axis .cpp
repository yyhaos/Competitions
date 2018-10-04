#include<bits/stdc++.h>
using namespace std;
//long long j[100005];
long long s[100005];
long long sum[100005];
char j[100005];
long long k[100005];
int main ()
{
    int tt;
    //freopen("test.txt","r",stdin);
    scanf("%d",&tt);
    while(tt--)
    {
        s[0]=0;
        sum[0]=0;
        scanf("%s",j);
        long long n=strlen(j);
        for(long long i=0;i<n;i++)
        {
            if(j[i]=='0')
            {
                k[i+1]=0;
                s[i+1]=s[i];
                if((s[i])&1)
                    s[i+1]++;
                else
                    s[i+1]+=2;
                sum[i+1]=sum[i]+s[i+1];
            }
            else
            {
                k[i+1]=1;
                s[i+1]=s[i];
                if( (s[i])&1)
                    s[i+1]+=2;
                else
                    s[i+1]+=1;
                sum[i+1]=sum[i]+s[i+1];
            }
        }
        long long ans=sum[n];
        //printf("%lld %lld\n",1,t[1]);
        for(long long i=2;i<=n;i++)
        {
            ans+=sum[n]-sum[i-1]-(n-i+1)*(s[i]-2+k[i]);
            //ans+=t[i];// printf("%lld %lld\n",i,t[i]);
        }
        //for(long long i=1;i<=n;i++)
       // {
           // printf("%lld sum:%lld s:%lld k:%lld\n",i,sum[i],s[i],k[i]);
       // }
        printf("%lld\n",ans);
    }
    return 0;
}
