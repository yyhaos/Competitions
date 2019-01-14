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

struct cin_Tp
{
	bool is_digit(const char ch)
	{
		return '0' <= ch && ch <= '9';
	}

	cin_Tp& operator>>(int& res)
	{
		res = 0;
		static char ch;
		while (ch = getchar(), !is_digit(ch))
			;
		do
			(res *= 10) += ch & 15;
		while (ch = getchar(), is_digit(ch));
		return *this;
	}
} ciaa;
int main ()
{
//    cin_base::sync_with_stdcin(0);
	//cin.tie(0);
	cout.tie(0);

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
    int si=-50,mi=50;
    int midis,mix,miy;
    while(1)
    {

        midis=99999999;
        for(int i=si;i<=mi;i++)
        {
            for(int j=si;j<=mi;j++)
            {
                if(maze[i][j]==1)
                {
                    if(midis>fabs(i-ttx)+fabs(j-tty))
                    {
                        midis=fabs(i-ttx)+fabs(j-tty);
                        mix=i;
                        miy=j;
                    }
                }
            }
        }
        int sx=-1,sy=-1;
        if(mix<ttx)
        {
            sx=1;
        }
        if(miy<tty)
            sy=1;
        sx=-sx;
        sy=-sy;
        if(th%2==0)
        {
            ttx+=sx;
            if(ttx<=0)
            {
                ttx++;
                tty+=sy;
                if(tty<=0)
                {
                    tty+=2;
                }
                if(tty>=1000)
                {
                    tty-=2;
                }
            }
            if(ttx>=1000)
            {
                ttx--;
                tty+=sy;
                if(tty<=0)
                {
                    tty+=2;
                }
                if(tty>=1000)
                {
                    tty-=2;
                }
            }
        }
        else
        {
            tty+=sy;
            if(tty<=0)
            {
                tty++;
                ttx+=sx;
                if(ttx<=0)
                {
                    ttx+=2;
                    if(ttx>=1000)
                        ttx-=2;
                }
                if(ttx>=1000)
                {
                    ttx-=2;

                }
                if(ttx>=1000)
                        ttx-=2;
            }
            if(tty>=1000)
            {
                tty--;
                ttx+=sx;
                if(ttx<=0)
                {
                    ttx+=2;

                }
                if(ttx>=1000)
                        ttx-=2;
            }
        }

               cout<<ttx<<" "<<tty<<'\n';
        cout.flush();
        cin>>th>>tx>>ty;
        if(th<=-1)
        {
           // cout<<"-1 -1\n"<<endl;
            return 0;
        }
        if(th==0)
        {
           // cout<<"-1 -1\n"<<endl;
            return 0;
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
