//Problem Web:  https://vjudge.net/contest/290417?tdsourcetag=s_pcqq_aiomsg#problem/C
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
ll M[105][105];

ll ta[4][2]={0,1,0,-1,1,0,-1,0};
char K[105][105];
ll t,n,m;
ll x,y;
struct poi
{
    ll x, y,th;
    poi(ll _x=1,ll _y=1,ll _th=1)
    {
        x=_x;
        y=_y;
        th=_th;
    }
};

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
    while(~scanf("%lld%lld%lld",&n,&x,&y))
    {
        memset(M,0,sizeof(M));
        for(int i=0;i<n;i++)
        {
            scanf("%s",K[i]);
           // cout<<K[105]<<endl;
        }

        //mem(M,0);

        queue<poi> q;
        q.push(poi(x-1,y-1,1));
        M[x-1][y-1]=1;

        while(!q.empty())
        {

            poi tt=q.front();
            q.pop();
           // cout<<tt.x<<" "<<tt.y<<"  "<<K[tt.x][tt.y]<<endl;


            if(K[tt.x][tt.y]=='#')
            {
                cout<<M[tt.x][tt.y]<<endl;
                break;
            }
            ll nx,ny;
            for(int i=0;i<4;i++)
            {
                nx=tt.x+ta[i][0];
                ny=tt.y+ta[i][1];
                if(nx<n && nx>-1 && ny<n && ny>-1)
                {
                    if(M[nx][ny]==0)
                    {
                        M[nx][ny]=tt.th+1;
                        q.push(poi(nx,ny,tt.th+1));
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
