//Problem Web:http://www.bnuoj.com/contest_problem_merge.php?cid=9518
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

ll t,n,m;
ll ans=0;
//bool dao[10005][10005];
ll x,y;
ll cnt=1;
ll now=0;


struct pos
{
    ll x,y;
    ~pos(){}
    pos(){}
    pos(ll _x,ll _y)
    {
        x=_x;y=_y;
    }
    friend bool operator<(pos a,pos b)
    {
        if(a.x!=b.x)
        return a.x<b.x;
        return a.y<b.y;
    }
}pp[3000005];
map < pos, bool> mm;
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

//    ll x,y;
    cin>>x>>y>>n;
mm.clear();
    now=0;
    cnt=1;
ll ans=0;
//ll tx,ty;

    pp[0].x=pp[0].y=0;

    ll tx,ty;
    while(now<cnt)
    {
//        if(cnt>1e7)
//        {
//            cout<<now<<" "<<cnt<<endl;
//        cout<<pp[now].x<<" "<<pp[now].y<<endl;}
        tx=pp[now].x;ty=pp[now].y;
        if(mm[pos(tx,ty)]==true )
        {
            now++;
            continue ;
        }
        mm[pos(tx,ty)]=true;
        if(tx==x && ty==y)
        {
            ans=1;
            break ;
        }
        if(tx+n <= x && ty+n+1 <=y)
        {
            if(mm[pos(tx+n,ty+n+1)]==false)
            {
                //dfs(tx+n,ty+n+1);
                pp[cnt].x=tx+n;
                pp[cnt++].y=ty+n+1;
            }
        }
        if(tx+n+1 <= x && ty+n <=y)
        {
            if(mm[pos(tx+n+1,ty+n)]==false)
            {
                pp[cnt].x=tx+n+1;
                pp[cnt++].y=ty+n;
            }
        }
        now++;
    }

    if(ans)
    {
        cout<<"Yes";
    }
    else
        cout<<"No";


#ifdef use_t
}
#endif // use_t
    return 0;
}

