#include <bits/stdc++.h>
using namespace std;
//int col[100015];
#define li long long
int chan[500];
int col[355][100011];
int v[100005];
int ll[355];
int rr[355];
int sum[100011];
int si,maxn;
int th(int a)
{
    int t=a/si;
    return t;
}
int cnt(int x)
{
    int res=0;
    for(int i=0;i<maxn;i++)
        if(chan[i])
        {
            if(chan[i]==x)res+=rr[i]+1-ll[i];
        }
        else
            res+=col[i][x];
    return res;
}
void down(int x)
{
    if(chan[x])
    {
        for(int i=ll[x];i<=rr[x];i++)
        {
            col[x][v[i]]--;
            col[x][chan[x]]++;
            v[i]=chan[x];
        }
    }
    chan[x]=0;
}
void draw(int l,int r,int x)
{
    int tt=th(l);
    int tr=th(r);
    for(int i=tt+1;i<tr;i++)
    {
        chan[i]=x;
    }
    if(tt==tr)
    {
        down(tt);
        for(int i=l;i<=r;i++)
        {
            col[tr][v[i]]--;
            col[tr][x]++;
            v[i]=x;
        }
    }
    else
    {
        down(tt);
        down(tr);
        for(int i=ll[tr];i<=r;i++)
        {
            col[tr][v[i]]--;
            col[tr][x]++;
            v[i]=x;
        }
        for(int i=l;i<=rr[tt];i++)
        {
            col[tt][v[i]]--;
            col[tt][x]++;
            v[i]=x;
        }
    }
}
int n,c,t;
int main ()
{
 //   freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&c,&t);
    memset(col,0,sizeof(col));
    //memset(chan,1,sizeof(chan));
    memset(ll,0,sizeof(ll));
    memset(rr,0,sizeof(rr));

    si=sqrt(n);
  //  si=50;
 // maxn=(n-1)/si;
    maxn=n/si;

    if(maxn*si!=n)
        maxn++;
    maxn=(n-1)/si+1;
        /*
    for(int i=0;i<maxn;i++)
    {
        chan[i]=1;
        ll[i]=i*si;
        rr[i]=i*si-1+si;
        col[i][1]=si;
    }
    rr[maxn-1]=n-1;
    col[maxn-1][1]=n-maxn*si+si;
    */
    for(int i=0;i<n;i++)
    {
        //chan[i/si]=1;
        ll[i/si]=i/si*si;
        rr[i/si]=max(i,rr[i/si]);
        col[i/si][1]++;
        v[i]=1;
    }
    for(int i=0;i<n;i++)
        v[i]=1;
    //for(int i=0;i<maxn;i++)
    //{
    //    printf("%d %d %d\n",ll[i],rr[i],col[i][1]);
    //}



    while(t--)
    {
        int p,x,a,b;
        scanf("%d%d%d%d",&p,&x,&a,&b);
        li aa=a;
        li bb=b;
        li s=cnt(p);
        li l=aa+s*s;

        l%=n;
        li r=a+(s+bb)*(s+bb);
        r%=n;
        if(l>r)
            swap(l,r);
        //cout<<"draw"<<l<<" "<<r<<" "<<x<<endl;
        draw(l,r,x);
    }
    int ans=0;
    for(int i=0;i<maxn;i++)
    {

        down(i);
       // cout<<"chan"<<i<<" "<<chan[i]<<endl;
    }
    memset(sum,0,sizeof(sum));

    for(int i=0;i<n;i++)
    {
        //cout<<"okk"<<v[i]<<i<<endl;
        sum[v[i]]++;
        ans=max(ans,sum[v[i]]);
    }
    cout<<ans;

    return 0;
}
