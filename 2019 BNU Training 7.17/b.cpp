#include<bits/stdc++.h>
#define mem(a,b) memset(a,(b),sizeof(a))
using namespace std;
const int MAXN=1e5+5;
int a[MAXN];
int b[MAXN];
int main(void)
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("task.in","r",stdin);
#endif

    int t;scanf("%d",&t);
    while(t--){
        int ans=0;
        int n;scanf("%d",&n);
        for(int i=1;i<=n+1;i++)a[i]=b[i]=0;
        for(int i=0;i<n;i++){
            int x;scanf("%d",&x);
            if(x>n) ans++;
            else a[x]++;
        }
        if(a[1]==0){
            a[1]=1;ans++;
        }
        for(int i=1;i<=n;i++){
            if(a[i]>1) ans+=a[i]-1,a[i]=1;
        }
        int tmp=0;
        int f=1;
        for(int i=n;i>=1;i--)
            b[i]=b[i+1]+a[i];
        int pos=n;
        for(int i=n;i>=1;i--){
            if(a[i]>0){
                pos=i;break;
            }
        }
        int del=0;
       // printf("%d\n",b[1]);
        for(int i=pos-1;i>=1;i--){
            if(a[i]==0){
                tmp++;
            }
            else{
                if(b[i]-1-del<=tmp){
                    tmp=0;
                    ans+=b[i]-del-1;
                    del+=b[i]-1;
                }
            }
        }
        printf("%d\n",ans+tmp);
    }
}
