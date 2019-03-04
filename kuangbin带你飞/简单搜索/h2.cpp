
#include<stdio.h>

#include<queue>

#include<map>

#include<string>

#include<string.h>

using namespace std;

#define N 105

const int inf=0x1f1f1f1f;

int a,b,c,flag;

int mark[N][N];

struct node

{

    int x,y,t;

    friend bool operator<(node a,node b)

    {

        return a.t>b.t;

    }

};

void prif(int x,int y)       //�ݹ����·��

{

    if(x==0&&y==0)

        return ;

    if(mark[x][y]>3*N)

    {

        prif(x,mark[x][y]-3*N);

        printf("DROP(2)\n");

    }

    else if(mark[x][y]>2*N)

    {

        prif(mark[x][y]-2*N,y);

        printf("DROP(1)\n");

    }

    else if(mark[x][y]>N)

    {

        int tmp=mark[x][y]-N;

        prif(x+tmp,y-tmp);

        printf("POUR(1,2)\n");

    }

    else if(mark[x][y]>0)

    {

        int tmp=mark[x][y];

        prif(x-tmp,y+tmp);

        printf("POUR(2,1)\n");

    }

    else if(mark[x][y]>-N)

    {

        int tmp=-mark[x][y];

        prif(x-tmp,y);

        printf("FILL(1)\n");

    }

    else if(mark[x][y]<-N)

    {

        int tmp=N+mark[x][y];

        prif(x,y+tmp);

        printf("FILL(2)\n");

    }

}

void bfs()

{

    priority_queue<node>q;

    node cur,next;

    mark[0][0]=inf;  //��״ֻ̬�ܳ���һ�Σ���ֵΪinf��ֹ��������ֵ

    mark[a][0]=-a;

    mark[0][b]=-b-N;

    cur.t=1;

    cur.x=a;

    cur.y=0;

    q.push(cur);

    cur.x=0;

    cur.y=b;

    q.push(cur);

    while(!q.empty())

    {

        cur=q.top();

        q.pop();

        next.t=cur.t+1;

        if(cur.x==c||cur.y==c)

        {

            flag=1;

            printf("%d\n",cur.t);

            prif(cur.x,cur.y);

            return ;

        }

        if(cur.x<a)       //��A��ˮ

        {

            int tmp=a-cur.x;

            next.y=cur.y;

            next.x=a;         //����ˮ��ͷ��ˮ

            if(!mark[next.x][next.y])

            {

                mark[next.x][next.y]=-tmp;

                q.push(next);

            }

            if(cur.y>0)      //����B��ˮ

            {

                int tmp=min(cur.y,a-cur.x);

                next.x=cur.x+tmp;

                next.y=cur.y-tmp;

                if(!mark[next.x][next.y])

                {

                    mark[next.x][next.y]=tmp;

                    q.push(next);

                }

            }

        }

        if(cur.y<b)        //��B��ˮ

        {

            int tmp=b-cur.y;

            next.x=cur.x;

            next.y=b;      //����ˮ��ͷ��ˮ

            if(!mark[next.x][next.y])

            {

                mark[next.x][next.y]=-tmp-N;

                q.push(next);

            }

            if(cur.x>0)      //����A��ˮ

            {

                int tmp=min(cur.x,b-cur.y);

                next.y=cur.y+tmp;

                next.x=cur.x-tmp;

                if(!mark[next.x][next.y])

                {

                    mark[next.x][next.y]=tmp+N;

                    q.push(next);

                }

            }

        }

        if(cur.x>0)     //����ˮ

        {

            int tmp=cur.x;

            next.x=0;

            next.y=cur.y;

            if(!mark[next.x][next.y])

            {

                mark[next.x][next.y]=2*N+tmp;

                q.push(next);

            }

        }

        if(cur.y>0)

        {

            int tmp=cur.y;

            next.y=0;

            next.x=cur.x;

            if(!mark[next.x][next.y])

            {

                mark[next.x][next.y]=3*N+tmp;

                q.push(next);

            }

        }

    }

}

int main()

{

    while(scanf("%d%d%d",&a,&b,&c)!=-1)

    {

        memset(mark,0,sizeof(mark));

        flag=0;

        bfs();

        if(!flag)

            printf("impossible\n");

    }

    return 0;

}
