#include<bits/stdc++.h>
using namespace std;
#define shui 1
#define huo 0
int n,m;
char mz[105][105];
int dp[105][105][2];
int si,sj,ei,ej;
int fi[4]={0,0,1,-1};
int fj[4]={1,-1,0,0};
struct state
{
    int i,j,now,zhuang;
    state(int ii=0,int jj=0,int N=0,int Z=0)
    {
        i=ii;
        j=jj;
        now=N;
        zhuang=Z;
    }
    friend bool operator < (state a,state b)
    {
        return a.now>b.now;
    }
};

void bfs()
{
    int ti,tj,tn,tz;
    priority_queue<state> q;
    state tmp,start(si,sj,0,shui);
    q.push(start);
    while(!q.empty())
    {
        tmp=q.top();
        q.pop();
        ti=tmp.i;
        tj=tmp.j;
        tn=tmp.now;
        tz=tmp.zhuang;
        //cout<<ti<<"-"<<tj<<"-"<<tn<<"-"<<tz<<endl;
        if(dp[ti][tj][tz]!=-1)
        {
            continue;
        }
        dp[ti][tj][tz]=tn;
        if(mz[ti][tj]=='T')
        {
            while(!q.empty())
                        q.pop();
            continue;
        }

        tn++;
        for(int i=0;i<4;i++)
        {
            ti=tmp.i+fi[i];
            tj=tmp.j+fj[i];
            switch(mz[ti][tj])
            {
                case 'w':
                    if(tz==huo)
                        q.push(state(ti,tj,tn,huo));
                    break;
                case '~':
                    //cout<<"shui::"<<ti<<"-"<<tj<<"-"<<tn<<"-"<<tz<<endl;
                    if(tz==shui)
                        q.push(state(ti,tj,tn,shui));
                    break;
                case '@':
                    q.push(state(ti,tj,tn,tz));
                    q.push(state(ti,tj,tn+1,1-tz));
                    break;
                case '#':
                    break;
                case '.':
                    q.push(state(ti,tj,tn,tz));
                    break;
                case 'T':
                    q.push(state(ti,tj,tn,tz));

                    break;
                case 'S':
                    q.push(state(ti,tj,tn,tz));

                    break;
            }
        }
    }
}
int main ()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%s",mz[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mz[i][j]=='S')
            {
                si=i;
                sj=j;
            }
            if(mz[i][j]=='T')
            {
                ei=i;
                ej=j;
            }
        }
    }
    memset(dp,-1,sizeof(dp));
    bfs();
    if(dp[ei][ej][0]==-1 && dp[ei][ej][1]==-1)
    {
        cout<<"-1";
    }
    else
    {
        cout<<max(dp[ei][ej][0],dp[ei][ej][1]);
    }

//    cout<<endl;
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<m;j++)
//        {
//            cout<<setw(2)<<dp[i][j][0];
//        }
//        cout<<"  ";
//        for(int j=0;j<m;j++)
//        {
//            cout<<setw(2)<<dp[i][j][1];
//        }
//        cout<<endl;
//    }

    return 0;
}
