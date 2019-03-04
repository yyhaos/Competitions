#include<iostream>
#include<string>
#include<string.h>
#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
using namespace std;
int f[100000];
const int N=600;
int s[100000];
int s2[100000];
int th[100000];
int fg[100000];
int w[100000];
vector<int> rs[100000],rs2[100000];
int fi(int a)
{
    int fa=f[a];
    if(fa!=a)
    {
        return f[a]=fi(fa);
    }
    return a;
}
void u(int a,int b)
{
    if(fi(a)!=fi(b))
    for(int k=0;k<=N;k+=N)
    {
        int ta=(a+k)%(2*N);
        int tb=(b+k)%(2*N);
        f[fi(ta)]=fi(tb);
        fi(ta);
        fi(tb);
    }
}
int cnt=0;
char tmp[50];
int ans[10000];
int dp[1000][1000];
int main ()
{
    freopen("test.txt","r",stdin);
    int n,p1,p2;
    int x,y;
    //cout<<1<<endl;
    while(scanf("%d%d%d",&n,&p1,&p2))
    {
        int peo=p1+p2;
        cnt=1;
        //cout<<n<<p1<<p2<<endl;
        memset(s,0,sizeof(s));
        memset(ans,0,sizeof(ans));
        memset(f,0,sizeof(f));
        memset(w,0,sizeof(w));
        memset(dp,0,sizeof(dp));
        memset(s2,0,sizeof(s2));
        if(n==0)
            return 0;
        for(int i=1;i<=p1+p2+N;i++)
        {
            f[i]=i;
            f[i+N]=i+N;
        }
        int flag=0;
        while(n--)
        {
            scanf("%d%d%s",&x,&y,tmp);
            if(flag==-1)
                continue;
            if(tmp[0]=='y')
            {
                if(fi(x)==fi(y+N) || fi(x)==fi(y+N))
                {
                    flag=-1;
                    continue;
                }
                else
                {
                    u(fi(x),fi(y));
                    fi(x);
                    fi(y);
                }
            }
            else
            {
                if(fi(x)==fi(y) || fi(x+N)==fi(y+N))
                {
                    flag=-1;
                    continue;
                }
                else
                {
                    u(fi(x),fi(y+N));
                    continue;
                }
            }
        }
        if(p1==p2 || flag==-1)
        {
            printf("no\n");
            continue;
        }
        for(int i=1;i<=p1+p2+N;i++)
        {
            if(i<=p1+p2)
            {
                s[fi(i)]++;
                rs[fi(i)].push_back(i);
            }
            else
            {
                s2[fi(i)]++;
                rs2[fi(i)].push_back(i);
            }
        }
        for(int i=1;i<=peo;i++)
        {
            if(s[i]>0 || s2[i]>0)
            {
            //    printf("%d %d %d\n",i,s[i], s2[i]);
                if(s[i]>s2[i])
                {
                    p1-=s2[i];
                    w[cnt]=s[i]-s2[i];
                    fg[cnt]=2;
                }
                else
                {
                    p1-=s[i];
                    w[cnt]=s2[i]-s[i];
                    fg[cnt]=1;
                }
                th[cnt++]=i;
            }
        }
        for(int i=1;i<cnt;i++)
        {
            for(int j=0;j<=p1;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(w[i]<=j)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+w[i]);
                }
            }
        }
        if(dp[cnt-1][p1]==p1)
        {
            int tmp=p1;
            for(int k=cnt-1;k>=1;k--)
            {
                if(dp[k][tmp]== dp[k-1][tmp-w[k]]+w[k])
                {
                    cout<<"used high"<<k<<endl;
                    tmp-=w[k];
                    if(fg[k]==2)
                        for(int i=0;i<rs[th[k]].size();i++)
                        {
                            ans[rs[th[k]][i]]++;
                        }
                    else
                        for(int i=0;i<rs2[th[k]].size();i++)
                        {
                            cout<<rs2[th[k]][i]%600<<endl;
                            ans[rs2[th[k]][i]%600]++;
                        }
                }
                else
                {
                    cout<<"not used high"<<k<<endl;
                    if(fg[k]==1)
                        for(int i=0;i<rs[th[k]].size();i++)
                        {
                            ans[rs[th[k]][i]]++;
                        }
                    else
                        for(int i=0;i<rs2[th[k]].size();i++)
                        {
                            cout<<rs2[th[k]][i]%600<<endl;
                            ans[rs2[th[k]][i]%600]++;
                        }

                }
            }
            for(int i=1;i<=peo;i++)
            {
                if(ans[i]>0)
                    printf("%d\n",i);
            }
            printf("end\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}


