#include<bits/stdc++.h>
using namespace std;

/*
̰��
Ԥ����ÿ��������ֱ���1~n�κ����Сֵ
Ȼ��ÿ�θĶ����൱�ڼ���һ���и�
��ÿ�����и�Ͷ�ѡӰ�������Ǹ��ͺ���
������кü����Ļ��������ѡһ���ͺã�

Ӱ����� ����˵ ��֮ǰ������-��֮������������������
*/
char str[500];
int a[500][500];
int nu[500];
int k[5050];
int main ()
{
    memset(a,0,sizeof(a));
    memset(nu,0,sizeof(nu));
    memset(k,0,sizeof(k));
    memset(str,0,sizeof(str));
    k[0]=0;
    for(int i=1;i<=500;i++)
    {
        k[i]=i;
    }
    for(int i=2;i<=500;i++)
    {
        k[i]=k[i-1]+k[i];//�˶�����Ϊi������
    }
    int n,sk;
    scanf("%d%d",&n,&sk);
    scanf("%s",str);
    int lian=0;
    int cnt=0;
    for(int i=0;str[i];i++)
    {
        if(str[i]=='1')
        {
            lian++;
        }
        else if(lian>0)
        {
            a[cnt++][0]=lian;
            lian=0;
        }
    }
    if(lian>0)
    {
        a[cnt++][0]=lian;
    }
    for(int i=0;i<cnt;i++)
    {
        int chu=a[i][0];
        for(int j=1;j<=chu;j++)//�г�j+1��
        {
            a[i][j]=0;
            int th=1;
            int tc=chu-j;//����j�ζ���
            int cha=tc/(j+1);
            if(cha==0)
            {
                a[i][j]=tc;
                continue;
            }
            int num_cha_1=tc-cha*(j+1);
            int num_cha=j+1-num_cha_1;
            a[i][j]+=num_cha*k[cha];
            a[i][j]+=num_cha_1*k[cha+1];//Ԥ����ע��ֿ�ķ�������ÿ�����С����ࡣ
        }
    }
    for(int i=0;i<cnt;i++)
    {
        a[i][0]=k[a[i][0]];
    }
    int tk=0;
    for(int i=0;i<cnt;i++)
        tk+=a[i][0];
    int tmp=-1,ti;
    memset(nu,0,sizeof(nu));
    for(int an=0;an<=450;an++)
    {
        tmp=0;
        if(tk<=sk)
        {
            printf("%d",an);
            return 0;
        }
        for(int i=0;i<cnt;i++)
        {
            if(tmp<a[i][nu[i]]-a[i][nu[i]+1])//̰��
            {
                tmp=a[i][nu[i]]-a[i][nu[i]+1];
                ti=i;
            }
        }
        nu[ti]++;
        tk-=tmp;
    }

    return 0;
}
