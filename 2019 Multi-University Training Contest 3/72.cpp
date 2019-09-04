#include<bits/stdc++.h>
#define mem(a,b) memset(a,(b),sizeof(a))
using namespace std;
typedef long long LL;
const int maxn=3e5+100;

int row[maxn],sorted[maxn],o1,o2;

priority_queue<int> Q;
multiset<int> S;
int main(void)
{
    //freopen("data.txt","r",stdin);
    //freopen("data.out","w",stdout);
    int t;scanf("%d",&t);
    while(t--){
        S.clear();
        while(!Q.empty()) Q.pop();
        int n,m;scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",row+i);
        }
        LL pre,sum;
        pre=sum=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            pre+=row[i];
            if(pre-sum<=m);
            else{
                while(pre-sum>m){
                    sum+=Q.top();
                    S.insert(S.end(),Q.top());
                    Q.pop();
                    ans++;
                }
                while(pre-sum<m){
                    int tmp=*S.begin();
                    if(pre-sum+tmp>m)break;
                    Q.push(tmp);
                    sum-=(tmp);
                    S.erase(S.begin());
                    ans--;
                }
            }
            printf("%d ",ans);
            Q.push(row[i]);
        }
        printf("\n");
    }
}
