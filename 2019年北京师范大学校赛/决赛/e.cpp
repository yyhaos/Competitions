//Problem Web:https://ac.nowcoder.com/acm/contest/895/E
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
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
struct guai
{
    ll h,th;
    guai (ll _h=0,ll _th=0)
    {
        h=_h;
        th=_th;
    }
    friend bool operator < (guai a,guai b)
    {
        return a.h>b.h;
    }
};
priority_queue<guai> pq;
ll t,n,m;
ll h[200005];
ll d[200005];
ll sd[200005];
vector <ll > k[200005];
//#define de 1
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    cin>>n>>m;
    rep(i,1,n)
        scanf("%lld",&h[i]);
    rep(i,1,m)
        scanf("%lld",&d[i]);
    ll tc,tmp;
    rep(i,1,n)
    {
        scanf("%lld",&tc);
        rep(j,1,tc)
        {
            scanf("%lld",&tmp);
            k[i].push_back(tmp);
        }
    }
    ll dc=0;
    rep(i,1,m)
        dc+=d[i];
    rep(i,m+1,2*m)
        d[i]=d[i-m];
    rep(i,1,2*m)
        sd[i]=sd[i-1]+d[i];

    pq.push(guai(h[1],1));
    ll dcnt=0;//已经有的伤害
    ll st=0;//有没有连续
    ll ans=0;//答案次数 使用
    ll nt=1;//将要进行的第nt轮伤害
    while(!pq.empty())
    {
        guai t=pq.top();
        pq.pop();
        #ifdef de
        cout<<"第"<<t.th<<"个怪出来 血量为"<<t.h<<" 当前伤害是"<<dcnt<<" 即将发生伤害轮次是"<<nt<<endl;
        #endif // de
        if(dcnt>=t.h)
        {
            #ifdef de
            cout<<"怪物"<<t.th<<"直接死亡"<<" 答案为"<<ans<<" 并产仔：";
#endif // de
            st=1;
            ll th=t.th;
            ll si=k[th].size();
            for(int i=0;i<si;i++)
            {
                #ifdef de
                cout<<" "<<k[th][i];
                #endif // de
                pq.push(guai( h[k[th][i]]+dcnt,k[th][i]));
            }
            #ifdef de
            cout<<endl;
            #endif // de
            continue;
        }
        else
        {
            ll cha=t.h-dcnt;//实际伤害差
            ll lun=cha/sd[m];//差的伤害轮次
            ll sheng=cha%sd[m];//减轮次后的还差的伤害量
            dcnt+=lun*sd[m];//更新伤害量
            #ifdef de
            cout<<"怪物原血量为"<<t.h<<" "<<"伤害轮次有："<<lun<<" 还剩余"<<sheng<<"血量 伤害量更新为"<<dcnt<<endl;
            #endif // de
            if(lun>0)
            {
                ans+=lun*m-st;//用了lun*m-st次 如果st=1说明免费一次
                st=0;//不再免费
            }

            if(sheng==0)//死亡了
            {
                #ifdef de
            cout<<"怪物"<<t.th<<"恰好死亡"<<" 答案为"<<ans<<" 并产仔：";
                #endif // de
            st=1;
            ll th=t.th;
            ll si=k[th].size();
            for(int i=0;i<si;i++)
            {
                #ifdef de
                cout<<" "<<k[th][i];
            #endif // de
                pq.push(guai( h[k[th][i]]+dcnt,k[th][i]));
            }
            #ifdef de
            cout<<endl;
            #endif // de
                continue;
            }
            else
            {
                #ifdef de
                cout<<"怪物受轮次伤害后的答案为"<<ans<< " ";
                #endif // de
                ll tsheng = sd[nt-1]+sheng;//加上前面的伤害，便于计算需要多少次
                ll tar = lower_bound(sd+1,sd+2*m,tsheng)-sd;//恰好死亡的伤害轮次
                ll jg = tar-nt+1;//需要jg次轮次。
                ll ts=sd[tar]-sd[nt-1];//是实际伤害数
                dcnt+=ts;
                nt=tar+1;
                if(nt>m)
                    nt-=m;
                if(nt>m)
                    nt-=m;//更新nt
                ans+=jg-st;
                st=1;
                #ifdef de
            cout<<"怪物受轮次攻击后血量为"<<tsheng<<" "<<"即将伤害轮次是："<<nt<<" 理论受伤害轮次是"<<tar <<" "<<" 伤害量更新为"<<dcnt<<endl;

            cout<<"怪物"<<t.th<<"死亡"<<" 答案为"<<ans<<" 并产仔：";
                #endif // de
            st=1;
            ll th=t.th;
            ll si=k[th].size();
            for(int i=0;i<si;i++)
            {
                #ifdef de
                cout<<" "<<k[th][i];
                #endif // de
                pq.push(guai( h[k[th][i]]+dcnt,k[th][i]));
            }
            #ifdef de
            cout<<endl;
            #endif // de
                //if(tar>m)
                //    tar=tar-m;//更新


            }
        }
    }
    cout<<ans<<endl;


#ifdef use_t
}
#endif // use_t
    return 0;
}
