//Problem Web:https://codeforces.com/contests/1214
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


string str[1000005];
vector <ll> M[1000005];
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

    cin>>n>>m;
    getchar();
    for(int i=0;i<n;i++)
    {
        getline(cin,str[i]);
        //getline(cin,str);
//        cout<<str[i]<<endl;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            M[i].push_back(INF);
            if(i==0 && j==0 )
                continue;
            if(i==n-1 && j==m-1)
                continue;
            if(i>0 && j>0)
            {
                if(str[i-1][j]=='#' && str[i][j-1]=='#')
                {
                    str[i][j]='#';
                }
            }
            else if(i>0 && j==0)
            {
                if(str[i-1][j]=='#')
                    str[i][j]='#';
            }
            else  if(j>0 && i==0)
            {
                if(str[i][j-1]=='#')
                    str[i][j]='#';
            }
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            M[i].push_back(INF);
            if(i==0 && j==0 )
                continue;
            if(i==n-1 && j==m-1)
                continue;
            if(i<n-1 && j<m-1)
            {
                if(str[i+1][j]=='#' && str[i][j+1]=='#')
                {
                    str[i][j]='#';
                }
            }
            else if(i<n-1 && j==m-1)
            {
                if(str[i+1][j]=='#')
                    str[i][j]='#';
            }
            else  if(j<m-1 && i==n-1)
            {
                if(str[i][j+1]=='#')
                    str[i][j]='#';
            }
        }
    }


    ll ans=INF;
    ll tmp=0;


//for(int i=0;i<n;i++)
//    {
//        getline(cin,str[i]);
//        //getline(cin,str);
////        cout<<str[i]<<endl;
//    }


    for(ll i=1;i<m;i++)
    {
        tmp=0;
//        if(i < n)
//        {
            for(int th=0;th<=min(i,n);th++)
            {
                if(str[th][i-th]=='.')
                {
                    tmp++;
                }
            }
            ans=min(ans,tmp);
//        }
//        else
//        {
//            for(int th=0;th<n;th++)
//            {
//                if(str[th][i-th]=='.')
//                {
//                    tmp++;
//                }
//            }
//            ans=min(ans,tmp);
//        }
//cout<<ans<<endl;
    }

    for(int i=1;i<n-1;i++) // i m-1
    {
        tmp=0;
        for(int th=0;th<=m;th++)
        {
            if(m-1-th<0 || i+th>=n)
                break;
            if(str[i+th][m-1-th]=='.')
            {
                tmp++;
            }
        }
        ans=min(ans,tmp);
//cout<<ans<<endl;
    }

//for(int i=1;i<m-1;i++)
//{
//    tmp=0;
//    for(int j=0;j<n;j++)
//    {
//        if(str[j][i]=='.')
//            tmp++;
//    }
//    ans=min(ans,tmp);
//
//}
//for(int i=1;i<n-1;i++)
//{
//    tmp=0;
//    for(int j=0;j<m;j++)
//    {
//        if(str[i][j]=='.')
//            tmp++;
//    }
//    ans=min(ans,tmp);
//
//}
//
//    for(int i=1;i<n+m-2;i++)
//    {
//        tmp=0;
//        for(int th=0;th<=i;th++ )
//        {
//            if(th>=n)
//                break;
//            if(i-th<0)
//                break;
//            if(i-th>m)
//            {
//                th=i-m+1;
//            }
//            if(str[th][i-th]=='.')
//            {
//                tmp++;
//            }
//        }
//        ans=min(ans,tmp);
//    }

    cout<<ans;



#ifdef use_t
}
#endif // use_t
    return 0;
}



