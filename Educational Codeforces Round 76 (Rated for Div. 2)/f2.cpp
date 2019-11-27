#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int a[105];
int bi[105][45];
int tbi[105][45];
int s[105];
void trans(int x,int a[45]){
    int cnt=0;
    for(int i=0;i<30;i++)a[i]=0;
//    memset(a,0,sizeof(a)*35);
    while(x>0)
    {
        a[cnt]=x%2;
        x/=2;
        cnt++;
    }
}
const ll q=37;
//struct pp
//{
//    int pre;
//    ll change;
//    pp(){}
//    pp(int _p,int _c){
//        pre=_p,change=_c;
//    }
//    bool operator < pp(b){
//        return change<b.change;
//    }
//};
map<ll, int> mp;
int main ()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    #endif // yyhao
    cin>>n;
    memset(bi,0,sizeof(bi));
    memset(s,0,sizeof(s));
    int fa=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        trans(a[i],bi[i]);
        for(int j=0;j<35;j++){
            if(bi[i][j]==1)
                s[i]++;
        }
//        printf("s:%d\n",s[i]);
    }
//    printf("1\n");
    for(int i=(1<<15)-1;i>=0;i--){
        int now=i<<15;

        for(int j=0;j<n;j++){
            trans(a[j]^now , tbi[j]);

        }

            ll has=0;
//            if(now ==0)
          for(int j=0;j<n;j++){
            has*=q;
            for(int k=15;k<30;k++){
                has+= bi[j][k] - tbi[j][k];
            }
//            if(now ==0)

//            printf("%d,%d Has:%lld\n",a[j]^now ,a[j],has);

        }
        mp[has]=now+1;
//        if(now ==0)
//            printf("Has:%lld\n",has);
    }

//    printf("2\n");
    for(int i=0;i<(1<<15);i++){
        for(int j=0;j<n;j++){
            trans( a[j]^i , tbi[j] );
        }
        for(int off=-30;off<=0;off++){
            ll has=0;
            for(int j=0;j<n;j++){
                has*=q;
                for(int k=0;k<15;k++){
                    has+= tbi[j][k]-bi[j][k] ;
                }
                has+=s[j]+off;
            }
            if(mp[has]!=0){
//                    printf("ii:%d off:%d has:%d\n",i,off,has);
                printf("%d\n",i ^ (mp[has]-1));
//                int ans= i^ (mp[has]-1);
//                for(int i=0;i<n;i++){
//                    trans(a[i]^ans, bi[i]);
//                }
//                for(int i=0;i<n;i++){
//                    int cnt=0;
//                    for(int j=0;j<30;j++){
//                        cnt+=bi[i][j];
//                    }
//                    printf("%d ",cnt);
//                }
                return 0;
            }
        }
    }
    printf("-1");

    return 0;
}
