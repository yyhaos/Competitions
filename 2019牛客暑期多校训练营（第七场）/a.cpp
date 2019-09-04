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
#define pb push_back
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll MAXN=1000;
const ll q=1e9+7;
vector<int>v;
char s[MAXN];
int sum[MAXN];
void getv(int st,int ed)
{
    v.clear();
    memset(sum,0,sizeof(sum));
    int c0=0,c1=0;
//    cout<<st<<endl;
    for(int i=st;i<=ed;i++)
    {
        if(s[i]=='0')
        {
            if(i!=st&&c1!=0){v.pb(c1);}

            c1=0;
            c0++;
        }
        else
        {
            if(c0!=0)v.pb(c0);
            c0=0;
            c1++;
        }
    }
    if(c1)v.pb(c1);

}
void print(int st,int ed)
{
    for(int i=st;i<=ed;i++)
    {
        printf("%c",s[i]);
    }
//    cout<<strlen(s)-1<<" "<<ed<<endl;
    if(ed != strlen(s)-1);
        printf(" ");
}
int slove1(int st,int len)
{
//    cout<<"st:"<<st<<endl;
    int c0=v[st],c1=v[st+1];
    int ans=c0+c1-1;
    int flag=0;
    for(int i=st+2;i<len;i++)
    {
        if(i%2==0)// Ϊ 0
        {
            if(v[i]<c0)
            {
                c0=min(c0,v[i]);
                flag=1;
                continue;
            }
            else
                break;
        }
        else// Ϊ 1
        {
            if(flag)
            {
                ans=max(ans,i);
            }
            else
            {
                break;
            }
        }
    }
    cout<<"solve1:"<<ans<<" "<<st<<endl;
    return ans-st+1;
}
int slove2(int st,int len)
{
    int ans=0;
    for(int j=0;st+j*2+1<=len/2;j++)
    {
        int d=2*j+2;

        if(slove1(st,st+d) != d &&  slove2(st,st+d)!=d)
            continue;
//        printf("st=%d j=%d st+d=%d\n",st,j,st+d);
        for(int i=st+d;i<len;i++)
        {
//            printf("i=%d\n",i);
            if(v[i]!=v[(i-st)%d])break;
            if((i-st)%d+1==d)ans=i;
        }
    }
//    printf("%d\n",ans);
    return ans-st+1;
}
int main ()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif
//    freopen("int.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        int len_s=strlen(s);
        int st=0,ed=len_s-1;
        int flag=0;
        for(int i=0;i<len_s;i++)
        {
            st=i;
            if(s[i]=='0')break;
        }
        for(int i=len_s-1;i>=0;i--)
        {
            ed=i;
            if(s[i]=='1')break;
        }
        for(int i=0;i<len_s;i++)
        {
            if(s[i]!='0')printf("%c",s[i]);
            else break;
        }
        if(s[0]=='1')printf(" ");
        getv(st,ed);
        int len_v=v.size();
        for(int i=0;i<len_v;i++)
        {
            if(i==0)sum[i]=v[i];
            else sum[i]=sum[i-1]+v[i];
//            printf("%d ",v[i]);
        }
//        return 0;
//        printf("\n");
//        st=0;
        int ma=0;
//        printf("st=%d ed=%d\n",st,ed);
        for(int i=0;i<len_v;)
        {
            ma=max(slove1(i,len_v),slove2(i,len_v));
            cout<<"ma:"<<ma<<endl;
            print(st+(i==0?0:sum[i-1]),st+sum[i+ma]-1);
            i=i+ma;
        }
        for(int i=len_s-1;i>=0;i--)
        {
            if(s[i]=='0')printf("%c",s[i]);
            else break;
        }
        printf("\n");
    }
    return 0;
}
