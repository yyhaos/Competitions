//Problem Web:
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
string M[105];
ll dis[105][105];
ll Kx[55],Ky[55];
struct pos
{
    ll x,y,th;
    pos(ll _x=0,ll _y=0, ll _th=0)
    {
        x=_x;y=_y;th=_th;
    }
};
ll fx[4]={0,0,1,-1};
ll fy[4]={-1,1,0,0};
ll dfs(ll sx,ll sy)
{
    mem(dis,0);
    queue<pos> mq;
    mq.push(pos(sx,sy,-1));
    while(!mq.empty())
    {
        pos tt=mq.front();
        mq.pop();
        if(dis[tt.x][tt.y]!=0 || (tt.x==sx && tt.y==sy && tt.th!=-1) || M[tt.x][tt.y]=='#')
            continue;
        dis[tt.x][tt.y]=tt.th;
        ll nx,ny,nth;
        for(int i=0;i<4;i++)
        {
            nx=tt.x+fx[i];
            ny=tt.y+fy[i];

            if(nx<0 || nx>=n || ny<0 || ny>=m || M[nx][ny]=='#' || dis[nx][ny]!=0)
                continue;
            if(tt.th!=-1)
            nth=tt.th+1;
            else
                nth=1;
//            cout<<nx<<"-"<<ny<<" "<<nth<<endl;
            mq.push(pos(nx,ny,nth));
        }
    }
////    cout<<"dis:"<< sx<<" "<<sy<<endl;
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<m;j++)
//        {
//            cout<<dis[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
ll ds[6][6];
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
    while(cin>>n>>m)
    {
        if(n==0)
            return 0;
        getchar();
        for(int i=0;i<n;i++)
        {
            cin>>M[i];
//            cout<<M[i]<<endl;
        }
        ll k;
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            scanf("%lld%lld",&Kx[i],&Ky[i]);
            Kx[i]--;
            Ky[i]--;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]=='@')
                {
                    Kx[0]=i;
                    Ky[0]=j;
                }
            }
        }


//        for(int i=0;i<=k;i++)
//        {
//            cout<<Kx[i]<<" "<<Ky[i]<<endl;
//        }

        for(int i=0;i<=k;i++)
        {
            dfs(Kx[i],Ky[i]);
            for(int j=0;j<=k;j++)
            {
                ds[i][j]=dis[Kx[j]][Ky[j]];
                if(ds[i][j]==0)
                    ds[i][j]=INF;
            }
        }
        ll now[10];
        now[0]=0;
        for(int i=1;i<=k;i++)
        {
            now[i]=i;
        }
        ll tmp;
        ll ans=INF;
//        for(int i=0;i<=k;i++)
//        {
//            for(int j=0;j<=k;j++)
//            {
//                cout<<ds[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        tmp=0;
            for(int i=0;i<k;i++)
            {
                tmp+=ds[now[i]][now[i+1]];
            }
            ans=min(ans,tmp);
        while(next_permutation(now,now+k+1))
        {
////            cout<<"now:";
//            for(int i=0;i<=k;i++)
//            {
//                cout<<" "<<now[i];
//            }
//            cout<<endl;
            if(now[0]!=0)
                break;
            tmp=0;
            for(int i=0;i<k;i++)
            {
                tmp+=ds[now[i]][now[i+1]];
            }
            ans=min(ans,tmp);
//            if(ans==tmp)
//            {
//                cout<<"tmp:"<<tmp;
//                for(int i=0;i<=k;i++)
//                {
//                    cout<<" "<<now[i];
//                }
//                cout<<endl;
//            }
        }
        if(ans>=INF)
        {
            ans=-1;
        }
        cout<<ans<<"\n";

    }





#ifdef use_t
}
#endif // use_t
    return 0;
}

