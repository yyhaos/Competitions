//Problem Web:https://vjudge.net/contest/355936#problem/B
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
ll nxt[36][100005];
char a[100005];
char b[100005];
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
    for(int i=0;i<36;i++)
    {
        for(int j=0;j<100005;j++)
        {
            nxt[i][j]=-1;
        }
    }
    scanf("%s%s",a,b);
    ll s1=strlen(a),s2=strlen(b);
    for(int i=s1-1;i>=0;i--)
    {
        for(int j=0;j<36;j++)
        {
            nxt[j][i]=nxt[j][i+1];
        }
        nxt[a[i]-'a'][i]=i;
    }
//    for(int i=0;i<5;i++)
//    {
//        cout<<char(i+'a')<<":";
//        for(int j=0;j<6;j++)
//        {
//            cout<<nxt[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    int fa=1;
    int ci=1;
    int th=0;
    for(int i=0;i<s2;i++)
    {
        int now=b[i]-'a';

//        cout<<char(b[i])<<" "<<ci<<" "<<th<<" "<<nxt[now][th]<<endl;
        if(nxt[now][th]==-1 && th==0)
        {
            ci=-1;break;
        }
        if(nxt[now][th]==-1)
        {
            th=0;
            ci++;
            i--;
            continue;
        }
        th=nxt[now][th]+1;

    }

    printf("%d\n",ci);




#ifdef use_t
}
#endif // use_t
    return 0;
}

