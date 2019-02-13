#include<bits/stdc++.h>
using namespace std;
char s[1005][1005];
int n,m;
int r,c,x,y;
int ans=0;
int vis[1005][1005];
struct sta
{
    int i,j;
    int tx,ty;
    sta(int ii=0,int jj=0,int ttx=0,int tty=0)
    {
        i=ii;
        j=jj;
        tx=ttx;
        ty=tty;
    }
    friend bool operator < (sta a, sta b)
    {
        return a.tx+a.ty<b.tx+b.ty;
    }
};
priority_queue<sta> q;
void dfs()
{
    while(!q.empty())
        q.pop();
    memset(vis,0,sizeof(vis));
    q.push(sta(r-1,c-1,x,y));
    sta tmp;
    while(!q.empty())
    {
        tmp=q.top();
        q.pop();
        //cout<<tmp.i<<" "<<tmp.j<<endl;
        if(vis[tmp.i][tmp.j]==1)
            continue;
        vis[tmp.i][tmp.j]=1;
        ans++;
        s[tmp.i][tmp.j]='+';
        if(tmp.i-1>=0&& s[tmp.i-1][tmp.j]=='.' && vis[tmp.i-1][tmp.j]==0)
        {
            q.push(sta(tmp.i-1,tmp.j,tmp.tx,tmp.ty));
        }
        if(tmp.i+1<n  && s[tmp.i+1][tmp.j]=='.' && vis[tmp.i+1][tmp.j]==0)
        {
            q.push(sta(tmp.i+1,tmp.j,tmp.tx,tmp.ty));
        }
        if(tmp.j+1<m&& tmp.ty>0  && s[tmp.i][tmp.j+1]=='.' && vis[tmp.i][tmp.j+1]==0)
        {
            q.push(sta(tmp.i,tmp.j+1,tmp.tx,tmp.ty-1));
        }
        if(tmp.j-1>=0 && tmp.tx>0  && s[tmp.i][tmp.j-1]=='.' && vis[tmp.i][tmp.j-1]==0)
        {
            q.push(sta(tmp.i,tmp.j-1,tmp.tx-1,tmp.ty));
        }
    }
}
int main ()
{
    cin>>n>>m;
    ans=0;

    //int r,c;
    cin>>r>>c;
    //int x,y;
    cin>>x>>y;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    dfs();
    cout<<ans;

//    cout<<endl;
//    for(int i=0;i<n;i++)
//    {
//        cout<<s[i]<<endl;
//        //scanf("%s",s[i]);
//    }
    return 0;
}
