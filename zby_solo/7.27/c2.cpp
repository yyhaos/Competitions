#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll encode[30][10];
void getencode()
{
    for(int i=0;i<=26;i++)
    {
        ll tn=4;
        ll tmp=i;
        while(tmp)
        {
            if(tmp%2)
            {
                encode[i][tn--]=1;
            }
            else
                encode[i][tn--]=0;
            tmp/=2;
        }
        while(tn>=0)
        {
            encode[i][tn--]=0;
        }
    }
}

ll tr(char x)//�ַ�ת���encode������±�
{
    if(x==' ')
        return 0;
    return x-'A'+1;
}
ll zhuanyi[1000005];

    ll r,c,len;
ll ans[105][105];
void dfs(ll tx,ll ty,ll tn,ll ti,string fx)
//��ǰλ�ã�tx,ty��. ��ǰ��Ӧ���룺encode[zhuanyi[tn]][ti] , ��ǰ���� fx
{
//    cout<<tx<<" "<<ty<<":"<<tn<<" "<<ti<<" "<<fx<<endl;
    ll bianma ;//��ǰ����
    if(tn<len)
        bianma=encode[zhuanyi[tn]][ti];
    else
        bianma=0;

    ti++;
    if(ti>=5)
        tn++,ti=0;

    ans[tx][ty]=bianma+1;//+1 ������������

    if(fx=="you")//����Ϊ��
    {
        if(ty+1<c && ans[tx][ty+1]==0)//ֱ��
            dfs(tx,ty+1,tn,ti,"you");
        else if(tx+1<r && ans[tx+1][ty]==0)//��ת��
            dfs(tx+1,ty,tn,ti,"xia");
    }
    if(fx=="zuo")//����Ϊ��
    {
        if(ty-1>=0 && ans[tx][ty-1]==0)//ֱ��
            dfs(tx,ty-1,tn,ti,"zuo");
        else if(tx-1>=0 && ans[tx-1][ty]==0)//��ת��
            dfs(tx-1,ty,tn,ti,"shang");
    }
    if(fx=="shang")//����Ϊ��
    {
        if(tx-1>=0 && ans[tx-1][ty]==0)//��ת��
            dfs(tx-1,ty,tn,ti,"shang");
        else if(ty+1<c && ans[tx][ty+1]==0)//ֱ��
            dfs(tx,ty+1,tn,ti,"you");
    }
    if(fx=="xia")//����Ϊ��
    {
        if(tx+1<r && ans[tx+1][ty]==0)//��ת��
            dfs(tx+1,ty,tn,ti,"xia");
        else if(ty-1>=0 && ans[tx][ty-1]==0)//ֱ��
            dfs(tx,ty-1,tn,ti,"zuo");
    }
}

int main ()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    #endif // yyhaos
    getencode();
    memset(ans,0,sizeof(ans));
//    for(int i=0;i<=26;i++)
//    {
//        cout<<"i="<<i<<":";
//        for(int j=0;j<5;j++)
//        {
//            cout<<encode[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    string str;
    cin>>r>>c;
    getline(cin,str);

len=0;
    for(int i=1;str[i];i++)
    {
        zhuanyi[len]=tr(str[i]);
        len++;
    }

    //cout<<str<<endl;
//    for(int i=0;i<len;i++)
//    {
//        cout<<str[i+1]<<":"<<zhuanyi[i]<<endl;
//    }

    dfs(0,0,0,0,"you");

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<ans[i][j]-1;
        }
//        cout<<endl;
    }



    return 0;
}
