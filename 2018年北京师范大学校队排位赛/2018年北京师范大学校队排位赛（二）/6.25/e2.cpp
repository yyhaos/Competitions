#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

#define MAX 100

int n;
int weight[MAX][MAX];           //Ȩ��
int lx[MAX],ly[MAX];                //������
bool sx[MAX],sy[MAX];          //��¼Ѱ������·ʱ�㼯x��y��ĵ��Ƿ�������
int match[MAX];                       //match[i]��¼y[i]��x[match[i]]���Ӧ

bool search_path(int u) {          //��x[u]��ƥ��,������̺�������ƥ����һ����
    sx[u]=true;
    for(int v=0; v<n; v++){
        if(!sy[v] &&lx[u]+ly[v] == weight[u][v]){
            sy[v]=true;
            if(match[v]==-1 || search_path(match[v])){
                match[v]=u;
                return true;
            }
        }
    }
    return false;
}

int Kuhn_Munkras(bool max_weight){
    if(!max_weight){ //�������Сƥ�䣬��Ҫ����Ȩȡ��
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                weight[i][j]=-weight[i][j];
    }
    //��ʼ�����꣬lx[i]����Ϊmax(weight[i][j] | j=0,..,n-1 ), ly[i]=0;
    for(int i=0;i<n;i++){
        ly[i]=0;
        lx[i]=-0x7fffffff;
        for(int j=0;j<n;j++)
            if(lx[i]<weight[i][j])
                lx[i]=weight[i][j];
    }

    memset(match,-1,sizeof(match));
    //�����޸Ķ��ֱ꣬���ҵ��걸ƥ�������ƥ��
    for(int u=0;u<n;u++){   //Ϊx���ÿһ������ƥ��
        while(1){
            memset(sx,0,sizeof(sx));
            memset(sy,0,sizeof(sy));
            if(search_path(u))       //x[u]�������ͼ�ҵ���ƥ��,����Ϊ��һ������ƥ��
                break;
            //����������ͼ��û���ҵ�ƥ�䣬���޸Ķ��ֱ꣬���ҵ�ƥ��Ϊֹ
            //�����ҵ��޸Ķ���ʱ������inc, min(lx[i] + ly [i] - weight[i][j],inc);,lx[i]Ϊ�������ĵ㣬ly[i]��δ�������ĵ�,��Ϊ������Ҫ��u��ƥ�䣬����ֻ��Ҫ�޸��ҵĹ������������ĵ㣬�����п��ܶ�u�а����ı�
            int inc=0x7fffffff;
            for(int i=0;i<n;i++)
                if(sx[i])
                    for(int j=0;j<n;j++)
                        if(!sy[j]&&((lx[i] + ly [j] - weight[i][j] )<inc))
                            inc = lx[i] + ly [j] - weight[i][j] ;
            //�ҵ��������޸Ķ��꣬��Ϊsx[i]��sy[j]��Ϊ�棬���Ȼ����lx[i] + ly [j] =weight[i][j]��Ȼ��lx[i]��inc��ly[j]��inc����ı��ʽ������ԭ��lx[i] + ly [j] ��=weight[i][j]��sx[i]��sy[j]���һ��Ϊ�棬lx[i] + ly [j] �ͻᷢ���ı䣬�Ӷ����ϵ�ʽ����Ҳ�ͼ��뵽�����ͼ��
            if(inc==0)  cout<<"fuck!"<<endl;
            for(int i=0;i<n;i++){
                if(sx[i])   //
                    lx[i]-=inc;
                if(sy[i])
                    ly[i]+=inc;
            }
        }

    }
    int sum=0;
    for(int i=0;i<n;i++)
        if(match[i]>=0)
            sum+=weight[match[i]][i];

    if(!max_weight)
        sum=-sum;
    return sum;


}
int main(){
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        weight[i][i]=-10000000;
        for(int j=0;j<i;j++)
        {
            scanf("%d",&weight[i+1][j]);
            weight[j][i+1]=weight[i+1][j]=weight[i+1][j];
        }
    }

    Kuhn_Munkras(1);
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        ans+=weight[i][sx[i]];
    }
    printf("%d\n",ans);
    for(int i=2;i<=n;i++)
    {
        printf("%d\n",sx[i]+1);
    }
    system("pause");
    return 0;
}
