#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+6;
ll a[maxn], s[maxn];

struct node{
    int l,r;
    ll sum,lazy;
    void upd(ll val){
        sum+=1LL*(r-l+1)*val;
        lazy += val;
    }
}tree[maxn<<2];

void push_up(int x){
    tree[x].sum = tree[x<<1].sum + tree[x<<1|1].sum;
}

void push_down(int x){
    ll lazyval = tree[x].lazy;
    if (lazyval!=0){
        tree[x<<1].upd(lazyval);
        tree[x<<1|1].upd(lazyval);
        tree[x].lazy = 0;
    }
}

void build(int x,int l,int r){
    tree[x].l = l,tree[x].r = r;
    tree[x].sum = tree[x].lazy = 0;
    if (l==r){
        tree[x].sum = s[l];
    }
    else {
        int mid = (l+r)>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        push_up(x);
    }
}

void update(int x,int l,int r,ll val){
    int L = tree[x].l,R = tree[x].r;
    if (l<=L&&R<=r){
        tree[x].upd(val);
        return;
    }
    push_down(x);
    int mid = (L+R)>>1;
    if (l<=mid) update(x<<1,l,r,val);
    if (r>mid) update(x<<1|1,l,r,val);
    push_up(x);
}

ll query(int x,int l,int r){
    int L = tree[x].l,R = tree[x].r;
    if (l<=L&&R<=r){
        return tree[x].sum;
    }else{
        int mid = (L+R)>>1;
        ll res = 0;
        push_down(x);
        if (l<=mid) res += query(x<<1,l,r);
        if (r>mid) res += query(x<<1|1,l,r);
        push_up(x);
        return res;
    }
}

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    a[0] = s[0] = 0;
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        s[i] = s[i-1] + a[i];
        //printf("%d\n",s[i]);
    }
    build(1,1,n);
    while(q--){
        int op,b,c;
        scanf("%d%d%d",&op,&b,&c);
        if (op==1){
            if (b==1){
                printf("%lld\n",query(1,b,c));
            }
            else printf("%lld\n",query(1,b,c)-1LL*(c-b+1)*query(1,b-1,b-1));
        }else{
            ll dx = c - a[b];
            a[b] = c;
            update(1,b,n,dx);
        }
    }
    return 0;
}

/*
5 5
1 2 3 4 5
1 1 5
2 1 0
1 1 5

5 10
9998778 6324912 999999999 99999999 888888888
1 1 5
1 2 5
2 1 0
1 1 5
2 1 9998778
1 1 5
*/
