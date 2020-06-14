//Problem Web:
#include<bits/stdc++.h>
#include<ext/rope> //using __gnu_cxx
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
//#define use_t 1

const int of=3001;
inline int gx(int x){
    return x%of;
}
inline int gy(int y){
    return y/of;
}
inline int he(int x,int y){
    return y*of+x;
}
char M[3005][3005];
int fa[3005][3005];

int si[3005*3005+1];

inline int fi(int x ,int y ){
    if( fa[x][y] == he(x,y)) return fa[x][y];
    else return fa[x][y] =  fi( gx(fa[x][y]), gy(fa[x][y]) );
}
inline void un ( int x1,int y1, int x2,int y2){
    if(fi(x1,y1) == fi(x2,y2))
        return ;
    int fx = gx( fi(x1,y1));
    int fy = gy( fi(x1,y1));
    fa[fx][fy]= fa[x2][y2];
    fi(x1,y1);
}

ll t,n,m;

int main ()
{
    memset(si,0,sizeof(si));

#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    int k;
    cin>>n>>m>>k;
    getchar();
    for(int i=0;i<n;i++){
        scanf("%s", M[i]);
    }

    for( int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fa[i][j]=he(i,j);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i<n-1){
                if(M[i][j] != M[i+1][j]){
                    un(i,j,i+1,j);
                }
            }
            if(j<m-1){
                if(M[i][j]!= M[i][j+1])
                    un(i,j,i,j+1);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fi(i,j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            si[fi(i,j)] ++;
        }
    }

//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            printf("(%d,%d)\t",gx(fi(i,j)), gy(fi(i,j)));
//        }
//        printf("\n");
//    }
int x,y;
    while(k--){
        scanf("%d%d",&x,&y);
        x--;
        y--;
        printf("%d\n",si[fi(x,y)]);
    }


#ifdef use_t
}
#endif // use_t
    return 0;
}


