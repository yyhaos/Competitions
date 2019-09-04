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
ll a[25];
ll used[25];
ll sum[25];
ll maxn[25];
ll minn[25];
map<ll , ll> us;
void dfs(ll th, ll cha)
{
    if(m<=0)
    {
        return ;
    }

    if(th>=n)
    {
//            cout<<"m="<<m<<":";
//            for(int i=1;i<=n;i++)
//            {
//                if(i-1)
//                    printf(" ");
//                cout<<a[i];
//            }
//            cout<<"\n";
        for(int st=n;st>=1;st--)
        {
            ll fa=1;
            for(int h=1;h<n;h++)
            {
                if(st+sum[h]<=0 || st+sum[h]>n)
                {
                    fa=0;
                    break;
                }
            }
            if(fa==1)
            {
//                cout<<"m="<<m<<":";
//                cout<<st;
//                    for(int i=1;i<n;i++)
//                    {
//                        printf(" ");
//                        cout<<st+sum[i];
//                    }
//                    cout<<"\n";
//                    printf("cha:");
//                    for(int i=1;i<n;i++)
//                    {
//                        if(i-1)
//                            printf(" ");
//                        cout<<a[i];
//                    }
//                    cout<<"\n";
                m--;
                if(m==0)
                {
                    cout<<st;
                    for(int i=1;i<n;i++)
                    {
                        printf(" ");
                        cout<<st+sum[i];
                    }
                    cout<<"\n";
//                    printf("cha:");
//                    for(int i=1;i<n;i++)
//                    {
//                        if(i-1)
//                            printf(" ");
//                        cout<<a[i];
//                    }
//                    cout<<"\n";
                }
            }
        }


        return ;
    }
    if(th==1)
    {
        for(int fi=-n+1;fi<=n-1;fi++)
        {
            if(us[fi]==0 )
            {
                a[th]=fi;
                maxn[1]=minn[1]=sum[1]=fi;
                us[fi]=1;
                dfs(th+1,0);
                us[fi]=0;
            }
        }
    }
    else
    {
        for(ll fi=-n+1;fi<=n-1;fi++)
        {
            ll tmp=sum[th-1]+fi;
            if(tmp-minn[th-1]>n)
                continue;
            if(maxn[th-1] - tmp>n)
                continue;
            if(tmp<-n+1 || tmp>n-1)
                continue;
            if(us[tmp]==0 )
            {
                maxn[th]=max(tmp,maxn[th-1]);
                minn[th]=min(tmp,minn[th-1]);
                us[tmp]=1;
                sum[th]=tmp;
                a[th]=fi;
                dfs(th+1,0);
                us[tmp]=0;
            }
        }
    }
}

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

//for(int i=1;i<=2*3*4*5;i++)
//{
//    us.clear();
//    us[0]=1;
//    mem(a,0);
//    mem(sum,0);
//    mem(used,0);
//    n=5;
//    m=i;
//    dfs(1,0);
//}

#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        a[i]=i+1;
//    }
    cin>>m;
    us.clear();
    us[0]=1;
    mem(a,0);
    mem(sum,0);
    mem(used,0);
    mem(used,0);
//    for(int i=1;i<m;i++)
//    {
//        next_permutation(a,a+n);
//    }


    dfs(1,n-1);

//    cout<<"yuan:";
//    for(int i=1;i<=n;i++)
//    {
//        if(i-1)
//            cout<<" ";
//
//        cout<<a[i];
//    }
//    cout<<endl;




#ifdef use_t
}
#endif // use_t
    return 0;
}



