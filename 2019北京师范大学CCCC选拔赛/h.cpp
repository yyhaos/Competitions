//Problem Web:
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
using namespace std;

#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
//#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const int INF = 100000000;
const int maxn=1000;
const int q=1e9+7;
int ksm(int a,int b)
{
    int ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a%q;
        a=a*a%q;
        b/=2LL;
    }
    return ans;
}

int t,n,m;
int a[1000005];
int b[1000005];
int cnt;
void show(int l,int r,int bc)
{
  //  cout<<endl<<l<<" "<<r<<" "<<bc<<endl;
    if(bc<0)
        return ;
    if(l>r)
        return ;
    cnt--;
    if(cnt)
    {
        cout<<b[bc]<<' ';
    }
    else
        cout<<b[bc];
    int mid;
    int cnt=0;
    for(mid=l;mid<=r;mid++)
    {
        cnt++;
        if(a[mid]==b[bc])
        {
            break;
        }

    }
    int yu=r-mid+1;
    //cout<<"mid:"<<mid<< " "<<cnt<<endl;
    show(l,mid-1,bc-yu);
    show(mid+1,r,bc-1);

}

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
int ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    int i=0;
    while(cin>>a[i++])
    {
        if(getchar()!=' ')
            break;
    }
        i=0;
    while(cin>>b[i++])
    {
        if(getchar()!=' ')
            break;
    }
    cnt=i;
    show(0,i-1,i-1);


#ifdef use_t
}
#endif // use_t
    return 0;
}

