//Problem Web:
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
#define zero(x) (((x)>0?(x):-(x))<eps)
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
const double eps=1e-1;
const ll INF = 1e18;
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


struct point
{
    double x,y,z;
    void get()
    {
        cin>>x>>y>>z;
    }
    void show()
    {
        cout<<x<<" "<<y<<" "<<z;
    }
    point(){}
~point(){}
    bool friend operator<(point a,point b)
    {
        if(a.x!=b.x)return a.x<b.x;
        if(a.y!=b.y)return a.y<b.y;
        return a.z<b.z;
    }
}nd[100005];
map<point,ll> nn;
struct line
{
    point a,b;
};
struct plane
{
    point a,b,c;
    void show()
    {
        a.show();
        cout<<" ";
        b.show();
        cout<<" ";
        c.show();
        cout<<" ";
    }
    void get(){
        a.get();b.get();c.get();
    }
};
point xmult(point u,point v)
{
    point ret;
    ret.x=u.y*v.z-v.y*u.z;
    ret.y=u.z*v.x-u.x*v.z;
    ret.z=u.x*v.y-u.y*v.x;
    return ret;
}

point subt(point u,point v)
{
    point ret;
    ret.x=u.x-v.x;ret.y=u.y-v.y;ret.z=u.z-v.z;
    return ret;
}
point pvec(plane s){
    return xmult(subt(s.a,s.b),subt(s.b,s.c));
}
point pvec(point s1,point s2,point s3){  return xmult(subt(s1,s2),subt(s2,s3)); }
double distance(point p1,point p2){  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z)); }
double vlen(point p){  return sqrt(p.x*p.x+p.y*p.y+p.z*p.z); }

//int zero(double x)
//{
//    if(fabs(x)<eps)return 1;
//    return 0;
int dot_inplane(point p,plane s){
//    p.show();
//    cout<<"\n";
//    s.show();
//    cout<<endl;
//double a,b,c,d;
//    cout<<(a=vlen(xmult(subt(s.a,s.b),subt(s.a,s.c))))<<endl;
//    cout<<(b=vlen(xmult(subt(p,s.a),subt(p,s.b))))<<endl;
//    cout<<(c=vlen(xmult(subt(p,s.c),subt(p,s.a))))<<endl;
//    cout<<(d=vlen(xmult(subt(p,s.b),subt(p,s.c))))<<endl;
//    cout<<a-b-c-d<<endl;
     return zero(vlen(xmult(subt(s.a,s.b),subt(s.a,s.c)))-vlen(xmult(subt(p,s.a),subt(p,s.b)))-   vlen(xmult(subt(p,s.b),subt(p,s.c)))-vlen(xmult(subt(p,s.c),subt(p,s.a)))); }
plane pp[20005];
point s,d;

vector<ll> M[100005];
ll cnt=1;

ll id(point a)
{
    if(nn[a]!=0)
        return nn[a];
    else
    {
        nd[cnt]=a;
        return nn[a]=cnt++;
    }
}
map<ll,ll> added;
void add(point a,point b)
{

    ll ida=id(a),idb=id(b);
    if( added[ida*1000000+idb]!=0 )
        return;
    added[ida*1000000+idb]=1;
    added[idb*1000000+ida]=1;
    M[ida].push_back(idb);
    M[idb].push_back(ida);
}


ll dis[100005];
struct sta
{
    ll to,w,pre;
    friend bool operator < (sta a,sta b)
    {
        return a.w>b.w;
    }
    sta(ll _t,ll _w,ll _pre)
    {
        pre=_pre;
        to=_t;
        w=_w;
    }
};

    priority_queue<sta> pq;
    ll path[100005];

void di(ll x)
{
    pq.push(sta(x,nd[x].z,-1));
    while(!pq.empty())
    {
        sta top=pq.top();
        pq.pop();

        ll now=top.to;
        ll w=top.w;

//        cout<<now<<" "<<w<<endl;
        if(dis[now] > w)
        {
            dis[now]=w;
            path[now]=top.pre;
        }
        else
        {
            continue;
        }

        ll si=M[now].size();
//        cout<<si<<endl;
        for(int i=0;i<si;i++)
        {
            ll nxt=M[now][i];
            pq.push(sta(nxt, max(w,(ll)nd[nxt].z),now));
        }
    }
}


void ds(ll x)
{
    if(path[x]!=-1)
    {
        ds(path[x]);
    }
    printf("%lld %lld %lld\n", (ll)nd[x].x, (ll) nd[x].y , (ll)nd[x].z);
//    cout<<endl;return ;
}
ll ans=0;
void ds2(ll x)
{
    if(path[x]!=-1)
    {
        ds2(path[x]);
    }
    ans++;
}
int main ()
{
    for(int i=0;i<=100000;i++)
    {
        dis[i]=INF;
    }
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("hiking.in","r",stdin);
    freopen("hiking.out","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;

for(ii=1;ii<=t;ii++)
{
#endif // use_t
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        pp[i].get();
    }
    s.get();
    d.get();

    for(int i=1;i<=n;i++)
    {
        add(pp[i].a,pp[i].b);
        add(pp[i].a,pp[i].c);
        add(pp[i].c,pp[i].b);
        if(dot_inplane(s,pp[i]))
        {
//            cout<<"on"<<endl;
            add(pp[i].a,s);
            add(pp[i].b,s);
            add(pp[i].c,s);
        }
        if(dot_inplane(d,pp[i]))
        {
//            cout<<"on2"<<endl;
            add(pp[i].a,d);
            add(pp[i].b,d);
            add(pp[i].c,d);
        }
    }

//    cout<<cnt<<endl;
//    for(int i=1;i<cnt;i++)
//    {
//        cout<<nd[i].x<<" "<<nd[i].y<<" "<<nd[i].z<<":\t";
//        ll si=M[i].size();
//        for(int j=0;j<si;j++)
//        {
//            printf("%lld ",M[i][j]);
//        }
//        printf("\n");
//    }

    di(id(s));
    ds2(id(d));
//    printf("%lld",dis[id(d)]);
    printf("%lld\n",ans);
    ds(id(d));


#ifdef use_t
}
#endif // use_t
    return 0;
}

