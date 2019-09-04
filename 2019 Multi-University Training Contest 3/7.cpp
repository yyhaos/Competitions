#include<bits/stdc++.h>
using namespace std;
#define ll long long



struct mll
{
    ll v;
    mll(ll _v=0)
    {
        v=_v;
    }
    friend bool operator<(mll a, mll b)
    {
        return a.v<b.v;
    }
    ~mll(){}
};
ll chu[200005];
ll cnt=0;
int main ()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
ll n=2e5;
//    cout<<n<<" "<<n<<endl;
//    for(int i=1;i<=n;i++)
//    {
//        cout<<n<<" ";
//    }
//    cout<<endl;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n ,m ;
        cin>>n>>m;
        ll sum=0;
        ll ans=0;
        ll tmp;
        priority_queue<mll> pq;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&tmp);
//            cout<<tmp<<":"<<sum<<":"<<ans<<endl;

            sum+=tmp;
            cnt=0;
            while(sum>m)
            {
                ans++;
                sum-=pq.top().v;
//                cout<<"out:"<<pq.top().v<<endl;
                chu[cnt++]=pq.top().v;
                pq.pop();
            }
            printf("%lld",ans);
            if(i<n-1)
                printf(" ");

//            cout<<tmp<<" - "<<cnt<<" - "<<sum<<endl;
            if(cnt)
            {
                sum-=tmp;
                ans++;
                chu[cnt-1]=min(chu[cnt-1],tmp);
                sort(chu,chu+cnt);
                for(int i=0;i<cnt && sum+chu[i]<=m;i++)
                {
//                    cout<<"in:"<<chu[i]<<endl;
                    ans--;
                    sum+=chu[i];
                    pq.push(mll(chu[i]));
                }
            }
            else
            {
//                 cout<<"in:"<<tmp<<endl;
                pq.push(mll(tmp));
            }

        }
        printf("\n");

    }
    return 0;
}
