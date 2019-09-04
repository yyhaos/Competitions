//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=855
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
ll myc(ll d,ll x)
{

    ll cnt=0;
    while(x)
    {
        if(x%10==d)
        cnt++;
    x/=10;
    }
    return cnt;
}
ll d9[3000]={
0,10000000000,20000000000,30000000000,
 40000000000,50000000000,60000000000,70000000000,
 80000000000
};
ll d8[3000]={
0,9465000000,9486799989,9486799990,9486799991,
 9486799992,9486799993,9486799994,9486799995,
 9486799996,9486799997,9497400000,9498399989,
 9498399990,9498399991,9498399992,9498399993,
 9498399994,9498399995
};
ll d7[3000]={0,0,9465000000,9471736170,9500000000,9757536170,
 9965000000,9971736170,10000000000,19465000000,
 19471736170,19500000000,19757536170,19965000000,
 19971736170,20000000000,29465000000,29471736170};
ll d6[3000]={
0,9500000000,9628399986,9628399987,9628399988,
 9628399989,9628399990,9628399991,9628399992,
 9628399993,9628399994,9628399995,10000000000,
 19500000000,19628399986,19628399987,19628399988,
 19628399989};
ll d4[3000]={0,499999984,499999985,499999986,499999987,
 499999988,499999989,499999990,499999991,499999992,
 499999993,500000000,10000000000,10499999984,
 10499999985,10499999986,10499999987,10499999988,
 10499999989
};
ll d5[3000]={
0,10000000000,20000000000,30000000000,
 40000000000};
ll d1[3000]={
0,1,199981,199982,199983,199984,199985,199986,
 199987,199988,199989,199990,200000,200001,1599981,
 1599982,1599983,1599984,1599985,1599986,1599987,
 1599988,1599989,1599990,2600000,2600001,13199998,
 35000000
};
ll d2[3000]={0,
28263827,35000000,242463827,500000000,528263827,
 535000000,10000000000,10028263827,10035000000,
 10242463827,10500000000,10528263827,10535000000
};
ll d3[3000]={0,371599983,371599984,371599985,371599986,
 371599987,371599988,371599989,371599990,371599991,
 371599992,500000000,10000000000,10371599983,
 10371599984,10371599985,10371599986,10371599987,
 10371599988};

//ll show(ll d,ll x)
//{
//    ll pre=0;
//    for(int i=1;i<=10)
//
//
//
//    return 0;
//}

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll maxn=600;
sort(d1,d1+maxn);
sort(d2,d2+maxn);
sort(d3,d3+maxn);
sort(d4,d4+maxn);
sort(d5,d5+maxn);
sort(d6,d6+maxn);
sort(d7,d7+maxn);
sort(d8,d8+maxn);
sort(d9,d9+maxn);
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t


//    show(1,10000000);
ll d,y;
    cin>>d>>y;
//    cout<<d<<" "<<y<<endl;
    if(d==1)
    {
        ll pos=upper_bound(d1,d1+maxn,y)-d1;
        cout<<d1[pos-1];
    }

    if(d==2)
    {
        ll pos=upper_bound(d2,d2+maxn,y)-d2;
        cout<<d2[pos-1];
    }
    if(d==3)
    {
        ll pos=upper_bound(d3,d3+maxn,y)-d3;
        cout<<d3[pos-1];
    }
    if(d==4)
    {
        ll pos=upper_bound(d4,d4+maxn,y)-d4;
        cout<<d4[pos-1];
    }
    if(d==5)
    {
        ll pos=upper_bound(d5,d5+maxn,y)-d5;
        cout<<d5[pos-1];
    }
    if(d==6)
    {
        ll pos=upper_bound(d6,d6+maxn,y)-d6;
        cout<<d6[pos-1];
    }
    if(d==7)
    {
        ll pos=upper_bound(d7,d7+maxn,y)-d7;
        cout<<d7[pos-1];
    }
    if(d==8)
    {
        ll pos=upper_bound(d8,d8+maxn,y)-d8;
        cout<<d8[pos-1];
    }
if(d==9)
    {
        ll pos=upper_bound(d9,d9+maxn,y)-d9;
        cout<<d9[pos-1];
    }
    cout<<"\n";
#ifdef use_t
}
#endif // use_t
    return 0;
}

