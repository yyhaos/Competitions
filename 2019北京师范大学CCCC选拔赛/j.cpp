//Problem Web:
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
using namespace std;

#define ll long long
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
const ll INF = 1000000000000LL;
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
ll a[1000400];
ll t,n,m;
bool ge(ll th)
{
    string tmp;
    if(cin>>tmp)
    {
      //  cout<<"th"<<th<<" "<<tmp<<endl;
        if(tmp=="null")
        {
            a[th]=INF;
            //return false;
        }
        else
        {
            int cnt=1;
            a[th]=0;
            for(int i=tmp.size()-1;i>=0;i--)
            {
                a[th]+=cnt*(tmp[i]-'0');
                cnt*=10;
            }
        }
        return true;
    }
    return false;
}
bool dfs(int th,ll mi,ll ma)
{
    if(a[th]==INF)
        return true;
    int n1=th*2;
    int n2=th*2+1;
    //cout<<"fa  "<<th<<" "<<mi<<" "<<ma<<endl;
    if(a[n1]!=INF && (a[n1] > a[th] || a[n1] <mi || a[n1]>ma))
    {
        //cout<<"fa 1 "<<th<<" "<<mi<<" "<<ma<<endl;
        return false;
    }
    if(a[n2]!=INF &&(a[n2] < a[th] || a[n2] <mi || a[n2]>ma))
    {
        //cout<<"fa 2 "<<th<<" "<<mi<<" "<<ma<<endl;
        return false;
    }
    return dfs(n1,mi,min(ma,a[th])) && dfs(n2,max(mi,a[th]),ma);
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
rep(i,1,1000000)
    {
        a[i]=INF;
    }
    cin>>a[1];
    ll sum=2;

    for(int i=2;i<=sum;)
    {
        //cout<<"i:"<<i<<" ";
//        for(int i=1;i<=sum;i++)
//        {
//            cout<<a[i]<<" ";
//        }
        //cout<<endl;
        if(a[i/2] !=INF )
        {
            if(ge(i))
            {
                sum+=2;
            }
        }
        i++;
    }
    if(dfs(1,-INF,INF))
    {
        cout<<"Y";
    }
    else
        cout<<"N";




#ifdef use_t
}
#endif // use_t
    return 0;
}

