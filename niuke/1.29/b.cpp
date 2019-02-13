#include<bits/stdc++.h>
using namespace std;
int n,m;

int main ()
{
    cin>>n>>m;
    if(n%2==1 && m%2==1)
    {
        cout<<"-1";
        return 0;
    }
    else if(n==1)
    {
        if(m>=3)
        {
            cout<<"-1";
            return 0;
        }
        else
        {
            cout<<"RL";
            return 0;
        }
    }
    else if(m==1)
    {
        if(n==2)
        {
            cout<<"DU";
            return 0;
        }
        else
        {
            cout<<"-1";
            return 0;
        }
    }
    else if(n%2==0)
    {
        for(int i=1;i<n;i++)
            cout<<"D";
        for(int i=1;i<m;i++)
            cout<<"R";
        for(int i=1;i<n/2;i++)
        {
            cout<<"U";
            for(int i=1;i<=m-2;i++)
                cout<<"L";
            cout<<"U";
            for(int i=1;i<=m-2;i++)
            {
                cout<<"R";
            }
        }
        cout<<"U";
        for(int i=1;i<m;i++)
            cout<<"L";
    }
    else
    {
        for(int i=1;i<m;i++)
        {
            cout<<"R";
        }
        for(int i=1;i<n;i++)
            cout<<"D";
        for(int i=1;i<m/2;i++)
          //  cout<<"LULD";
        {
            cout<<"L";
            for(int i=1;i<=n-2;i++)
                cout<<"U";
            cout<<"L";
            for(int i=1;i<=n-2;i++)
                cout<<"D";
        }
        cout<<"L";
        for(int i=1;i<n;i++)
            cout<<"U";
    }
    return 0;
}
