//Problem Web:https://vjudge.net/contest/318541
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
char yuan[105][105];
char str[10005];
ll cnt=0;
ll nx,ny;
void dfs1(ll x,ll y, ll fx)
{
    str[cnt++]=yuan[x][y];
    if(fx==1) // ×óÏÂ µ½ ÓÒÉÏ
    {
        nx=x-1;
        ny=y+1;
        if(nx >=0 && ny<n)
        {
            dfs1(nx,ny,1);
        }
        else
        {
            nx=x;
            ny=y+1;
            if(ny<n)
            {
                dfs1(nx,ny,0);
            }
            else
            {
                nx=x+1;
                ny=y;
                if(nx<n)
                {
                    dfs1(nx,ny,0);
                }
            }
        }
    }
    else
    {
        nx=x+1;
        ny=y-1;
        if(nx<n && ny>=0)
        {
            dfs1(nx,ny,0);
        }
        else
        {
            nx=x+1;
            ny=y;
            if(nx<n)
            {
                dfs1(nx,ny,1);
            }
            else
            {
                nx=x;
                ny=y+1;
                if(ny<n)
                {
                    dfs1(nx,ny,1);
                }
            }
        }
    }
}
void getstr(ll n)
{
    cnt=0;
    dfs1(0,0,1);

//    for(int i)
    str[n*n]=0;

//    cout<<str<<endl;
}
ll used[105][105];
ll fx[4]={0,1,0,-1};
ll fy[4]={1,0,-1,0};
void dfs2(ll x,ll y,ll tfx)
{
    used[x][y]=1;
    yuan[x][y]=str[cnt++];
    ll tx=0;
    for(ll i=0;i<=3;i++)
    {
        tx=(tfx+i)%4LL;

        nx=fx[tx]+x;
        ny=fy[tx]+y;
        if(nx<n && ny<n && nx>=0 && ny>=0 && used[nx][ny]==0)
        {
            dfs2(nx,ny,tx);
            break;
        }
    }

}
void form(ll n)
{
    cnt=0;
    mem(used,0);
    dfs2(0,0,0);
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
//for(int i=1;i<=100;i++)
//{
//    cout<<i<<endl;
//    for(int k=1;k<=i;k++)
//    {
//        for(int j=1;j<=i;j++)
//        {
//            cout<<char('a'+(j*k)%26);
//        }
//        cout<<endl;
//    }
//}
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    while(cin>>n)
    {
        cout<<n<<endl;
        getchar();
        for(int i=0;i<n;i++)
        {
            scanf("%s",yuan[i]);
        }
        getstr(n);
        form(n);
        for(int i=0;i<n;i++)
        {
            printf("%s\n",yuan[i]);
        }
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}

