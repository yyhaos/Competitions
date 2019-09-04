//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=853
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
struct trash
{
    ll x,y,w,th;
    friend bool operator < (trash a, trash b)
    {
        if(a.x!=b.x)
        {
            return a.x<b.x;
        }
        return a.y<b.y;
    }
}tr[2005];
struct xpai
{
    ll x,th;
    friend bool operator < (xpai a, xpai b)
    {
        return a.x<b.x;
    }
}xx[2005], yy[2005];
ll xth[2005];
ll yth[2005];
//ll thx[2005];
//ll thy[2005];
map<ll , ll > yyth;
//map<ll , ll > thx;
map<ll , ll > xxth;
//map<ll , ll > thy;
ll mws[2005][2005];
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
    yyth.clear();
    xxth.clear();
//    xth.clear();
//    yth.clear();
#endif // use_t
ll maxx=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&tr[i].x,&tr[i].y,&tr[i].w );
    }
    sort(tr+1,tr+n+1);

    for(int i=1;i<=n;i++)
    {

        tr[i].th=i;
        xx[i].x=tr[i].x;
        xx[i].th=i;
        yy[i].th=i;
        yy[i].x=tr[i].y;
    }
    sort(xx+1,xx+1+n);
    sort(yy+1,yy+1+n);
    ll cx=1,cy=1;
    for(int i=1;i<=n;i++)
    {
//        cout<<xx[i].x<<' '<<yy[i].x<<" = "<<i<<endl;
//        xth[xx[i].th]=i;
//
//        if(xx[i].x == xx[i+1].x)
//        {
//
//        }
        if(xxth[xx[i].th]==0)
        {
            xxth[xx[i].th]=cx++;
        }
        if(yyth[yy[i].th]==0)
        {
            yyth[yy[i].th]=cy++;
        }

//        thx[i]=xx[i].x;
//        yth[yy[i].th]=i;
//        thy[i]=yy[i].x;
    }
    for(int i=1;i<=n;i++)
    {
//        cout<<xx[i].x<<' '<<yy[i].x<<" = "<<i<<endl;
        xth[ i] = xxth[xx[i].x];
        yth[ i] = yyth[yy[i].x];
//        yth[i]=yyth[yy[i].x];
//        thx[i]=xx[i].x;
//        yth[yy[i].th]=i;
//        thy[i]=yy[i].x;
    }
    ll ti,tj;
    mem(mws,0);
    for(int i=1;i<=n;i++)
    {
        ti=xth[i];
        tj=yth[i];
//        cout<<ti<<" "<<tj<<" = "<<tr[i].w<<endl;
        mws[ti][tj] += tr[i].w;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mws[i][j]=mws[i][j]+mws[i-1][j]+mws[i][j-1]-mws[i-1][j-1];
//            cout<<mws[i][j]<<" ";
        }
//        cout<<endl;
    }

    ll zuo,you,shang,xia;
    ll ti2,tj2;
    xth[0]=0;
    yth[0]=0;
    xth[n+1]=n+1;
    yth[n+1]=n+1;
    for(int i=0;i<=n+1;i++)
    {
        ti=xth[i];
        tj=yth[i];
        for(int j=i;j<=n+1;j++)
        {
            ti2=xth[j];
            tj2=yth[j];
            xia=min(ti2,ti);
            shang=max(ti2,ti);
            zuo=min(tj2,tj);
            you=max(tj2,tj);
            maxx=max(maxx, mws[shang][you] +mws[xia][zuo] -mws[shang][zuo]-mws[xia][you] );
        }
    }

    cout<<maxx<<"\n";




#ifdef use_t
}
#endif // use_t
    return 0;
}


