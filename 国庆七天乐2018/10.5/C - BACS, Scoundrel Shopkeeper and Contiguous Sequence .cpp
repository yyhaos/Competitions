
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int T;
    scanf("%d",&T);
    int tot = 1;
    while(T--){
        ll M,N;
        scanf("%lld%lld",&M,&N);
        int last = -1;
        ll sum = 0;
        int a;
        int flag = 0;
        for(int i = 0;i<N;i++){
            scanf("%d",&a);
            if(flag == 0){
                if(a - last == 1)
                    flag = 1;
            }
            last = a;
            sum+=a;
        }
        printf("Case %d: Thank You BACS!!! ",tot++);
        if(sum == M)
            printf("Thik ache. ");
        else
            printf("Bojjat dokandar!! ");
        if(flag == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
