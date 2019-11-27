
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fa[100005];
ll fi(ll x)
{
    if(fa[x]==x)return x;
    else return fa[x]=fi(fa[x]);
}
ll un(ll x,ll y)
{
    if(fi(x)==fi(y))return 0;
    fa[fi(x)]=fi(y);
    fi(x);
    fi(y);
    return 1;
}

    ll n,m;
ll ru[100005];
vector<ll> M[100005];
ll vis[100005];
ll previs[100005];
set<int> st,g[100005];
void bfs(ll s)
{
    queue<int> q;
    q.push(s);st.erase(s);
    while(q.size())
    {
        int u=q.front();
        q.pop();
        vector<int > v;
        vis[u]=1;
        for(set<int>::iterator it = st.begin();it!=st.end();it++){
            if(g[u].find(*it)==g[u].end())
            {
                v.push_back(*it);q.push(*it);
            }
        }
        for(int i=0;i<v.size();i++)st.erase(v[i]),vis[v[i]]=1;
    }
}
signed main ()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    #endif // yyhao
    memset(ru,0,sizeof(ru));
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        st.insert(i);
    for(ll i=0;i<m;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
//        M[u].push_back(v);
//        M[v].push_back(u);
//        ru[u]++;
//        ru[v]++;
        g[u].insert(v);
        g[v].insert(u);
    }

ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])bfs(i),ans++;
    }

    printf("%lld",ans-1);


    return 0;
}
