
#include <iostream>
using namespace std;
char Map[1005][1005];

int main()
{
    std::ios::sync_with_stdio(false);//����
    int N,M,K;//����ͼ����������������㵽�յ����̾���
    cin >> N >> M >> K;
    int startx=1,starty=1,endx=1,endy=1;//�ȼ�����ʼ�����ֹ������궼Ϊ��1��1��

    //�Ȱ���������ͼ�Թ�ȫ������'x'�ϰ�
    int i,j;
    for(i=1;i<=N;++i)
        for(j=1;j<=M;++j)
            Map[i][j]='x';

    Map[endx][endy]='.';//����ֹ�㣨1��1������'.'·����Ϊ��ֹ��һ����·��λ��

    if( N==1 )//����ͼ�Թ�ֻ��1�е����
        for(j=2;j<=K+1;++j)//ֻ�ܺ�����
        {
            Map[1][j]='.';//���ϰ�'x'��Ϊ·'.'
            endy++;//��ֹ��������������1
        }
    else if( M==1 )//����ͼ�Թ�ֻ��1�е����
        for(i=2;i<=K+1;++i)//ֻ��������
        {
            Map[i][1]='.';//���ϰ�'x'��Ϊ·'.'
            endx++;//��ֹ��������������1
        }
    else if( N==2 )//����ͼ�Թ�ֻ��2�е����
        while(K)//ֱ�߻��߷�
        {
            if(K) endx++,K--,Map[endx][endy]='.';
            if(K) endy++,K--,Map[endx][endy]='.';
            if(K) endy++,K--,Map[endx][endy]='.';
            if(K) endx--,K--,Map[endx][endy]='.';
            if(K) endy++,K--,Map[endx][endy]='.';
            if(K) endy++,K--,Map[endx][endy]='.';
        }
    else if( M==2 )//����ͼ�Թ�ֻ��2�е����
        while(K)//ֱ�߻��߷�
        {
            if(K) endy++,K--,Map[endx][endy]='.';
            if(K) endx++,K--,Map[endx][endy]='.';
            if(K) endx++,K--,Map[endx][endy]='.';
            if(K) endy--,K--,Map[endx][endy]='.';
            if(K) endx++,K--,Map[endx][endy]='.';
            if(K) endx++,K--,Map[endx][endy]='.';
        }
    else
    {
        if( (N/2)*(M-1)<=(M/2)*(N-1) )
        {
            while(K)
            {
                while( endy<M && K ) endy++,K--,Map[endx][endy]='.';//��Ȧ
                if(K) endx++,K--,Map[endx][endy]='.';//ֱ�߻��߷�
                if(K) endx++,K--,Map[endx][endy]='.';//ֱ�߻��߷�
                while( endy>1 && K ) endy--,K--,Map[endx][endy]='.';//��Ȧ
                if(K) endx++,K--,Map[endx][endy]='.';//ֱ�߻��߷�
                if(K) endx++,K--,Map[endx][endy]='.';//ֱ�߻��߷�
            }
        }
        else
        {
            while(K)
            {
                while( endx<N && K ) endx++,K--,Map[endx][endy]='.';//��Ȧ
                if(K) endy++,K--,Map[endx][endy]='.';//ֱ�߻��߷�
                if(K) endy++,K--,Map[endx][endy]='.';//ֱ�߻��߷�
                while( endx>1 && K ) endx--,K--,Map[endx][endy]='.';//��Ȧ
                if(K) endy++,K--,Map[endx][endy]='.';
                if(K) endy++,K--,Map[endx][endy]='.';
            }
        }
    }

    cout << startx << " " << starty << endl;
    cout << endx << " " << endy << endl;

    for(i=1;i<=N;++i)
    {
        for(j=1;j<=M;++j)
        {
            cout << Map[i][j];
        }
        cout << endl;
    }
}
