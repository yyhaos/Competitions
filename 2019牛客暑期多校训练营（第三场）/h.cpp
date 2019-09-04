#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5;
struct Point{
    LL x,y;
    Point(LL _x,LL _y):x(_x),y(_y){}
    Point(){}
}po[maxn];
Point sw,ne;
inline LL cross(Point a,Point b,Point A,Point B)
{
    return (b.x-a.x)*(B.y-A.y)-(b.y-a.y)*(B.x-A.x);
}

bool IsLeft(Point a,Point b,Point p)
{
    return cross(a,b,a,p)>0;
}

bool cmp(Point a,Point b)
{
    return IsLeft(sw,a,b) ;
}

void solve(int n)
{

    sw.x= - 1000000;
    sw.y=LL((1.0*rand()/RAND_MAX)*2000000)-1000000LL;
//cout<<RAND_MAX<<endl;
    sort(po,po+n,cmp);
//    cout<<n<<" "<<sw.x<<" "<<sw.y<<endl;

//    for(int i=0;i<n;i++)
//    {
//        cout<<po[i].x<<" "<<po[i].y<<endl;
//    }
    ne.x=po[n/2].x+(po[n/2].x-sw.x)+1;
    ne.y=po[n/2].y+(po[n/2].y-sw.y);
}

bool check(int n)
{
    int l=0,r=0;
    for(int i=0;i<n;i++){
        LL tmp=cross(sw,ne,sw,po[i]);
        if(tmp>0) l++;
        else if(tmp<0) r++;
    }
    return (l==n/2)&&(r==n/2);
}


int main(void)
{ srand(time(NULL));
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int _;scanf("%d",&_);
    while(_--){
        int n;scanf("%d",&n);


        for(int i=0;i<n;i++){
            scanf("%lld%lld",&po[i].x,&po[i].y);
        }
        while(1){
    //            cout<<n<<endl;
            solve(n);

            if(check(n)){
                printf("%lld %lld %lld %lld\n",sw.x,sw.y,ne.x,ne.y);
                break;
            }
        }

    }
}
