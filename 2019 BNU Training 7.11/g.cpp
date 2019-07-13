#include<bits/stdc++.h>
#define mem(a,b) memset(a,(b),sizeof(a))
using namespace std;
const int MAXN=1e5+10;
typedef long long LL;

LL get_pos(int x1,int x2,int pos)
{
    if(x1>x2) swap(x1,x2);
    if(x1<=pos&&pos<=x2) return 0;
    else if(pos>x2) return pos-x2;
    else return x1;
}

struct sq{
    int x1,y1,x2,y2;
    int midx,midy;
    void init(){
        midx=(x1+x2)>>1;
        midy=(y1+y2)>>1;
    }
}a[MAXN],b[MAXN],b2[MAXN];

bool cmpx1(sq& tmp1,sq& tmp2){

        return tmp1.x1<tmp2.x1;
    //return tmp1.x2<tmp2.x2;
}
bool cmpx2(sq& tmp1,sq& tmp2){
    return tmp1.x2<tmp2.x2;
}


bool cmpy1(sq& tmp1,sq& tmp2){

        return tmp1.y1<tmp2.y1;
    //return tmp1.x2<tmp2.x2;
}
bool cmpy2(sq& tmp1,sq& tmp2){
    return tmp1.y2<tmp2.y2;
}

int main(void)
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
            a[i].init();
            b[i]=a[i];
            b2[i]=a[i];
        }
        sort(b,b+n,cmpx1);
        sort(b2,b2+n,cmpx2);
//        for(int i=0;i<n;i++)
//        {
//            cout<<b[i].x1<<" "<<b[i].x2<<endl;
//
//        }
       // cout<<endl;
     //   for(int i=0;i<n;i++)
     //   cout<<b2[i].x1<<" "<<b2[i].x2<<endl;
        int p1=n-1,p2=0;
        LL ans=0;

         //   cout<<b[p1].x1<<" "<<b2[p2].x2<<endl;
        while(b[p1].x1>b2[p2].x2){
        //    cout<<b[p1].x1<<" "<<b2[p2].x2<<endl;
            ans+=max(0ll,1ll*b[p1].x1-1ll*b2[p2].x2);
            p1--;
            p2++;
        }
        for(int i=0;i<n;i++) b[i]=b2[i]=a[i];
        sort(b,b+n,cmpy1);
        sort(b2,b2+n,cmpy2);
        p1=n-1,p2=0;
        while(b[p1].y1>b2[p2].y2){
            ans+=max(0ll,1ll*b[p1].y1-1ll*b2[p2].y2);
            p1--;
            p2++;
        }
        printf("%lld\n",ans);
    }
}
