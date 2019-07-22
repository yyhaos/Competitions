#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;
typedef pair<pair<LL,LL>,LL> PIII;
map<PII,int> num1;
map<PIII,int> num2;

const int MAXN=1e6;
const double PI=acos(-1);
//int a[MAXN];

PIII line[MAXN];

int main(void)
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        num1.clear();
        num2.clear();
        for(int i=0;i<n;i++){
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            LL a=-1*(y1-y2);
            LL b=(x1-x2);
            LL c=1ll*(x2*y1)-1ll*(x1*y2);
            LL x=__gcd(abs(a),abs(b));
            x=__gcd(abs(c),abs(x));
            if(a<0) x=-x;
            else if(a==0&&b<0) x=-x;
            else if(a==0&&b==0&&c<0) x=-x;
            a/=x; b/=x; c/=x;
            line[i]={{a,b},c};
            num1[line[i].first]++;
            num2[line[i]]++;
        }
        LL ans=0;
        for(int i=0;i<n;i++){
            PIII tmp=line[i];
            ans+=1ll*n;
            ans-=num1[tmp.first];
            ans+=num2[tmp];
            ans--;
        }
        printf("%lld\n",ans/2);
    }
}
