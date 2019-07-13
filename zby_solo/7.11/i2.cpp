#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mst(a) memset(a,0,sizeof a)

const int maxn=1e4+7;
const int mod=1e9+7;
const int inf = 0x3f3f3f3f;
const double eps=1e-8;

int a[maxn];

signed main()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    #endif // yyhaos

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);

        int cnt=0;
        for(int i=1;a[i]<0;++i)
        {
            cnt++;
        }

        for(int i=1;i<=k,i<=cnt;++i)
        {
            a[i]=-a[i];
        }
        if(cnt>=k) goto sss;

        else
        {
            sort(a+1,a+n+1);
            int fl=(k-cnt)%2;
            if(fl==1)a[1]=-a[1];
        }



        sss: ;
        int ans=0;
        for(int i=1;i<=n;++i) ans+=a[i];

        cout<<ans<<endl;



    }






    return 0;
}
