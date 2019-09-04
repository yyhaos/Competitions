//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=851
#include<bits/stdc++.h>
#include<ext/rope>
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
ll sc[4][100005];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    ll k;
    scanf("%lld%lld",&n,&k);
    if(k==1)
    {
        printf("yes\n");
        for(int i=1;i<=n;i++)
        {

            if(i-1)
                printf(" ");
            printf("%d",i);
        }
        printf("\n");
        continue;
    }
    if(k==n)//去重
    {
        printf("no\n");
        continue;
    }
    ll sum=n*(n+1)/2;

//    cout<<"sum:"<<sum<<endl;
    if(sum%k!=0)// 堆大小非整数
    {
        printf("no\n");
        continue;
    }
    ll si=sum/k;//堆大小
//    cout<<"si:"<<si<<endl;
    if(si<=n)
    {

        printf("no\n");
        continue;
    }

    ll ceng=n/k;
////cout<<ceng<<endl;
    if(ceng %2==0)
    {
        printf("yes\n");
        for(int i=1;i<=k;i++)
        {
            printf("%d",i);
            for(int j=2;j<=ceng;j++)
            {
               // if(j<=ceng)
                    printf(" ");
                if(j%2==1)
                {
                    printf("%d",j*k+i-k);
                }
                else
                    printf("%d",j*k-i+1);
            }
            printf("\n");
        }
    }
    else
    {
        if(k%2==0)// 前三层搞不定
        {
            printf("no\n");
            continue;
        }
        if(ceng>=3)
        printf("yes\n");
        else
        {
            printf("no\n");
            continue;
        }
        ll si3=(3*k+1)*3/2;
        for(int i=1;i<=3;i++)
        {
            if(i==1)
            {
                for(int j=1;j<=k;j++)
                {
                    sc[i][j]=j;
                }
            }
            else if(i==2)
            {
                for(int j=1;j<=(k+1)/2;j++)
                {
                    sc[i][j]=3*k-2*j+2;
                }
                for(int j=1;j<=k/2;j++)
                {
                    sc[i][j+k/2+1]=3*k-1-2*j+2;
                }
            }
            else if(i==3)
            {for(int j=1;j<=k;j++)
                sc[i][j]=si3-sc[1][j]-sc[2][j];
            }
        }


        for(int i=1;i<=k;i++)
        {
//            printf("%d",i);
            for(int j=1;j<=3;j++)
            {
//                printf(" ");
            if(j-1)
                printf(" ");
                printf("%d",sc[j][i]);
            }
            for(int j=4;j<=ceng;j++)
            {
               // if(j<=ceng)
                    printf(" ");
                if(j%2==1)
                {
                    printf("%d",j*k+i-k);
                }
                else
                    printf("%d",j*k-i+1);
            }
            printf("\n");
        }


    }



#ifdef use_t
}
#endif // use_t
    return 0;
}


