//Problem Web:fastvj.rainng.com/contest/290417#problem/F
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
#define use_t 1
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
    friend bool operator < (poi a, poi b)
    {
        return a.th>b.th;
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
{ priority_queue<poi> q;
#endif // use_t
    scanf("%lld%lld",&n,&m);
        memset(M,0,sizeof(M));
        for(int i=0;i<n;i++)
        {
            scanf("%s",K[i]);
            //cout<<K[i]<<endl;
        }
        ll ex,ey;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            //cout<<i<<" "<<j<<endl;
            if(K[i][j]=='S')
            {
                //cout << i<< j<<endl;
                q.push(poi(i,j,1));

                M[i][j]=1;
            }
            if(K[i][j]=='E')
            {
                ex=i;
                ey=j;
            }
        }
    }
   // cout<<"11"<<endl;
        mem(M,0);





        while(!q.empty())
        {
//cout<<"11"<<endl;
            poi tt=q.top();
            q.pop();
           // cout<<tt.x<<" "<<tt.y<<" "<<tt.th<<"  "<<K[tt.x][tt.y]<<endl;


            if(K[tt.x][tt.y]=='#')
            {
                //cout<<M[tt.x][tt.y]<<endl;
                continue;
            }
            ll nx,ny;
            for(int i=0;i<4;i++)
            {
                nx=tt.x+ta[i][0];
                ny=tt.y+ta[i][1];
                if(nx<n && nx>-1 && ny<m && ny>-1)
                {
                    if(M[nx][ny]==0 && M[nx][ny]!='#')
                    {
                        M[nx][ny]=tt.th+1;
                        q.push(poi(nx,ny,tt.th+1));
                    }
                }
            }
            if(K[tt.x][tt.y]=='O')
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(K[i][j]=='O')
                        {
                            if(M[i][j]==0)
                            {
                                M[i][j]=tt.th;
                                q.push(poi(i,j,tt.th));
                            }
                        }
                    }
                }
                //cout<<M[tt.x][tt.y]<<endl;
 //               continue;
            }
        }

        if(M[ex][ey]!=0)
            cout<<M[ex][ey]-1<<endl;
        else
            cout<<"impossible"<<endl;




#ifdef use_t
}
#endif // use_t
    return 0;
}
