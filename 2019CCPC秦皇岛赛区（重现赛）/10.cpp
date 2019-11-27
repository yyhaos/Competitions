//Problem Web:http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1011&cid=872
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
char str[10001005];
char str2[10010005];
ll nxt[10010005];
void getnext(char *p,ll nxt[])
{
    ll j=0,k=-1;
    ll len=strlen(p);
//    printf("%lld\n",len);

    p[len]='a';
    p[len+1]=0;
    nxt[0]=-1;
    while(j<=len-1)
    {
//        printf("%lld %lld\n",j,k);
        if(k==-1 || p[j]==p[k])
        {
            j++;
            k++;
            //if(p[j]!=p[k])
                nxt[j]=k;
            //else
           //     nxt[j]=nxt[k];
        }
        else
        {
            k=nxt[k];
        }
    }
}
ll kmp(char *p,ll nxt[],char *q)
{
    ll len=strlen(p);
    ll len2=strlen(q);
    ll j=0,k=0;
    while(j<len&&k<len2)
    {
        if(k==-1 || p[j]==q[k] )
        {
            j++;
            k++;
        }
        else
        {
            k=nxt[k];
        }
    }
    if( k==len2)
        return j-k;
    return -1;
}
void show(char *p)
{
    ll len=0;
    printf(" ");
    for(int i=0;p[i];i++)
    { len++;
        printf("%c ",p[i]);
    }
    printf("\n");
    for(int i=0;i<len;i++)
    {
        printf("%lld ",nxt[i]);
    }
    printf("\n");
}
ll t,n,m;

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
ll a,b;
while(~scanf("%lld%lld\n",&a,&b))
{
    ll ans=-(1e9*1e5+10);
    scanf("%s\n",str);
    for(int i=0;str[i];i++)
    {
        if(str[i]=='.')
            strcpy(str2,str+i+1);
    }
ll len=strlen(str2);
   // scanf("%s",str2);
    for(int i=0;str2[i];i++)
    {
        str[len-i-1]=str2[i];
    }
//    str[len]='a';
    str[len]=0;

len=strlen(str);
//   printf("%s\n%s\n",str2,str);
    getnext(str,nxt);
//    show(str);
    //cout<<kmp(str,nxt,str2);
    len=strlen(str);
    for(int i=1;i<len;i++)
    {
        ll sa=nxt[i];
        ll xlen=i-sa;
        ll zong=i;
//        ll xunhuan=zong/xlen;
        ans=max(ans, a*zong - b*xlen);
//        printf("i:%lld sa:%lld len:%lld zong:%lld tmp:%lld\n",i,sa,xlen,zong,a*zong - b*xlen);
    }
    printf("%lld\n",ans);

}




#ifdef use_t
}
#endif // use_t
    return 0;
}


