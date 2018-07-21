
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+6;
//https://www.nowcoder.com/acm/contest/view-submission?submissionId=29721668
int v[maxn],a[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if (i!=0){
                v[i-1] = a[i]-a[i-1];
            }
        }
        ll sum = 0;
        int t = 0;
        int last = 0;
        for (int i=0;i<n-1;i++){
            if (i==0){
                if (v[i]>0){
                    last = 1;
                    sum+=v[i]*1ll;
                    t++;
                }else{
                    last = -1;
                }
            }else{
                if (v[i]>0){
                    if (last==1){
                        sum+=v[i]*1ll;
                    }else if (last==0){
                        continue;
                    }else{
                        t++;
                        sum+=v[i]*1ll;
                        last = 1;
                    }
                }else if (v[i]<0){
                    if (last == -1){
                        continue;
                    }else if (last == 1){
                        t++;
                        last = -1;
                    }
                }
            }
        }
        if (t%2!=0){
            t++;
        }

        if (sum<=0)
            t = 0;
        printf("%lld %d\n",sum,t);
    }
    return 0;
}
