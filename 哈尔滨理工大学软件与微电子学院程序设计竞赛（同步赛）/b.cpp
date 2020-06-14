//Problem Web:https://ac.nowcoder.com/acm/contest/5929/B
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
struct shu{
    int val,pos,sta ;
    friend bool operator< (shu a, shu b){
        if(a.val!=b.val)return a.val<b.val;
        return a.pos<b.pos;
    }
}a[1000000],b[1000000];

ll used[3000005];
ll off=1000000;

ll re[3000005];
void gen(ll pos,ll val){
    if(re[pos]==0){
        re[pos]=val;
    }
    else {
        re[pos]=min(re[pos],val);
    }
}
void ge(ll i,ll nxt){
    if(i==nxt)
        return ;
    ll pos= abs(a[i].val*a[i].sta + a[nxt].sta*a[nxt].val);
    ll val= a[i].pos+a[nxt].pos;
    if(re[pos]==0){
        re[pos]=val;
    }
    else {
        re[pos]=min(re[pos],val);
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

    memset(used,0,sizeof(used));

    cin>>n;
    ll th=1;
    ll tmp;
    for(int i=1;i<=n;i++){

        scanf("%lld",&tmp);
        if(used[tmp+off]<2){
            a[th].val=tmp;
            a[th].sta=tmp>0 ? 1:-1;
            a[th++].pos=i;
            used[tmp+off]++;

        }
    }
    n=th-1;


    sort(a+1,a+1+n);
    memset(re,0,sizeof(re));



    for(int i=1;i<n;i++){
        int nxt=i+1;
        gen(abs(a[i].val + a[nxt].val), a[i].pos+a[nxt].pos );
    }

    for(int i=1;i<=n;i++){
        b[i]=a[i];
    }
    th=1;
    for(int i=1;i<=n;i++){
        if(i-1>=1){
//            printf("%d == %d\n",b[i].val,b[i-1].val);
            if(b[i].val == b[i-1].val){
                continue;
            }
        }
        a[th++]=b[i];
    }
    n=th-1;

//    for(int i=1;i<=n;i++)
//        printf("%d %d\n",a[i].val,a[i].pos);
//    printf("\n");

    for(int i=1;i<=n;i++){
        if(a[i].sta<0){
            a[i].val*=-1;
        }
    }



    sort(a+1,a+1+n);

    int pre_1=-1;

    int now=1;
    int prenow=-1;
    while(now<=n){
        while( now<=n&& a[now].sta==-1 ){
            if(prenow!=-1)
                ge(prenow,now);
            pre_1=now;
            now++;
        }

        if(pre_1!=-1){
            ge(  pre_1, now );
        }
        while( now<=n&&a[now].sta==1){
            if(pre_1!=-1){
                ge(  pre_1, now );
            }
            prenow=now;
            now++;
        }

    }



    for(int i=0;i<=2000005;i++){
        if(re[i]!=0){
            printf("%d %lld\n",i,re[i]);
            return 0;
        }
    }


#ifdef use_t
}
#endif // use_t
    return 0;
}

