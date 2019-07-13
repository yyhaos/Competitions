#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mst(a) memset(a,0,sizeof a)

const int maxn=1e3+7;
const int mod=1e9+7;
const int inf = 0x3f3f3f3f;
const double eps=1e-8;

struct node
{
    char s;
    char c;

    friend bool operator < (node a,node b)
    {
        if(a.s!=b.s)return a.s<b.s;
        else return a.c<b.c;
    }

}a[maxn];

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
        int n,m;
        cin>>n>>m;

        for(int i=1;i<=n;++i)
        {
            cin>>a[i].s;
        }
//        getchar();
        for(int i=1;i<=n;++i)
        {
            cin>>a[i].c;
        }

//        for(int i=1;i<=n;++i)
//        {
//            cout<<a[i].s<<' '<<a[i].c<<endl;
//        }

        sort(a+1,a+n+1);

        char p[m+1];
        cin>>p;
//cout<<p<<endl;
//cout<<p[m-1]<<endl;
        sort(p,p+m);

        int fl=1;
        for(int i=0;p[i];++i)
        {
           // cout<<p[i]<<endl;
            int fa=0;
            for(int j=1;j<=n;++j)
            {
                if(p[i]==a[j].s)
                {
                    fa=1;
                    break;
                }
            }
            if(!fa)
            {
                fl=0;
                break;
            }
        }
        if(!fl)cout<<"-1"<<endl;
        else
        {

            int ans=0;
            for(int i=0;p[i];++i)
            {
                for(int j=1;j<=n;++j)
                {
                    if(a[j].s==p[i])
                    {
                        ans+=a[j].c-'0';
                        break;
                    }
    //                cout<<i<<' '<<now<<' '<<ans<<endl;

                }

            }

            cout<<ans<<endl;

        }



    }








    return 0;
}
