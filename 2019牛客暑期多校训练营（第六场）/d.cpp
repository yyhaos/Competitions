//Problem Web:https://ac.nowcoder.com/acm/contest/886#countdown
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1000;
const ll q=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a%q;
        a=a*a%q;
        b/=2LL;
    }
    return ans;
}

ll t,n,m;
ll k;
ll v[10005];
ll nxt[10005];
int ans;
ll used[10005];
bool test(ll x)
{

    for(int i=0;i<=n;i++)
    {
        nxt[i]=i-1;
    }
//    nxt[0]=0;
    mem(used,0);
    ll rong;
    if(x<v[n-1])
        return false;
    ll fa=n;
    ll pre=n-1;
    ll now=0;
    used[n]=1;
rong=0;
    for(int i=1;i<=ans;i++)
    {

        if(fa<=0)
        {
            return true;
            break;
        }
        if(rong!=0)
        {
            return false;
        }
        rong=x;
        ll th=upper_bound(v,v+n,rong)-v-1;
        pre=th;
        while(th>=0)
        {
//            cout<<th<<" "<<pre<<" "<<nxt[th]<<" "<<rong<<endl;
            if(rong==0)
                break;

            if(used[th])
            {
//                if(th==0)
//                    break;
                th=nxt[th];

                continue;
            }
            if( rong>= v[th] )
            {
                fa--;
                rong-=v[th];
                used[th]++;

                nxt[pre]=nxt[th];

//                if(th==0)
//                    break;
                th=nxt[th];
                continue;
            }
            pre=th;


//            if(th==0)
//                break;
            th=nxt[th];
            continue;
        }
//cout<<"nxt: ";
//
//        for(int i=1;i<=n;i++)
//        {
//            cout<<nxt[i]<<" ";
//        }
//        cout<<endl;
    }
    if(rong!=0)
        {
            return false;
        }
    if(fa<=0)
    {
        return true;
    }
        return false;
}


//int check(int n,int m,int k)
//{
//    for(int i=0;i<n;i++) vis[i]=0;
//    int cnt=0;
//    for(int i=0;i<k;i++){
//        int tmp = m;
//        for(int j=n-1;j>=0;j--){
//            if(!vis[j]&&tmp>=a[j]){
//                cnt++;
//                tmp-=a[j];
//                vis[j]=1;
//            }
//        }
//    }
//    if(cnt==n) return 1;
//    else return 0;
//}

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif
//cout<<"1\n1000 1\n";
//for(int i=0;i<1000;i++)
//    cout<<"1000 ";
#ifdef use_t
ll ii=1;
cin>>t;ll sum=0;
for(ii=1;ii<=t;ii++)
{cout<<"Case #"<<ii<<": ";
#endif // use_t
    cin>>n>>k;
    sum=0;
    ll maxx=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",v+i);
        sum+=v[i];
        maxx=max(v[i],maxx);
    }
    if(k==1)
    {
        cout<<sum<<"\n";
        continue;
    }
    sort(v,v+n);

//    cout<<test(1000)<<endl;
    for(ans=k;ans>=1;ans--)
    {
        if(sum%ans==0)
        {

            if(test( sum/ans ))
            {
                cout<<sum/ans;
                break;
            }
        }
    }




    if(ii!=t)
    {
        cout<<"\n";
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}


