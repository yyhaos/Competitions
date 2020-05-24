//Problem Web:≤‚∆¿ŒﬁÃ‚ƒø
#include<bits/stdc++.h>
#include<ext/rope> //using __gnu_cxx
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define ll __int128
#define mll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
//#define use_t 1
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

ll t,n,m,p;
bool check(mll sum){
    ll now=0;
    ll nd=0;
    ll tn=n,tm=m;
    while(nd<=sum){
           // cout<<"money:"<<now<<" day:"<<nd<<" sday:"<<sum<<" n:"<<tn<<" m:"<<tm<<endl;

        ll tsum= now+ (sum-nd)*tn*tm;
        if(tsum>=t){
         //   cout<<"tsum:"<<tsum<<" out"<<endl;

            return true;
        }

        ll dq= ((p-nd)+tn*tm-1 )/(tn*tm);
        if(dq<0)dq=0;


        now+=dq*tn*tm;
        nd+=dq;


        //cout<<"dq:"<<dq<<endl;

        if(nd>sum){
       //         cout<<"outoftime"<<endl;
            break;
        }



        ll butou = now+ (sum-nd)*tn*tm;
        ll tou=0;
        if(tn>tm)swap(tn,tm);
        tou = now+(sum-nd) * (tn+1)*tm -p;

//        cout<<"tou:"<<tou<<" butou:"<<butou<<endl;

            tn++;
            now-=p;

        nd++;
        now+=tn*tm;

        if(tou>=t){
         //   cout<<"tou:"<<tou<<" out"<<endl;
            return true;
        }
    }
    return false;
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

mll an,am,ap,aat;
    cin>>an>>am>>ap>>aat;
    n=an;m=am;p=ap;t=aat;

    mll l=1,r=t;
    while(l<r){
        mll mid=(l+r)/2;
        if(check(mid)){
            r=mid-1;
        }
        else
            l=mid+1;
    }
    for(mll i=max(1LL,l-3);i<=l+3;i++){
        if(check(i)){
            cout<<i;
            break;
        }
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}


