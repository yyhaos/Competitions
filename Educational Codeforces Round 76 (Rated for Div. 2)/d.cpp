//https://codeforces.com/contests/1257
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll q=1e9+7;
ll ksm(ll a, ll b){
    ll ans=1;while(b){
        if(b&1){
            ans=ans*a%q;
        }a=a*a%q;b/=2;
    }return ans;
}
ll a[302005];
struct her
{
    ll p,s;
    friend bool operator < (her a,her b){
        if(a.p==b.p)return a.s<b.s;
        else return a.p<b.p;
    }
}h[300045],th[300405];
signed main ()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    #endif // yyhao
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        ll m;
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++){
            scanf("%lld",a+i);
        }
        scanf("%lld",&m);
        ll maxn=0;
        for(ll i=1;i<=m;i++){
            scanf("%lld%lld",&h[i].p,&h[i].s);
            maxn=max(maxn,h[i].p);
        }
        int ffa=1;
        for(ll i=1;i<=n;i++){
            if(a[i]>maxn)
            {
                ffa=0;
            }
        }
        if(ffa==0)
        {
            printf("-1\n");
            continue;
        }
        sort(h+1,h+1+m);
        ll cnt=0;
        ll pp=h[m].p,ps=h[m].s;
        th[cnt++]=h[m];
        for(ll i=m-1;i>=1;i--)
        {
            if(ps>=h[i].s)continue;
            else{
                th[cnt++]=h[i];
                pp=h[i].p;
                ps=h[i].s;
            }
        }
        sort(th,th+cnt);
//        for(ll i=0;i<cnt;i++)
//        {
//            printf("%lld %lld  -\n",th[i].p,th[i].s);
//        }
        ll ans=0;
        for(ll i=1;i<=n;){
            her tmp;
        tmp.p=a[i];
        tmp.s=0;
            ll pos=lower_bound(th,th+cnt,tmp)-th;
//            printf("%lld %lld\n",pos,i);
            if(pos >=cnt){
//                    printf("1111\n");
//                    error<<"chao"<<endl;
                ans=-1;break;
            }
            ll st=i;
            ll max_nai=th[pos].s+i-1;
            for(st = i;st<=max_nai;st++){
                if(a[st]<=th[pos].p)continue;
                else{
//                        st--;
                    tmp.p=a[st];tmp.s=0;
                    ll pos2=lower_bound(th,th+cnt,tmp)-th;
//                    if(pos2>=cnt){
//                        //printf("122111\n");
//                        ans=-1;break;
//                    }
                    if(th[pos2].s >= st-i+1){// huan
                        pos=pos2;
                        max_nai=th[pos2].s+i-1;
                    }
                    else{// bu ru bu huan
                        st--;
                        break;
                    }
                }
            }

            if(ans==-1)break;
            if(st>max_nai)st=max_nai;
            i=st+1;
            ans++;
        }

    printf("%lld\n",ans);
    }
    return 0;
}


