//Problem Web:https://ac.nowcoder.com/acm/contest/883#countdown
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
//const ll maxn=1000;
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
const int maxn=510;
int a[maxn][maxn];
int s[maxn][maxn];
int Max[maxn<<2][maxn<<2] , Min[maxn<<2][maxn<<2];
void Build(int H,int row,int h,int l,int r)
{
    if(l==r)
    {
        Max[H][h]=a[row][l];
        Min[H][h]=a[row][l];
        return ;
    }
    int mid=(l+r)>>1;
    Build(H,row,h<<1,l,mid);
    Build(H,row,h<<1|1,mid+1,r);
    Max[H][h]=max(Max[H][h<<1],Max[H][h<<1|1]);
    Min[H][h]=max(Min[H][h<<1],Min[H][h<<1|1]);
}
void mymerge(int H,int h1,int h2,int h,int l,int r)
{
    if(l==r)
    {
        Max[H][h]=max(Max[h1][h],Max[h2][h]);
        Min[H][h]=min(Min[h1][h],Min[h2][h]);
        return ;
    }
    int mid = (l + r) >> 1;
    mymerge(H,h1,h2,h<<1,l,mid);
    mymerge(H,h1,h2,h<<1|1,mid+1,r);
    Max[H][h] = max(Max[h1][h],Max[h2][h]);
    Min[H][h] = min(Min[h1][h],Min[h2][h]);
}
void build(int h,int l,int r)
{
    if(l == r)
    {
        Build(h,l,1,1,m);
        return ;
    }
    int mid = (l + r) >> 1;
    build(h<<1,l,mid);build(h<<1|1,mid+1,r);
    mymerge(h,h<<1,h<<1|1,1,1,m);
}
int query_max(int H,int h,int l,int r,int q,int w)
{
    if(l == q && r == w)return Max[H][h];
    int mid = (l + r) >> 1;
    if(w <= mid)return query_max(H,h<<1,l,mid,q,w);
    else if(q > mid)return query_max(H,h<<1|1,mid+1,r,q,w);
    else return max(query_max(H,h<<1,l,mid,q,mid),query_max(H,h<<1|1,mid+1,r,mid+1,w));
}

int Query_max(int h,int l,int r,int q,int w,int lls,int rr)
{
    if(l == q && r == w)return query_max(h,1,1,m,lls,rr);
    int mid = (l + r) >> 1;
    if(w <= mid)return Query_max(h<<1,l,mid,q,w,lls,rr);
    else if(q > mid)return Query_max(h<<1|1,mid+1,r,q,w,lls,rr);
    else return max(Query_max(h<<1,l,mid,q,mid,lls,rr),Query_max(h<<1|1,mid+1,r,mid+1,w,lls,rr));
}

int query_min(int H,int h,int l,int r,int q,int w)
{
    if(l == q && r == w)return Min[H][h];
    int mid = (l + r) >> 1;
    if(w <= mid)return query_min(H,h<<1,l,mid,q,w);
    else if(q > mid)return query_min(H,h<<1|1,mid+1,r,q,w);
    else return min(query_min(H,h<<1,l,mid,q,mid),query_min(H,h<<1|1,mid+1,r,mid+1,w));
}

int Query_min(int h,int l,int r,int q,int w,int lls,int rr)
{
    if(l == q && r == w)return query_min(h,1,1,m,lls,rr);
    int mid = (l + r) >> 1;
    if(w <= mid)return Query_min(h<<1,l,mid,q,w,lls,rr);
    else if(q > mid)return Query_min(h<<1|1,mid+1,r,q,w,lls,rr);
    else return min(Query_min(h<<1,l,mid,q,mid,lls,rr),Query_min(h<<1|1,mid+1,r,mid+1,w,lls,rr));
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

ll M;
    while(cin>>n>>M)
    {
        cout<<n<<" "<<M<<endl;
        m=n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%lld",&a[i][j]);
            }
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                s[i][j]=0;
            }
        }
        for(int i=0;i<=n*4;i++)
        {
            for(int j=0;j<=n*4;j++)
            {
                Max[i][j]=Min[i][j]=0;
            }
        }
        build(1,1,n);

        ll ans=0;
        cout<<n<<" "<<m<<endl;
//        ll z=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    for(int l=k;l<=n;l++)
                    {
                        cout<<i<<" "<<j<<" "<<k<<" "<<l<<":"<<Query_max(1,1,n,i,j,k,l)<<" "<<Query_min(1,1,n,i,j,k,l)<<endl;
                    }
                }
            }
        }
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}



