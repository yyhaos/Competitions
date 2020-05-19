//Problem
#include<bits/stdc++.h>
#include<ext/rope> //using __gnu_cxx
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

ll t,n,m;
vector <int> M[10005];
int si[100005];
int getsi(int x){
    si[x]=-1;
   // cout<<"get:"<<x<<endl;
    int tmp=1;
    int ma=M[x].size();
    for(int i=0;i<ma;i++){
        int nxt=M[x][i];
        if( si[nxt] ==0){
            tmp+=getsi(nxt);
        }
    }
    return si[x]=tmp;
}

int pos[1010][20];
int ke[20];
int used[10005];

void dfs(int x,int now_x,int now_y){
    int ma=M[x].size();
    int math=-1;
    int masi=-1;

//    cout<<x<<" "<<now_x<<" "<<now_y<<" ma:"<<ma<<endl;
    for(int i=0;i<ma;i++){
        int nxt=M[x][i];
        if(nxt!=x && used[nxt]==0){
            if(masi<si[nxt])
            {
                masi=si[nxt];
                math=nxt;
            }
        }
    }
    for(int i=0;i<ma;i++){
        int nxt=M[x][i];
        if(nxt!=math && nxt!=x && used[nxt]==0){
            int ny=now_y+1;
    used[nxt]=1;
            pos[++ke[ny]][ny]=nxt;
            dfs(nxt,ke[ny],ny);
        }
    }



    if(math!=-1){

    used[math]=1;
        pos[++ke[now_y]][now_y]=math;
        dfs(math,ke[now_y],now_y);
    }

}
int ax[1005];
int ay[1005];
int mx,my;

void test(int gen){
    mx=my=-1;
    memset(used,0,sizeof(used));
    used[gen]=1;
    for(int i=0;i<20;i++){
        ke[i]=-1;
    }
    //memset(ke,0,sizeof(ke));
    ke[0]=0;
    memset(si,0,sizeof(si));

    getsi(gen);
//    for(int i=1;i<=n;i++){
//        cout<<"si:"<<i<<"="<<si[i]<<endl;
//    }
    memset(pos,0,sizeof(pos));
    pos[0][0]=gen;

    dfs(gen,0,0);


    for(int i=0;i<1010;i++){
        for(int j=0;j<20;j++){
            if(pos[i][j]>0){
                ax[pos[i][j]]=i;
                ay[pos[i][j]]=j;
                mx=max(mx,i);
                my=max(mx,j);
            }
        }
    }
}

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
    cin>>n;

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
       // a--;b--;
        M[a].push_back(b);
        M[b].push_back(a);
    }


    for(int ge=1;ge<=n;ge++){
        test(ge);
        if( (mx+1) * (my+1) >9*n){
            continue;
        }
 for(int i=1;i<=n;i++){
        cout<<ax[i]<<" "<<ay[i]<<endl;
    }

//    for(int i=0;i<=10;i++){
//        for(int j=0;j<=5;j++){
//            printf("%4d",pos[i][j]);
//        }
//        printf("\n");
//    }

        break;

    }


//
#ifdef use_t
}
#endif // use_t
    return 0;
}

