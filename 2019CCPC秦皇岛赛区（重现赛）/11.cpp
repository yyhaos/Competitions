#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=2007;
pii a[maxn],b[maxn];
int n,q,ans[maxn];
int mygcd(int a,int b){
    if(b==0)return a;
    return mygcd(b,a%b);
}
pii ge(int x,int y){
    int tem=mygcd(x,y);
    x/=tem,y/=tem;
    if(x<0)x=-x,y=-y;
    else if(x==0&&y<0)y=-y;
    return make_pair(x,y);
}

map<pii,int>ma;
int main(){
     #ifdef yyhao
    freopen("in.txt","r",stdin);
    #endif // yyhaos
    while(scanf("%d %d",&n,&q)==2){
        for(int i=1;i<=n;i++)scanf("%d %d",&a[i].first,&a[i].second);
        for(int i=1;i<=q;i++)scanf("%d %d",&b[i].first,&b[i].second);
        for(int i=1;i<=n;i++){
            ma.clear();
            for(int j=1;j<=n;j++){
                if(j==i)continue;
                int x=a[j].first-a[i].first,y=a[j].second-a[i].second;
                ma[ge(x,y)]++;
            }
            for(int j=1;j<=q;j++){
                int x=b[j].first-a[i].first,y=b[j].second-a[i].second;
                if(ma.count(ge(-y,x)))ans[j]+=ma[ge(-y,x)];
            }
        }
        for(int i=1;i<=q;i++){
            ma.clear();
            for(int j=1;j<=n;j++){
                int x=a[j].first-b[i].first,y=a[j].second-b[i].second;
                ma[ge(x,y)]++;
                if(ma.count(ge(-y,x)))
                ans[i]+=ma[ge(-y,x)];
            }
        }
        for(int i=1;i<=q;i++){
            printf("%d\n",ans[i]);ans[i]=0;
        }
    }
    return 0;
}
