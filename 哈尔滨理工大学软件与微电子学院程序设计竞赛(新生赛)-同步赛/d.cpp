#include<bits/stdc++.h>
using namespace std;
#define ll __int128
double maxx(double a,double b,double c)
{

    return max(a,max(b,c));
}
ll a[100005];
ll cnt=0;
void d(ll x)
{
    if(x/10!=0)
        d(x/10);

    a[cnt++]=x%10;
}
ll dp[1000];
char str[8005];
//ll a[100005];
bool check(ll x)
{
    cnt=0;
    d(x);
    if(cnt<=1)
        return false;
    ll dif=0,now=a[0];
    for(int i=1;i<cnt;i++)
    {
        if(dif<0)
            break;
        if(a[i]==now)
            continue;
        else
        {
            if(dif==0)
                dif=1,now=a[i];
            else
                dif=-1,now=a[i];
        }
    }
    if(dif==1)
        return true;
    return false;
}

ll s[1000000];
ll scnt=0;
ll getf(ll i,ll j,ll fen,ll len)
{
    for(int ii=0;ii<fen;ii++)
    {
        a[ii]=i;
    }
    for(int ii=fen;ii<len;ii++)
    {
        a[ii]=j;
    }
    ll tmp=0;

// ll mi=1;
    for(int ii=0;ii<len;ii++)
    {
        tmp*=10;
        tmp+=a[ii];
    }
    return tmp;
}
void get()
{
    for(int len=2;len<=18;len++)
    {
        for(int i=1;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(i==j)
                    continue;
                for(int fen=1;fen<len;fen++)
                {
                    s[scnt++]=getf(i,j,fen,len);
                }
            }
        }
    }

}
int main ()
{
//    ll tmp,ans=0;
//    double tmp,ans=0;
//    scanf("%lf",&tmp);ans+=tmp;
//    scanf("%lf",&tmp);ans+=tmp;
//    scanf("%lf",&tmp);ans+=tmp;
////    scanf("%lld",&tmp);ans=max(ans,tmp);
////    scanf("%lld",&tmp);ans+=tmp;
////    scanf("%lld",&tmp);ans+=tmp;
//    if(ans>=180)
//    printf("NO");
//    else
//        printf("YES");

//    ll n;
//    ll b,c;
//    cin>>n;
//    for(int i=0;i<n;i++)
//    {
//
//        cin>>a[i];
//    }
//    cin>>b;
//    ll cnt=0;
//    for(int i=0;i<n;i++)
//    {
//        if(a[i]==b)
//            cnt++;
//    }
//    printf("%lld",cnt);
//printf("%d",check(101));
    ll n;
    get();
    sort(s,s+scnt);
//    printf("%lld\n",scnt);
//    for(int i=0;i<scnt;i++)
//    {
//        printf("%lld\n",s[i]);
//    }
   // printf("%lf\n",1111111111111111.0/17);
//while(cin>>n)
for(n=1;n<=100000;n++)
 {
    // if(n%10!=0)
     //   continue;
            if(n==0)
            break;


//        for(int i=2;i<=10000000000LL;i++)
//        {
//            if(check(i*n))
//            {
//                printf("%lld: %lld\n",n,i*n);
//                break;
//            }
//        }
ll aa=0;
        for(int i=0;i<scnt;i++)
        {
            if(s[i]%n==0 && s[i]>n)
            {
                aa=1;
                printf("%lld: %lld\n",(long long)n,(long long)s[i]);
                break;
            }
        }
        if(aa==0)
        {
//            printf("%lld: ------------",n);
//            printf("%lld: ",n);
//            for(int i=1;i<n/10;i++)
//                printf("1");
//            printf("0\n");
        }
    }
    return 0;
}
