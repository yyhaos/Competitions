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

int can[30005];
void dfs(int x){
    if(x>3000)
        return ;
    if(can[x]==0){
        can[x]=1;
        if(x%2==0)
        {
            dfs(3*x/2);
        }
        if(x>1)
            dfs(x-1);
    }
}
int main ()
{
//    memset(can,0,sizeof(can));
//    dfs(7);
//    for(int i=1;i<=3000;i++)
//    {
//        if(can[i])
//        printf("%d ",i);
//    }
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        if(x>=4)
        {
            printf("Yes\n");
        }
        else if(x>=2 && y<=3)
        {
            printf("Yes\n");
        }
        else if(x==1 && y==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
