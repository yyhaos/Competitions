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
    ll dcnt=0;//�Ѿ��е��˺�
    ll st=0;//��û������
    ll ans=0;//�𰸴��� ʹ��
    ll nt=1;//��Ҫ���еĵ�nt���˺�
    while(!pq.empty())
    {
        guai t=pq.top();
        pq.pop();
        #ifdef de
        cout<<"��"<<t.th<<"���ֳ��� Ѫ��Ϊ"<<t.h<<" ��ǰ�˺���"<<dcnt<<" ���������˺��ִ���"<<nt<<endl;
        #endif // de
        if(dcnt>=t.h)
        {
            #ifdef de
            cout<<"����"<<t.th<<"ֱ������"<<" ��Ϊ"<<ans<<" �����У�";
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
            ll cha=t.h-dcnt;//ʵ���˺���
            ll lun=cha/sd[m];//����˺��ִ�
            ll sheng=cha%sd[m];//���ִκ�Ļ�����˺���
            dcnt+=lun*sd[m];//�����˺���
            #ifdef de
            cout<<"����ԭѪ��Ϊ"<<t.h<<" "<<"�˺��ִ��У�"<<lun<<" ��ʣ��"<<sheng<<"Ѫ�� �˺�������Ϊ"<<dcnt<<endl;
            #endif // de
            if(lun>0)
            {
                ans+=lun*m-st;//����lun*m-st�� ���st=1˵�����һ��
                st=0;//�������
            }

            if(sheng==0)//������
            {
                #ifdef de
            cout<<"����"<<t.th<<"ǡ������"<<" ��Ϊ"<<ans<<" �����У�";
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
                cout<<"�������ִ��˺���Ĵ�Ϊ"<<ans<< " ";
                #endif // de
                ll tsheng = sd[nt-1]+sheng;//����ǰ����˺������ڼ�����Ҫ���ٴ�
                ll tar = lower_bound(sd+1,sd+2*m,tsheng)-sd;//ǡ���������˺��ִ�
                ll jg = tar-nt+1;//��Ҫjg���ִΡ�
                ll ts=sd[tar]-sd[nt-1];//��ʵ���˺���
                dcnt+=ts;
                nt=tar+1;
                if(nt>m)
                    nt-=m;
                if(nt>m)
                    nt-=m;//����nt
                ans+=jg-st;
                st=1;
                #ifdef de
            cout<<"�������ִι�����Ѫ��Ϊ"<<tsheng<<" "<<"�����˺��ִ��ǣ�"<<nt<<" �������˺��ִ���"<<tar <<" "<<" �˺�������Ϊ"<<dcnt<<endl;

            cout<<"����"<<t.th<<"����"<<" ��Ϊ"<<ans<<" �����У�";
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
                //    tar=tar-m;//����


            }
        }
    }
    cout<<ans<<endl;


#ifdef use_t
}
#endif // use_t
    return 0;
}
