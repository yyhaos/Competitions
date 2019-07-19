
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
char ans[15][15];
ll st=1;
void draw(ll x,ll y)
{
 //   cout<<x<<" "<<y<<endl;
    ans[x][y]=1;
    ans[x][y+1]=1;
    ans[x][y+2]=1;
    ans[x+1][y+1]=1;
    ans[x][y+3]=3;
    ans[x+1][y+3]=3;
    ans[x+2][y+3]=3;
    ans[x+1][y+2]=3;

    ans[x+1][y]=2;
    ans[x+2][y]=2;
    ans[x+3][y]=2;
    ans[x+2][y+1]=2;
    ans[x+3][y+2]=4;
    ans[x+3][y+3]=4;
    ans[x+3][y+1]=4;
    ans[x+2][y+2]=4;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            ans[i+x][j+y]+='0';
        }
    }

}

string a;
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
        if(n%4!=0 || m%4!=0 || n<4 || m<4)
    {
        cout<<"no response\n";
       // return 0;
       continue;
    }
    ll z=n/4;
    ll h=m/4;

    for(int i=0;i<n;i+=4)
    {
        for(int j=0;j<m;j+=4)
        {
            draw(i,j);
        }
    }
    for(int i=0;i<n;i++)
    {
        ans[i][m]='\0';
    }
    for(int i=0;i<n;i++)
    {
//        if(i)
//            cout<<'\n';
        printf("%s\n",ans[i]);

    }
    }

   // cout<<endl;





#ifdef use_t
}
#endif // use_t
    return 0;
}
