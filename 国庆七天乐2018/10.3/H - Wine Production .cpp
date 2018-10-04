#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 30005;
int ku[maxn];
int B[maxn];
struct nodeA{
    int tem,id;
}A[maxn];

struct edge{
    int l,r,id;
}G[maxn];

int cmp1(nodeA X,nodeA Y){
    return X.tem < Y.tem;
}

int cmp2(edge X,edge Y){
    if(ku[X.l] == ku[Y.l])
        return X.r < Y.r;
    else
        return ku[X.l] < ku[Y.l];
}

int main()
{
    //freopen("test.txt","r",stdin);
    int N,Q;
    int qum = sqrt(maxn);
    for(int i = 1;i<=maxn;i++)
        ku[i] = (i-1)/qum;
    scanf("%d%d",&N,&Q);
    for(int i = 1;i<=N;i++){
        int a;
        scanf("%d",&a);
        A[i].tem = a;
        A[i].id = i;
    }
    sort(A+1,A+N+1,cmp1);
    int m = 1;
    for(int i = 1;i<=N;i++){
        if(i == 1){
            B[A[i].id] = m;
            continue;
        }
        if(A[i].tem != A[i-1].tem)
            m++;
        B[A[i].id] = m;
    }
    //printf("离散");
//    for(int i = 1;i<=N;i++)
//        printf("%d\n",B[i]);
    for(int i = 0;i<Q;i++){
        scanf("%d%d",&G[i].l,&G[i].r);
        G[i].id = i;
    }
    sort(G,G+Q,cmp2);
    /*for(int i = 0;i<Q;i++)
        printf("%d %d %d\n",G[i].id,G[i].l,G[i].r);*/
    int num[maxn],vis[maxn],ans[maxn];
    memset(num,0,sizeof(num));
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
    int start = G[0].l;
    int edl = G[0].r;
    int sum = 0;


    for(int i = start;i<=edl;i++){
        vis[B[i]]++;
        num[vis[B[i]]]++;
        if(vis[B[i]] > num[vis[B[i]]])
            continue;
        else
            sum = max(sum,vis[B[i]]);
    }


    ans[G[0].id] = sum;
    for(int i = 1;i<Q;i++){
       // printf("%d %d %d\n",i,G[i].l,G[i].r);
        while(start > G[i].l){
            vis[B[--start]]++;
            num[vis[B[start]]]++;
            if(vis[B[start]]==1+sum && num[vis[B[start]]]>=vis[B[start]])
                sum++;
        }
        while(start < G[i].l){
            vis[B[start]]--;
            num[vis[B[start]]+1]--;
            if(sum == vis[B[start]]+1 && num[vis[B[start]]+1]<vis[B[start]]+1)
                sum--;
            start++;
        }
        while(edl > G[i].r){
            vis[B[edl]]--;
            num[vis[B[edl]]+1]--;
            if(vis[B[edl]]+1==sum && num[vis[B[edl]]+1]<vis[B[edl]]+1)
                sum--;
            edl--;
        }
        while(edl < G[i].r){
            vis[B[++edl]]++;
            num[vis[B[edl]]]++;
            if(vis[B[edl]]==sum+1 && num[vis[B[edl]]]>=vis[B[edl]])
                sum++;
        }
        ans[G[i].id] = sum;
    }
    for(int i = 0;i<Q;i++)
        printf("%d\n",ans[i]);
    return 0;
