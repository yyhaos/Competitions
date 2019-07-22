#include<bits/stdc++.h>
#define mem(a,b) memset(a,(b),sizeof(a))
using namespace std;
typedef long long LL;
const LL MAXN=5e5+10;

LL row[MAXN],ans[MAXN];
LL bit_row[MAXN],sum_ans[MAXN<<2LL];

LL lowbit(LL x){return x&(-x);}

void push_up(LL rt)
{
    sum_ans[rt]=sum_ans[rt<<1]+sum_ans[rt<<1|1];
}

void update_row(LL l,LL r,LL val){
    for(LL i=l;i<MAXN;i+=lowbit(i))
        bit_row[i]+=val;
    for(LL i=r+1;i<MAXN;i+=lowbit(i))
        bit_row[i]-=val;
}

LL query_row(LL pos)
{
    LL ret=0;
    for(LL i=pos;i>0;i-=lowbit(i))
        ret+=bit_row[i];
    return ret;
}

void build(LL rt,LL l,LL r)
{
    if(l==r){
        sum_ans[rt]=ans[l];
        return;
    }
    LL m=(l+r)>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    push_up(rt);
}


void update_ans(LL rt,LL pos,LL l,LL r,LL val)
{
    if(l==r){
        sum_ans[rt]=val;
        return;
    }
    LL m=(l+r)>>1;
    if(pos<=m) update_ans(rt<<1,pos,l,m,val);
    else update_ans(rt<<1|1,pos,m+1,r,val);
    push_up(rt);
}

LL query_ans(LL rt,LL L,LL R,LL l,LL r)
{
    if(L<=l&&r<=R) return sum_ans[rt];
    LL m=(l+r)>>1;
    LL ret1,ret2;
    ret1=ret2=0;
    if(m>=L) ret1=query_ans(rt<<1,L,R,l,m);
    if(m<R)  ret2=query_ans(rt<<1|1,L,R,m+1,r);
    return ret1+ret2;
}

int main(void)
{
     #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    LL _;scanf("%lld",&_);
    while(_--){
        LL n,q;scanf("%lld%lld",&n,&q);
        for(LL i=1;i<=n;i++)
            scanf("%lld",row+i);
        for(LL i=2;i<=n;i++)
            ans[i]=max(0LL,row[i]-row[i-1]);
        build(1,1,n);
        for(LL i=1;i<=n;i++)
            update_row(i,i,row[i]);
        while(q--){
            LL op,l,r,k;scanf("%lld%lld%lld",&op,&l,&r);
            if(op==1){
                scanf("%lld",&k);
                update_row(l,r,k);
                LL l1=query_row(l-1);
                LL l2=query_row(l);
                LL val=max(0ll,l2-l1);
                update_ans(1,l,1,n,val);
                LL r1=query_row(r);
                LL r2=query_row(r+1);
                val=max(0ll,r2-r1);
                update_ans(1,r+1,1,n,val);
            }
            else{
                if(l==r) printf("%lld\n",query_row(l));
                else{
                    LL sum=query_row(l);
                    sum+=query_ans(1,l+1,r,1,n);
                    printf("%lld\n",sum);
                }
            }
        }
    }
}
