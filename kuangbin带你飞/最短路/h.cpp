#include<iostream>
#include<string.h>
#include<string>
#include<stack>
#include<vector>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define mem(a,b) memset(a,b,sizeof(a))
vector <int > out[105];
vector <int > in[105];
int maze[105][105];
int ru[105];
int chu[105];
int n,m;
int used[105];
int find_chu(int t)
{
    //cout<<t<<endl;
    mem(used,0);
    stack<int> s;
    s.push(t);
    int ans=0;
    used[t]=1;
    while(!s.empty())
    {
        int top=s.top();
        s.pop();
        if(out[top].size()>0)
        rep(i,0,out[top].size()-1)
        {
            if(used[i]==1)
                continue;
            else
            {
                ans++;
                s.push(out[top][i]);
                used[out[top][i]]=1;
            }
        }
    }
    return ans ;
}

int find_ru(int t)
{
    //cout<<t<<" 2" <<endl;
    mem(used,0);
    stack<int> s;
    s.push(t);
    int ans=0;
    used[t]=1;
    while(!s.empty())
    {
        int top=s.top();
        //cout<<"top:"<<top<<" "<<in[top].size()<<endl;
        s.pop();
        if(in[top].size()>0)
        rep(i,0,in[top].size()-1)
        {
            //cout<<in[top][i]<<endl;
            if(used[in[top][i]]==1)
                continue;
            else
            {
                ans++;
                s.push(in[top][i]);
                used[in[top][i]]=1;
            }
        }
    }
    return ans;
}

int main ()
{
    //freopen("test.txt","r",stdin);
    mem(maze,0);
    scanf("%d%d",&n,&m);
    rep(i,1,n)
        chu[i]=ru[i]=-1;

    int s,e;

    rep(i,1,m)
    {
        scanf("%d%d",&s,&e);
        out[s].push_back(e);
        in[e].push_back(s);
        //maze[e][s]=-1;
    }
    //cout<<"111"<<endl;
    int ans=0;
    rep(i,1,n)
    {
        //cout<<find_chu(i)<<" "<<find_ru(i)<<endl;
        if(find_chu(i)+find_ru(i)==n)
        {
            //cout<<i<<endl;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
