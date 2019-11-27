//Problem Web:https://vjudge.net/contest/330734#problem/A
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

struct node
{
    ll l,r;
    vector<ll> lg,rg;
    ll lsi,rsi;
    ll fa;
    ll state;
};

node M[505];
map<string,ll> nn;

void update(ll x,ll tnew)
{
    ll fa=M[x].fa;
    if(M[fa].l==x)
    {
        M[fa].lg.push_back(tnew);
        M[fa].lsi++;
    }
    else
    {
        M[fa].rg.push_back(tnew);
        M[fa].rsi++;
    }

    if(x!=0)
     update(fa,tnew);
}

struct train
{
    ll pos,des,st;
}tr[10005];

struct mod
{
    ll pos,time;
    friend bool operator<(mod a, mod b)
    {
        if(a.time!=b.time)
        return a.time<b.time;
        return a.pos<b.pos;
    }
}mm[10000005];
ll mcnt=0;

void mo(ll pos,ll time)
{
    mm[mcnt].pos=pos;
    mm[mcnt].time=time;
    mcnt++;
}

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
freopen("instruction.in","r",stdin);
freopen("instruction.out","w",stdout);

#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    cin>>n;
        char tmp[5];
    ll cnt=1;
    for(int i=1;i<=n;i++)
    {
        ll tt;
        string tname;
        scanf("%s",tmp);
        if(tmp[0]=='s')
        {
            scanf("%lld",&tt);
            M[i].fa=tt;
            M[i].state=0;
            M[i].lsi=0;
            M[i].rsi=0;
            M[i].l=M[i].r=0;
            M[tt].l==0? M[tt].l=i : M[tt].r=i;
        }
        else
        {
            scanf("%lld",&tt);
            cin>>tname;
            nn[tname]=cnt++;
            M[i].fa=tt;
            M[i].lg.push_back(nn[tname]);
            M[i].lsi=1;
            M[i].rsi=0;
            M[i].l=M[i].r=0;
            M[tt].l==0 ? M[tt].l=i : M[tt].r=i;
            update(i,nn[tname]);
        }
    }

//    for(int i=1;i<=n;i++)
//    {
//        printf("i:%d %lld + %lld ->%lld\n",i,M[i].lsi,M[i].rsi,M[i].fa);
//        printf("Left: ");
//        for(int j=0;j<M[i].lsi;j++)
//            printf("%d ",M[i].lg[j]);
//        printf("\n");
//        printf("Right: ");
//        for(int j=0;j<M[i].rsi;j++)
//            printf("%d ",M[i].rg[j]);
//        printf("\n");
//    }
//
//    for(int i=1;i<=n;i++)
//    {
//        printf("i:%d %lld + %lld ->%lld %c\n",i,M[i].lsi,M[i].rsi,M[i].fa, M[i].state==0? 'L' : 'R' );
//    }

    cin>>m;
    for(int i=1;i<=m;i++)
    {
        string tmp;
        ll st;
        scanf("%lld",&st);
        cin>>tmp;
        tr[i].des=nn[tmp];
        tr[i].st=st;
        tr[i].pos=1;
    }
    for(int time=0;time<= 10005 +100; time++)
    {
//        printf("time:%d\n",time);
//        for(int i=1;i<=n;i++)
//        {
//            printf("i:%d %lld + %lld ->%lld %c\n",i,M[i].lsi,M[i].rsi,M[i].fa, M[i].state==0? 'L' : 'R' );
//        }
        for(int i=1;i<=m;i++)
        {
            if( M[tr[i].pos].l==0)
                continue;
            if(tr[i].st >time)
                continue;
            int tar=tr[i].des;
            int to=1;
            int now=tr[i].pos;
            int si=M[now].lsi;
            for(int i=0;i<si;i++)
            {
                if(M[now].lg[i]==tar)
                {
                    to=0;
                    break;
                }
            }
            if(to==M[now].state)
            {

            }
            else
            {
                if(now>0)
                mo(now,time+1);
                M[now].state=1-M[now].state;
//                printf("Mod:::: %d %d %d\n",i,now,time+1);
            }
            if(to==0)
                tr[i].pos=M[now].l;
            else
                tr[i].pos=M[now].r;
        }
    }

//    sort(mm,mm+mcnt);
    printf("%lld",mcnt);
    for(int i=0;i<mcnt;i++)
    {
        printf("\n%lld %lld",mm[i].pos,mm[i].time);
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}


