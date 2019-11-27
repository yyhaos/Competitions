//https://codeforces.com/contests/1257
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll q=1e9+7;
ll ksm(ll a, ll b){
    ll ans=1;while(b){
        if(b&1){
            ans=ans*a%q;
        }a=a*a%q;b/=2;
    }return ans;
}
int a[200005];
int cnt[200005];
vector<int > M[200005];
int main ()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    #endif // yyhao
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }
        if(n==1){
            printf("-1\n");
        }
        else if(n==2)
        {
            if(a[0]==a[1]){
                printf("2\n");
            }
            else
                printf("-1\n");
        }
        else
        {
            for(int i=0;i<n;i++)
                cnt[i]=0;
            for(int i=0;i<n;i++)
            {
                M[a[i]].push_back(i);
            }
            int ans=3e5;
            for(int i=0;i<=n;i++)
            {
                int si=M[i].size();
                if(si<=1){}
                else
                {
                    for(int j=0;j<si-1;j++)
                    {
                        ans=min(ans,M[i][j+1]-M[i][j]+1);
                    }
                }
                    M[i].clear();
            }
            if(ans>n)
                ans=-1;
            printf("%d\n",ans);

        }
    }

    return 0;
}

