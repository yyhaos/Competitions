//Problem Web:  http://www.bnuoj.com/contest_show.php?cid=9479#problem/F
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
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

bool cmp(string a,string b)
{
    return a.size() <b.size();
}
char str[100000][200];
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
int n;
int fi=1;
while(~scanf("%d",&n))
{

if(fi==0)
{
    cout<<endl;
}
fi=0;
    int i;
    getchar();
    for(i=0;i<n;i++)
    {
        string tmp;
        getline(cin,tmp);
        if(tmp=="stop")
            break;
        int j;
        for(j=0;tmp[j];j++)
        {
            str[i][j]=tmp[j];
        }
        str[i][j]='\0';
        //que.push_back(tmp);
    }

//cout<<i<<endl;
    //sort(que.begin(),que.end(),cmp);
    for(int j=0;j<i;j++)
    {
        for(int k=j+1;k<i;k++)
        {
            if(strlen(str[j]) >strlen(str[k]))
                swap(str[j],str[k]);
        }
    }
    for(int j=0;j<i;j++)
    {
        for(int k=j+1;k<i;k++)
        {
            if(strlen(str[j]) >strlen(str[k]))
                swap(str[j],str[k]);
        }
    }
    for(int j=0;j<i;j++)
    {
        for(int k=j+1;k<i;k++)
        {
            if(strlen(str[j]) >strlen(str[k]))
                swap(str[j],str[k]);
        }
    }
    for(int j=0;j<i;j++)
    {
        cout<<str[j];
        if(j!=i-1)
            cout<<endl;
    }

    //cout<<endl;
}





#ifdef use_t
}
#endif // use_t
    return 0;
}

