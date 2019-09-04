//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=849
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
//using namespace std;
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int tree[50][MAXN];
int sorted[MAXN];
int toleft[50][MAXN];
void build(int l,int r,int dep){
    if(l==r)return;
    int mid=(l+r)>>1;
    int same=mid-l+1;
    for(int i=l;i<=r;i++)
    {
        if(tree[dep][i]<sorted[mid])
            same--;
    }
    int lpos=l;
    int rpos=mid+1;
    for(int i=l;i<=r;i++)
    {
        if(tree[dep][i]<sorted[mid])
            tree[dep+1][lpos++]=tree[dep][i];
        else if(tree[dep][i]==sorted[mid]&&same>0)
        {
            tree[dep+1][lpos++]=tree[dep][i];
            same--;
        }
        else tree[dep+1][rpos++]=tree[dep][i];
        toleft[dep][i]=toleft[dep][l-1]+lpos-l;
    }
    build(l,mid,dep+1);
    build(mid+1,r,dep+1);
}
int query(int L,int R,int l,int r,int dep,int k)
{
    if(l==r)return tree[dep][l];
    int mid=(L+R)>>1;
    int cnt=toleft[dep][r]-toleft[dep][l-1];
    if(cnt>=k)
    {
        int newl=L+toleft[dep][l-1]-toleft[dep][L-1];
        int newr = newl+cnt-1;
        return query(L,mid,newl,newr,dep+1,k);
    }
    else
    {
        int newr=r+toleft[dep][R]-toleft[dep][r];
        int newl=newr-(r-l-cnt);
        return query(mid+1,R,newl,newr,dep+1,k-cnt);
    }
}
ll ma1,ma2,ma3;
inline void update(ll x){
    ma1=ma2;
    ma2=ma3;
    ma3=x;
}
ll qq(ll l,ll r)
{
    return l*1000000000ll+r;
}
map<ll,ll> qqn;
int main(void)
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("in.txt","w",stdout);
#endif

   // freopen("data.txt","r",stdin);
    int n,q;
    while(~scanf("%d%d",&n,&q)){
        qqn.clear();
        for(int i=0;i<=20;i++)
            for(int j=1;j<=n;j++)
                tree[i][j]=0;

        for(int i=1;i<=n;i++){
            scanf("%d",&tree[0][i]);
            sorted[i]=tree[0][i];
        }
        sort(sorted+1,sorted+n+1);
        build(1,n,0);
        while(q--){
            ll l,r;
            scanf("%lld%lld",&l,&r);
            if(qqn[qq(l,r)]!=0)
            {
                printf("%lld\n",qqn[qq(l,r)]);
                continue;
            }
            int f=1;
            int sum=r-l+1;
            if(sum<3){
                    qqn[qq(l,r)]=-1;
                printf("-1\n");continue;
            }
            ma1=1ll*query(1,n,l,r,0,sum);
            ma2=1ll*query(1,n,l,r,0,sum-1);
            ma3=1ll*query(1,n,l,r,0,sum-2);

            if(ma1-ma2<ma3){
                f=0;
                qqn[qq(l,r)]=ma1+ma2+ma3;
                printf("%lld\n",ma1+ma2+ma3);
            }
            else{
                for(int i=sum-3;i>0&&i>sum-45;i--){
                    ll x=1ll*query(1,n,l,r,0,i);
                    update(x);
                    //printf("   %lld %lld %lld\n",ma1,ma2,ma3);
                    if(ma1-ma2<ma3){
                        f=0;
                        qqn[qq(l,r)]=ma1+ma2+ma3;
                        printf("%lld\n",ma1+ma2+ma3);
                        break;
                    }
                }

            }
            if(f) {
                    qqn[qq(l,r)]=-1;
                    printf("-1\n");
            }
        }
    }
}

