//Problem Web:https://vjudge.net/problem/¼ÆËâ¿Í-T1180
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
int p[2][2][1005];
int cnt[2][2];
ll np[1005];
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
    char tt;
    int i=0,j=0;mem(cnt,0);mem(p,0);
    while(~scanf("%c",&tt))
    {
        if(tt=='.')
        {
            j=1;continue;
        }
        if(tt=='\n')
        {
            i=1;j=0;continue;
        }
        p[i][j][cnt[i][j]++]=tt-'0';
    }
//    cout<<cnt[0][0]<<" "<<cnt[0][1]<<" "<<cnt[1][0]<<" "<<cnt[1][1]<<endl;
ll jin=0;
    for(int i=max(cnt[0][1],cnt[1][1]);i>=0;i--)
    {
        p[0][1][i]+=p[1][1][i];
        if(p[0][1][i]>=10)
        {
            p[0][1][i]-=10;
            if(i>=1)
            p[0][1][i-1]++;
            else
            {
                jin++;
            }
        }
    }
//    for(int i=0;i<=40;i++)
//        cout<<p[0][1][i];
//    cout<<endl;
    mem(np,0);
    np[0]=jin;
    for(int i=0;i<cnt[0][0]/2;i++)
    {
        swap(p[0][0][i],p[0][0][ cnt[0][0]-1-i]);
    }
    for(int i=0;i<cnt[1][0]/2;i++)
    {
        swap(p[1][0][i],p[1][0][ cnt[1][0]-1-i]);
    }
    for(int i=0;i<max(cnt[0][0],cnt[1][0]);i++)
    {
        np[i]+=p[0][0][i]+p[1][0][i];
        if(np[i]>=10)
        {
            np[i+1]++;np[i]%=10;
        }
    }
    int fi=1;
    for(int i=104;i>=0;i--)
    {
        if(fi==0)
        {
            cout<<np[i];continue;
        }
        if(np[i]!=0)
        {
            fi=0;
            cout<<np[i];
        }
        if(i==0 && fi==1)
        {
            cout<<0;
        }
    }

    cout<<'.';
    int tfi=0;
    for(int i=104;i>=0;i--)
    {
        if(p[0][1][i]!=0)
        {
            tfi=i;
//    cout<<tfi<<endl;
            break;
        }
    }
//    cout<<tfi<<endl;
    for(int i=0;i<=tfi;i++)
    {
        cout<<p[0][1][i];
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}

