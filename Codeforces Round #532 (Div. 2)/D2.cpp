//	yyhaos
//  Problem:

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define mem(a,b) memset(a, b, sizeof(a))
const ll q=1e9+7;
ll power(ll a,ll e){ll ans=1LL;while(e){if(e&1)ans=(ans*a)%q;a=a*a%q;e>>=1;}return ans%q;}
ll gcd(ll a,ll b){return b ? gcd(b, a%b) : a;}
const double eps=1e-8;
const ll maxn=1e6;
int maze[1005][1005];
int mx[1005];
int my[1005];

struct cnt
{
    int num,w;
    friend bool operator < (cnt a,cnt b);
} C[4];

bool operator < (cnt a, cnt b)
{
    return a.num<b.num;
}

int main ()
{
//    cin_base::sync_with_stdcin(0);
	//cin.tie(0);
	cout.tie(0);
    mem(C,0);
    #ifdef yyhaos
        freopen("test.txt", "r", stdin);
    #endif
    mem(maze,0);
    int x,y;
    int ttx,tty;

    cin>>ttx>>tty;
    for(int i=1;i<=666;i++)
    {
        cin>>x>>y;
        maze[x][y]=1;
        mx[i]=x;
        my[i]=y;
    }

    int th,tx,ty;
    int m=501;
    rep(i,0,3)
        C[i].w=i;
    rep(i,1,1000)
        rep(j,1,1000)
        {
            if(maze[i][j]==1)
            {
                if(i<m && j<m)
                    C[0].num++;
                else if(i<m)
                    C[2].num++;
                else if(j<m)
                    C[1].num++;
                else
                    C[3].num++;
            }
        }
    sort(C,C+4);
    int xx,yy;
    if(C[0].w %2==0)
    {
        xx=999;
    }
    else xx=1;
    if(C[0].w <=1)
    {
        yy=999;
    }
    else yy=1;
    //cout<<C[0].num<<" "<<C[0].w<<endl;
    //cout<<"ta"<<xx<<" "<<yy<<endl;
    while(ttx!=xx || tty!=yy)
    {
        if(tty<yy)
            tty++;
        else tty--;
        if(ttx<xx && maze[ttx+1][tty]==0)
            ttx++;
        else if(ttx>xx && maze[ttx-1][tty]==0)
            ttx--;
        if(maze[ttx][tty]==1)
            exit(0);
        cout<<ttx<<" "<<tty<<endl;

        cin>>th>>tx>>ty;
        if(th<=-1)
        {
           // cout<<"-1 -1\n"<<endl;
            exit(0);
        }
        if(th<=0)
        {
           // cout<<"-1 -1\n"<<endl;
            exit(0);
        }

        maze[mx[th]][my[th]]=0;
        maze[tx][ty]=1;
        mx[th]=tx;
        my[th]=ty;

       // cout.flush();
    }
    xx=1000-xx;
    yy=1000-yy;
    while(ttx!=xx || tty!=yy)
    {
        if(tty<yy)
            tty++;
        else tty--;
        if(ttx<xx && maze[ttx+1][tty]==0)
            ttx++;
        else if(ttx>xx && maze[ttx-1][tty]==0)
            ttx--;
        if(maze[ttx][tty]==1)
            exit(0);
        cout<<ttx<<" "<<tty<<endl;

        cin>>th>>tx>>ty;
        if(th<=-1)
        {
           // cout<<"-1 -1\n"<<endl;
            exit(0);
        }
        if(th<=0)
        {
           // cout<<"-1 -1\n"<<endl;
            exit(0);
        }

        maze[mx[th]][my[th]]=0;
        maze[tx][ty]=1;
        mx[th]=tx;
        my[th]=ty;

       // cout.flush();
    }
    //fflush(stdout);
    //cout.flush();

    #ifdef yyhaos
        cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

