#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll ,int>m;
ll num[200005];
struct peo
{
    ll ty;
    vector <ll > n;
}p[100005];
bool cmp(peo a,peo b)
{
    return a.ty<b.ty;
}
int main ()
{
    ll n;
    ll ty1=0;
    scanf("%I64d",&n);
    for(ll i=1;i<=n;i++)
    {
        ll tmp;
        scanf("%I64d%I64d",&p[i].ty,&tmp);
        ll t1;
        if(p[i].ty==1)
            ty1++;
        while(tmp--)
        {
            scanf("%I64d",&t1);

            p[i].n.push_back(t1);
        }
    }
    sort(p+1,p+1+n,cmp);
    ll cnt=0;
    ll flag=0;
    for(ll i=1;i<=n;i++)
    {
        if(p[i].ty==1)
        {
            ll tmp;
            flag=1;
            ll si=p[i].n.size();
            for(ll j=0;j<si;j++)
            {
                tmp=p[i].n[j];
                if(m[tmp]==0)
                {
                    num[cnt++]=tmp;
                    m[tmp]=1;
                }
                else
                    m[tmp]++;
            }
        }
        else
        {
            ll tmp;
            ll si=p[i].n.size();
            for(ll j=0;j<si;j++)
            {
                tmp=p[i].n[j];
                if(m[tmp]==0)
                {
                    num[cnt++]=tmp;
                    m[tmp]=-1;
                }
                else if(m[tmp]>=1)
                {
                    m[tmp]=-1;
                }
            }
        }
    }
    ll ans=0;
    if(flag==0)
    {
        for(ll i=0;i<cnt;i++)
        {
            if(m[num[i]]==-1)
            {
                ans++;
            }
        }
        printf("%lld\n",1000000000000000000LL-ans);
    }
    else
    {
        for(ll i=0;i<cnt;i++)
        {
            if(m[num[i]]==ty1)
            {
               // printf("%I64d\n",num[i]);
                ans++;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
