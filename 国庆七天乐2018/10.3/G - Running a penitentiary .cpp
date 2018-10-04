#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod = 1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int maxn = 2*1e5 + 2;

pii a[maxn];

struct node{
    int l, r;
    int ml,mr;
}tree[maxn*4];

void push_up(int x){
    tree[x].mr = min(tree[x<<1].mr,tree[x<<1|1].mr);
    tree[x].ml = max(tree[x<<1].ml,tree[x<<1|1].ml);
}

void build(int x,int l,int r){
    tree[x].l = l,tree[x].r = r;
    if (l==r){
        tree[x].ml = a[l].first;
        tree[x].mr = a[l].second;
        return;
    }
    int mid = (l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    push_up(x);
}

void update(int x,int l,int vl,int vr){
    int L = tree[x].l,R = tree[x].r;
    if (L==R&&R==l){
        tree[x].ml = vl;
        tree[x].mr = vr;
        return;
    }
    int mid = (L+R)>>1;
    if (mid>=l) update(x<<1,l,vl,vr);
    else update(x<<1|1,l,vl,vr);
    push_up(x);
}

pii query(int x,int l,int r){
    int L = tree[x].l,R = tree[x].r;
    if (l<=L&&R<=r){
        return make_pair(tree[x].ml,tree[x].mr);
    }else{
        int ansl = -1e9-1, ansr = 1e9+1;
        int mid = (L+R)/2;
        if (mid>=l) {
            pii wr = query(x<<1,l,r);
            ansl = max(wr.first,ansl);
            ansr = min(wr.second,ansr);
        }
        if (r>mid) {
            pii wr = query(x<<1|1,l,r);
            ansl = max(wr.first,ansl);
            ansr = min(wr.second,ansr);
        }
        return make_pair(ansl,ansr);
    }
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].first,&a[i].second);
    build(1,1,n);
    char s[3];
    while(q--){
        scanf("%s",s);
        if (s[0]=='C'){
            int l,vl,vr;
            scanf("%d%d%d",&l,&vl,&vr);
            update(1,l,vl,vr);
        }else {
            int l,r;
            scanf("%d%d",&l,&r);
            pii ans = query(1,l,r);
            //printf("%d %d\n",ans.first,ans.second);
            //printf("Ans\n");
            if (ans.second<ans.first) printf("0\n");
            else printf("%I64d\n",1LL*ans.second-1LL*ans.first+1LL);
        }
    }
    return 0;
}
