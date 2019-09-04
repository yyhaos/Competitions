//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=852
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
char str[1000005];
int mynext[1000005];
ll cnt[1000005];
ll myans=0;
int extend[1000095];
void pre_EKMP(char x[],int m,int next[])
{  next[0]=m;  int j=0;  while(j+1<m && x[j]==x[j+1])j++;  next[1]=j;  int k=1;  for(int i=2;i<m;i++)
 {
  int p=next[k]+k-1;   int L=next[i-k];   if(i+L<p+1)next[i]=L;
  else
  {
   j=max(0,p-i+1);    while(i+j<m && x[i+j]==x[j])j++;    next[i]=j;    k=i;   }
 }
} void EKMP(char x[],int m,char y[],int n,int next[],int extend[])
{  pre_EKMP(x,m,next);  int j=0;  while(j<n && j<m && x[j]==y[j])j++;  extend[0]=j;  int k=0;  for(int i=1;i<n;i++)
 {
  int p=extend[k]+k-1;   int L=next[i-k];   if(i+L<p+1)extend[i]=L;
  else
  {
   j=max(0,p-i+1);
   while(i+j<n && j<m && y[i+j]==x[j])j++;    extend[i]=j;    k=i;   }
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

    scanf("%s",str);
    mem(mynext,0);
    ll len=strlen(str);

//cout<<len<<endl;
EKMP(str,len,str,len,mynext,extend);
//for(int i=0;i<len;i++)
//{
//    cout<<i<<":"<<extend[i]<<" ";
//}
//cout<<endl;
//    cout<<"ans:"<<KMP_Count(str,len,str+1,len-1)<<endl;
//
//    char tar[]="yw";
//    cout<<"test:"<<KMP_Count(tar,2,str,len)<<endl;
//ans-=len;
myans=0;
//cout<<len<<endl;
for(int i=1;i<len;i++)
{
    myans+=min(len-i,extend[i]+1LL);
}
    cout<<myans<<"\n";

#ifdef use_t
}
#endif // use_t
    return 0;
}


