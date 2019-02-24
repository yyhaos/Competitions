
#include <iostream>
using namespace std;
char Map[1005][1005];

int main()
{
    std::ios::sync_with_stdio(false);//加速
    int N,M,K;//方格图的行数，列数和起点到终点的最短距离
    cin >> N >> M >> K;
    int startx=1,starty=1,endx=1,endy=1;//先假设起始点和终止点的坐标都为（1，1）

    //先把整个方格图迷宫全部放上'x'障碍
    int i,j;
    for(i=1;i<=N;++i)
        for(j=1;j<=M;++j)
            Map[i][j]='x';

    Map[endx][endy]='.';//把终止点（1，1）放上'.'路，因为终止点一定是路的位置

    if( N==1 )//方格图迷宫只有1行的情况
        for(j=2;j<=K+1;++j)//只能横着走
        {
            Map[1][j]='.';//把障碍'x'变为路'.'
            endy++;//终止点所处的列数加1
        }
    else if( M==1 )//方格图迷宫只有1列的情况
        for(i=2;i<=K+1;++i)//只能竖着走
        {
            Map[i][1]='.';//把障碍'x'变为路'.'
            endx++;//终止点所处的行数加1
        }
    else if( N==2 )//方格图迷宫只有2行的情况
        while(K)//直走换边法
        {
            if(K) endx++,K--,Map[endx][endy]='.';
            if(K) endy++,K--,Map[endx][endy]='.';
            if(K) endy++,K--,Map[endx][endy]='.';
            if(K) endx--,K--,Map[endx][endy]='.';
            if(K) endy++,K--,Map[endx][endy]='.';
            if(K) endy++,K--,Map[endx][endy]='.';
        }
    else if( M==2 )//方格图迷宫只有2列的情况
        while(K)//直走换边法
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
                while( endy<M && K ) endy++,K--,Map[endx][endy]='.';//绕圈
                if(K) endx++,K--,Map[endx][endy]='.';//直走换边法
                if(K) endx++,K--,Map[endx][endy]='.';//直走换边法
                while( endy>1 && K ) endy--,K--,Map[endx][endy]='.';//绕圈
                if(K) endx++,K--,Map[endx][endy]='.';//直走换边法
                if(K) endx++,K--,Map[endx][endy]='.';//直走换边法
            }
        }
        else
        {
            while(K)
            {
                while( endx<N && K ) endx++,K--,Map[endx][endy]='.';//绕圈
                if(K) endy++,K--,Map[endx][endy]='.';//直走换边法
                if(K) endy++,K--,Map[endx][endy]='.';//直走换边法
                while( endx>1 && K ) endx--,K--,Map[endx][endy]='.';//绕圈
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
