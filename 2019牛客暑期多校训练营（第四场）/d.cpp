#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int maxn=1e5+5;

int num[70];
int ans1[70],ans2[70];
int main(void)
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int _;scanf("%d",&_);
    while(_--){
        for(int i=0;i<70;i++) num[i]=ans1[i]=ans2[i]=0;
        LL a;scanf("%lld",&a);
        if(a%3==0){
            printf("1 %lld\n",a);
        }
        else{
            for(int i=0;(1ll<<i)<=a;i++){
                if(a&(1ll<<i)) num[i]=1;
            }


            int r1=a%3,r2=a%3;
            for(int i=0;i<70;i++) ans1[i]=ans2[i]=num[i];
            int pos=-1;
            for(int i=0;i<70;i++){
                if(r1<=0) break;
                if(ans1[i]==1&&i%2==0){
                        r1--;
                        ans1[i]=0;
                        pos=i;
                }
            }
            if(r1==1&&pos!=-1){ r1++ ; ans1[pos]=1; }
             for(int i=0;i<70;i++){
                if(r1<=0) break;
                if(ans1[i]==1&&i%2==1&&r2>=2){
                        r1-=2;
                        ans1[i]=0;
                }
             }

            for(int i=69;i>=0;i--){
                if(r2<=0) break;
                if(ans2[i]==1&&i%2==1&&r2>=2){
                        r2-=2;
                        ans2[i]=0;
                }
            }
             for(int i=69;i>=0;i--){
                if(r2<=0) break;
                if(ans2[i]==1&&i%2==0){
                        r2-=1;
                        ans2[i]=0;
                }
             }

            LL ret1,ret2;
            ret1=ret2=0;
//            for(int i=30;i>=0;i--) printf("%d ",num[i]);puts("");
//             for(int i=30;i>=0;i--) printf("%d ",ans1[i]);puts("");
//              for(int i=30;i>=0;i--) printf("%d ",ans2[i]);puts("");

            for(int i=69;i>=0;i--){
                ret1=ret1*2+ans1[i];
                ret2=ret2*2+ans2[i];
            }
            cout<<a<<" "<<(ret2|ret1)<<":";
            printf("2 %lld %lld\n",ret2,ret1);
        }
    }
}
