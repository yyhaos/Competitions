//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=849
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
//#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1000;
const ll q=1e9+7;
ll question[100005];
//ll th;
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a%q;
        a=a*a%q;
        b/=2LL;
    }
    return ans;
}
ll N,C,K;
ll t,n,m;
ll a[100005];
ll cnt[100005];
map<ll,ll> used;
ll tmp[100005];
vector<ll> pos[100005];
ll th=0;
priority_queue<ll> pro;
ll fenl[100005];
ll fenr[100005];
//ll dfs2(ll l , ll r,ll fa);//fa=1 要重新统计 否则不重新统计
ll dfs(ll l , ll r,ll fa)//fa=1 要重新统计 否则不重新统计
{
//    cout<<l<<" "<<r<<" "<<fa<<endl;

    if(r<l)
        return 0;
    if(r==l)
    {
        if(K<=1)
            return 1;
        return 0;
    }
    if(fa==0)//<L-R/2 直接重新统计
    {
        for(int i=l;i<=r;i++)
        {
            cnt[a[i]]=0;
        }
        for(int i=l;i<=r;i++)
        {
            cnt[a[i]]++;
        }
        ll ans=0;
        ll pre=l;
        int i;
        ll duan=0;
        //ll cnt2[a[i]]={0};
        fa=0;
        ll mal,mar;
        ll fen=0;
        for(i=l;i<=r;i++)
        {
           // cnt2[a[i]]++;
            if(cnt[a[i]]<K)
            {
                duan++;
                if(fa==0 && i-1-pre+1 > (r-l+1)/2 )
                {
                    mal=pre;
                    mar=i-1;
                    fa=1;
//                    cout<<fa<<" "<<mal<<" "<<mar<<endl;
                }
                else
                {
                    fenl[fen]=pre;
                    fenr[fen++]=i-1;
                }

                pre=i+1;
                continue;
            }
        }
        if(duan==0)
        {
            ans=r-pre+1;
            return ans;
        }
        else
        {
            if(fa==0 && r-pre+1 > (r-l+1)/2 )
            {
                mal=pre;
                mar=r;
                fa=1;
            }

                else
                {
                    fenl[fen]=pre;
                    fenr[fen++]=r;
                }

        }
        if(fa)
        {
            while(!pro.empty())
            pro.pop();
//            cout<<fa<<" "<<mal<<" "<<mar<<endl;
            for(int i=l;i<mal;i++)
            {
                cnt[a[i]]--;
            }
            for(int i=mar+1;i<=r;i++)
            {
                cnt[a[i]]--;
            }
            for(int i=l;i<mal;i++)
            {
                if(cnt[a[i]]<K && cnt[a[i]])
                {
                    pro.push(a[i]);
                }
            }
            for(int i=mar+1;i<=r;i++)
            {
                if(cnt[a[i]]<K && cnt[a[i]])
                {
                    pro.push(a[i]);
                }
            }

            ans=max(ans,dfs(mal,mar,1));//必须先递归 大的
        }
        fa=0;
        for(int i=0;i<fen;i++)
        {
            ans=max(ans,dfs(fenl[i],fenr[i],0));
        }
        return ans;
    }
    else// 利用cnt 和 pro
    {
//        cout<<pro.size();
//        if(pro.size())
//            cout<<" "<<pro.top()<<endl;
//        else
//            cout<<endl;
        ll th=0;
        ll pre=-1,fr;
        ll fen=0;
        while(!pro.empty())
        {
            fr=pro.top();
            pro.pop();
            if(fr==pre)
                continue;
            pre=fr;

                ll np;
            ll si=pos[fr].size();
            for(int i=0;i<si;i++)
            {
                np=pos[fr][i];
                if(np>= l && np<=r)
                {
                    question[th++]=np;
                }
            }
        }
        if(th==0)
        {
            return r-l+1;
        }
        ll ans=0;fa=0;ll mal,mar;

//        cout<<th<<endl;
        for(int i=0;i<th;i++)
        {
            if(i==0)
            {
                if(fa==0 && question[i]-1-l+1 > (r-l+1)/2 )
                {
                    mal=l;
                    mar=question[i]-1;
                    fa=1;
    //                cout<<fa<<" "<<mal<<" "<<mar<<endl;
                }

                else
                {
                    fenl[fen]=l;
                    fenr[fen++]=question[i]-1;
                }

            }
            if(i==th-1)
            {
                if(fa==0 && r-question[i] > (r-l+1)/2 )
                {
                    mal=question[i]+1;
                    mar=r;
                    fa=1;
    //                cout<<fa<<" "<<mal<<" "<<mar<<endl;
                }

                else
                {
                    fenl[fen]=question[i]+1;
                    fenr[fen++]=r;
                }

            }
            if(i && i-th+1)
            {
                if(fa==0 && question[i+1]-1-question[i] > (r-l+1)/2 )
                {
                    mal=question[i]+1;
                    mar=question[i+1]-1;
                    fa=1;
    //                cout<<fa<<" "<<mal<<" "<<mar<<endl;
                }

                else
                {
                    fenl[fen]=question[i]+1;
                    fenr[fen++]=question[i+1]-1;
                }

            }
        }
        if(fa)
        {
            while(!pro.empty())
            pro.pop();
    //        cout<<fa<<" "<<mal<<" "<<mar<<endl;
            for(int i=l;i<mal;i++)
            {
                cnt[a[i]]--;
            }
            for(int i=mar+1;i<=r;i++)
            {
                cnt[a[i]]--;
            }
            for(int i=l;i<mal;i++)
            {
                if(cnt[a[i]]<K && cnt[a[i]])
                {
                    pro.push(a[i]);
                }
            }
            for(int i=mar+1;i<=r;i++)
            {
                if(cnt[a[i]]<K && cnt[a[i]])
                {
                    pro.push(a[i]);
                }
            }
            ans=max(ans,dfs(mal,mar,1));
        }
        fa=0;
        for(int i=0;i<fen;i++)
        {
            ans=max(ans,dfs(fenl[i],fenr[i],0));
        }
        return ans;
    }

}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
//    freopen("in.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
//cout<<"99999 100000 2"<<endl;
//
//cout<<1<<" ";
//for(int i=2;i<=49999;i++)
//{
//    cout<<i<<" "<<i-1<<" ";
//}
//cout<<"100000 100000 10"<<endl;
//    for(int i=1;i<=100000;i++)
//    {
//        cout<<i<<" ";
//    }
//    cout<<endl;
//cout<<"100000 100000 10"<<endl;
//    for(int i=1;i<=100000;i++)
//    {
//        cout<<1<<" ";
//    }
//    cout<<endl;
//cout<<"100000 100000 10"<<endl;
//    for(int i=1;i<=100000;i++)
//    {
//        if(i%10)
//            cout<<1<<" ";
//        else
//            cout<<2<<" ";
//    }
//    cout<<endl;


    while(cin>>N>>C>>K)
    {
        for(int i=1;i<=C;i++)
        {
            pos[i].clear();
        }
        for(int i=1;i<=N;i++)
        {
            scanf("%lld",a+i);
            pos[a[i]].push_back(i);
        }
        cout<<dfs(1,N,0)<<"\n";
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}


