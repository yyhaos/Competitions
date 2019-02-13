#include<bits/stdc++.h>
using namespace std;
char s[200005];
int len;
bool fi(int left,int right,int le,bool chance)
{
    if(chance==false)
    {
        if(left==-1 )
        {
            if(right==len )
                return true;
            else
                return false;
        }
        if(right==len)
        {
            return false;
        }
    }
    if(chance==true)
    {
        if(left==-1 && right==len)
            return true;
        if(left==-1 && right==len-1)
            return true;
        else if(left==0 && right==len)
            return true;
    }
    if(s[left]==s[right])
    {
        if(chance == false)
            return fi(left-1,right+1,le,false);
        else
            return fi(left-1,right+1,le,true) || fi(left,right+1,le,false) || fi(left-1,right,le,false);
    }
    if(s[left]!=s[right])
    {
        if(chance == false)
            return false;
        else
        {
            if(fi(left-1,right,le,false) )
                return true;
            return
                fi(left,right+1,le,false);
        }
    }
    return false;
}
int main ()
{
    cin>>s;
    len=strlen(s);
    bool ans;
    if(len<=2)
        ans = true;
    else if(len==3)
    {
        ans= s[0]==s[2] || s[0]==s[1] || s[1]==s[2];
    }
    else if(len%2==1)
    {
        int mid=len/2;
        ans=fi(mid,mid,1,true);
    }
    else
    {
        int mid=len/2;
        ans=fi(mid,mid,1,true) || fi(mid-1,mid-1,1,true) || fi(mid-1,mid,1,true);
    }
    if(ans)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
