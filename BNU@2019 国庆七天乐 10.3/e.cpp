
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e6+5;

LL a[maxn];
int t[maxn];
int ans[maxn];

int has[maxn];

struct mydata
{
    int cnt,val;
    int have;
    bool operator < (mydata tmp){
        if(cnt==tmp.cnt) return have>tmp.have;
        return cnt<tmp.cnt;
    }
}mydata[maxn];
LL lcm(LL x,LL y)
{
    return x/__gcd(x,y)*y;
}

void init(int x)
{
    memset(has,0,sizeof has);
    for(int i=1;i<=x;i++){
        for(int j=2;j*i<=x;j++){
            if(t[i*j]>0){
                has[i]=1;
                break;
            }
        }
    }
}

int main(void)
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("equal.in","r",stdin);
    freopen("equal.out","w",stdout);
 #endif // yyhao
 //   freopen("data.txt","r",stdin);
    memset(t,0,sizeof t);
    int n;scanf("%d",&n);
    LL x=0;int flag=1;
    LL all=1;
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        x=max(x,a[i]);
        t[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        all=lcm(all,a[i]);
        if(all>x) flag=0;
    }
    init(x);
    int num=0;
    for(int i=1;i<=x;i++){
        if(t[i]>0){
            mydata[num].cnt=t[i];
            mydata[num].val=i;
            if(has[i]) mydata[num].have=1;
            else mydata[num].have=0;
            num++;
        }
    }
    if(flag) num--;
    sort(mydata,mydata+num);
    memset(ans,0,sizeof ans);
    if(flag){
        int p=1;
        int add=1;
        for(int i=0;i<=num;i++){
            ans[p]=num-i+add;
            p+=mydata[i].cnt;
        }
    }
    else{
        int p=1;
        int add=0;
        for(int i=0;i<=num;i++){
            ans[p]=num-i+add;
            p+=mydata[i].cnt;
            if(mydata[i].have==0)
                add=1;
        }
    }

    for(int i=1;i<=n+1;i++){
        if(ans[i]==0) ans[i]=ans[i-1];
        printf("%d ",ans[i]);
    }
}
