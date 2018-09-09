#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

const ll maxn = 10000;
long long sum[maxn+8];
long long a[maxn+5];

long long ksm(ll ret){
    long long b = mod - 2;
    long long ans = 1;
    while(b>0){
        if(b%2 == 1) ans = (ans*ret)%mod;
        ret = (ret*ret)%mod;
        b /= 2;
    }
    return ans;
}

ll ni2=ksm(2);
ll ni6=ksm(6);

void st(){
    a[0] = 0;
    a[1] = 2;
    int inv = ksm(2);
    for(int i = 2;i<=maxn;i++)
        a[i] = ((3*a[i-1]%mod-a[i-2])*inv%mod + i + 1)%mod;
}

ll get_sum2(ll k,ll n)
{

    //printf("n=%lld\n",n);
    ll an;
        ll cnt=n/k;
        an=k*(1+cnt)*cnt%mod*ni2%mod;
        an=(an + k*k%mod*(cnt)%mod*(cnt+1)%mod*(2*cnt+1)%mod*ni6%mod)%mod;
      //  printf("%lld %lld %lld\n",k,n,an);
    return an;
}

ll s(ll i,ll n)
{

        return get_sum2(i,n);


}

ll tmp[50];

int factors(long long m){
    int cnt=0;
    //printf("m=%lld\n",m);
    memset(tmp,0,sizeof(tmp));
    for (ll i=2;i*i<=m;i++){
        if (m%i==0){
            while(m%i==0){
                m/=i;
            }
            tmp[cnt++] = i;
        }
    }
    if (m>1) tmp[cnt++] = m;
    return cnt;
}
ll ans;ll tn,ttm;
int has[4000];
ll dfs(int tk,int aim,int len)
{
    int tcnt=0;
    for(int i=0;i<len;i++)
    {
        if(has[i]==1)
            tcnt++;
    }
    if(tk>=len+1)
    {
        return 0;
    }
    if(tcnt<aim)
    {
        has[tk]=1;
        dfs(tk+1,aim,len);
        has[tk]=0;
        dfs(tk+1,aim,len);
        if(ans<0)
            ans+=mod;
        return 0;
    }
    if(tcnt==aim)
    {
        ll t=1;
        for(int i=len-1;i>=0;i--)
        {
            if(has[i]==1)
            {
                t*=tmp[i];
            }
        }

        if(tcnt%2==1)
        {
            ans=(ans-s(t,tn));
            if(ans<0)
                ans+=mod;
         //   printf("==%lld\n",-s(t,tn));
            return 1;

        }
        else
        {
            ans=(ans+s(t,tn))%mod;
            if(ans<0)
                ans+=mod;
          //  printf("==%lld\n",s(t,tn));
            return 1;

        }
        //printf("t=%d\n",t);

    }
    return 1;
}



int main()
{
    //get_sum(4);
    //for(int i=1;i<=5;i++)
    //{
       // printf("%d %lld\n",i,sum[i]);
    //}
    while(~scanf("%lld%lld",&tn,&ttm))
    {
        memset(sum,0,sizeof(sum));
        //get_sum(tn);
        //printf("m=%lld\n",ttm);

        int cn=factors(ttm);
        ans=s(1,tn);
        for(int len=1;len<=cn;len++)
        {
           // printf("slen=%d\n",len);
            memset(has,0,sizeof(has));
            dfs(0,len,cn);
            if(ans<0)
                ans+=mod;
        }

        printf("%lld\n",ans);
    }
    return 0;
}
