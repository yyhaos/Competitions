#include<bits/stdc++.h>
using namespace std;
#define INF 99999999
int NN,k;
const int N=INF;

int tr(int n)
{
    int ans=0;
    while(n>0)
    {
        ans*2;
        if(n&1)
        {
            ans++;
        }
        n/=2;
    }
    return ans;
}
int m,s,t;
int dis[N],vis[N],p[N];

int dp[1110][1110];
void D(int src)  //src��������
{
    for(int i=0; i<m; i++) //��ʼ����㵽���е�ľ���
    {
        dis[i] = dp[src][i];
        vis[i] = 0;
        p[i]=0;
    }
    dis[src] = 0; //���������Ϊ0
    vis[src] = 1; //��� עsrc=0
    for(int i=0; i<=tr(NN); i++)
    {
        int ans = INF,k;
        for(int j=0; j<=tr(NN); j++) // Ѱ��δ�����ʹ��������v0�����
        {
            if(!vis[j] && dis[j] < ans)
            {
                k = j;
                ans = dis[j];
            }
        }
        vis[k] = 1;   //����ѷ���
        if(ans == INF) break; //��ʾʣ�����е㶼��ͨ
        for(int j =0; j<m; j++)  //�ɳڲ�����������㵽����δ���ʵ�ľ���
        {
            if(!vis[j] &&  dis[k] + dp[k][j]<dis[j] )
            {
                dis[j] = dis[k] + dp[k][j];
                p[j]=k;//���ǰ���ڵ�
            }
        }
    }
}

int main ()
{
    for(int i=1;i<=10;i++)
    {
        cout<<tr(i)<<endl;
    }
    int t1,t2;
    cin>>NN>>k;
    for(int i=1;i<=1024;i++)
    {
        for(int j=1;j<=1025;j++)
        {
            dp[i][j]=999999999;
            int x=i-j;
            if(x<0)
                x*=-1;
            if(x&(x-1)==0)
            {
                dp[i][j]=1;
                dp[j][i]=1;
            }
        }
    }

    for(int i=1;i<=k;i++)
    {
        cin>>t1>>t2;
        dp[tr(t1)][tr(t2)]=1;
        dp[tr(t2)][tr(t1)]=1;
    }
    for(int i=0;i<=1024;i++)
    {
        for(int j=i+1;j<=1024;j++)
        {
            dp[j][i]=999999999;
        }
    }
D(0);
    cout<<dis[tr(NN)];
    return 0;
}
