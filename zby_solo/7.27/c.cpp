//Problem Web:https://vjudge.net/contest/315213#problem/C
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
ll encode[300][50];
void get(ll pos,ll tar)
{
    ll cnt=4;
    while(tar)
    {
        if(tar%2)
        {
            encode[pos][cnt]=1;
        }
        else
        {
            encode[pos][cnt]=0;
        }
        cnt--;
        tar/=2;
    }
    while(cnt>0)
    {
        encode[pos][cnt]=0;
        cnt--;

    }
}
ll now[100000];

ll used[1000][1000];

void dfs(ll r,ll c,ll len,ll tx,ll ty,ll tn,ll ti, string fx)
{
//    cout<<tx<<" "<<ty<<" "<<fx<<endl;
    ll tmp;
//    cout<<len<<" "<<now[tn]<<" "<<ti<<" "<<encode[now[tn]][ti]<<":";
    if(tn<len)
    {
        tmp=encode[now[tn]][ti];
    }
        ti++;
        if(ti>=5)
        {
            ti=0;
            tn++;
        }
    if((tn>=len && ti>=1) || tn>len) tmp=0;
//    tmp=(tn*5+ti)%8;
//    tmp++;
//    cout<<tmp<<endl;
used[tx][ty]=tmp+1 ;
    if(fx=="you")
    {
        if( ty+1<c && used[tx][ty+1]==0 )
        {

            dfs(r,c,len,tx,ty+1,tn,ti,"you");
        }
        else if( tx+1<r && used[tx+1][ty]==0 )
        {
//            used[tx+1][ty]=tmp;
            dfs(r,c,len,tx+1,ty,tn,ti,"xia");
        }
    }
    else if(fx=="xia")
    {
        if( tx+1<r && used[tx+1][ty]==0 )
        {
//            used[tx+1][ty]=tmp;
            dfs(r,c,len,tx+1,ty,tn,ti,"xia");
        }
        else if( ty-1>=0 && used[tx][ty-1]==0 )
        {
//            used[tx][ty-1]=tmp;
            dfs(r,c,len,tx,ty-1,tn,ti,"zuo");
        }
    }
    else if(fx=="zuo")
    {
        if( ty-1>=0 && used[tx][ty-1]==0 )
        {
//            used[tx][ty-1]=tmp;
            dfs(r,c,len,tx,ty-1,tn,ti,"zuo");
        }
        else if( tx-1>=0 && used[tx-1][ty]==0 )
        {
//            used[tx-1][ty]=tmp;
            dfs(r,c,len,tx-1,ty,tn,ti,"shang");
        }
    }
    else if(fx=="shang")
    {
        if( tx-1>=0 && used[tx-1][ty]==0 )
        {
//            used[tx-1][ty]=tmp;
            dfs(r,c,len,tx-1,ty,tn,ti,"shang");
        }
        else if( ty+1<c && used[tx][ty+1]==0 )
        {
//            used[tx][ty+1]=tmp;
            dfs(r,c,len,tx,ty+1,tn,ti,"you");
        }
    }

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

    for(int i=0;i<=28;i++)
    {
        get(i,i);
    }
//    for(int i=0;i<=27;i++)
//    {
//        for(int j=0;j<5;j++)
//        {
//            cout<<encode[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    ll r,c;
    string str;
    cin>>r>>c;
    getline(cin,str);
//    cout<<str<<endl;
    ll len=0;
    for(int i=1;str[i];i++)
    {
        len++;
        if(str[i]==' ')
            now[i-1]=0;
        else
            now[i-1]=1+str[i]-'A';
    }
mem(used,0);
    dfs(r,c,len,0,0,0,0,"you");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<used[i][j]-1;
        }
//        cout<<endl;
    }

#ifdef use_t
}
#endif // use_t
    return 0;
}

