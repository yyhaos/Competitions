//2018-2019 ACM-ICPC, Asia Jiaozuo Regional Contest
//B. Ultraman vs. Aodzilla and Bodzilla

//������Ǹ�AB�������� �и��Ե�Ѫ���͹�������Ȼ����ȥɱ�������� �����i�ι����Ĺ�������i����һ��ֻ�ܹ���һ������
//����ֻҪ���žͻṥ���㣬ÿһ�ι����ȹ���
//��һ�ֹ������� ����֤���ܵ����˺�����С ���ڱ�֤�ܵ��˺�����С������� ����ֵ�����С�Ĺ������С�
//����յ�����С�˺� �͹������� ��AB�ַ�������ʾ ��i���ַ���ʾ��i�ι�����Ŀ��

/*
����
CASE
HP_A HP_B AD_A AD_B

Input
2
5 15 5 25
5 15 25 5

Output
155 BBBBBA
105 AAABBB

*/

//̰�ĵ�˼�� ��һ������նɱһ������ ��ȥɱ��һ�����planA��planC��������˼��
//���� ��նɱ��һ�������ʱ�� �������˺����˷ѡ������ڿ���һ���������һ��ʱ����һ������ֻ��1��Ѫ����������Ĺ������Ѿ���1000�ˣ����˷���999���˺���
//���ԣ� ��Ҫ��ɱ��һ������Ķ����˺��ȸ��ڶ������ȥ��������Ѫ����planB �� planC
//�ѵ����ڣ�    1.�����˺��ȸ��ڶ�������� �ȿ��ܼ���ɱ�����Ĵ�����Ҳ���ܼ��ٲ��ˡ�
//              2.�����ֵ�����С��Լ����һЩ�����ͬ ���ǹ���˳��ͬ�Ĳ�����Ҫ�Ƚ�
//              3.�������ﶼ������Ϊ��һ��ɱ���Ķ��󣬵��Ƕ��������ֵ�����С��Լ���������кܴ���졣
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll da(ll start,ll day)  //�����start�ε�start+day-1�α����� ��day���� ���˺���
{
    return (2*start+day-1)*day/2LL;
}
ll fi(ll tar,ll start)  //�����start�ο�ʼ ����k���У�Ҫ��tar�˺�ʱ������Ҫ�Ĵ���k_min ���ַ�
{
    ll mid,l=0,r=100000000;
    while(r>l)
    {
        mid=(r+l)/2;
        ll D=da(start,mid);
        if(D==tar)
        {
            if(mid>0)
                return mid;
            else
                return 0;
        }
        else if(D>tar)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    ll ans;
    for(ans=l-3 ; ans<= r+3;ans++)
    {
        if(ans<0)
            continue;
        if( da(start,ans)>=tar)
            return ans;
    }
    if(ans>r+3)
        cout<<"error ans>r+3\n"<<endl;
    return -1;
}
ll planA(string &ans,const ll& pa,const ll& pb,const ll& aa,const ll& ab)
{
    /*
        �ȸ�A ֱ��A������תB
    */
    ll damagehe=0;
    ll adie=fi(pa,1); //A������������ ���������Ҫ��֤ a����һ��ʱ����
   // ll ayu = da(1,adie)-pa;//ɱA��������˺�
        ans = "";
        for(int i=1;i<=adie;i++)
        {
            ans+="A";
        }
        damagehe+=adie*(aa+ab);
        ll bdie=fi(pb,adie+1);
        for(int i=1;i<=bdie;i++)
        {
            ans+="B";
        }
        damagehe+=bdie*ab;
     //   ans+="\0";
        return damagehe;

}
ll planB(string &ans,const ll& pa,const ll& pb,const ll& aa,const ll& ab)
{
    /*
    �ȸ�A �Ѷ�����˺�ת�Ƹ�B
    */
    ll damagehe=0;
    ll adie=fi(pa,1); //A������������ ���������Ҫ��֤ a����һ��ʱ����
    ll ayu = da(1,adie)-pa;//ɱA��������˺�
    ll trans=min(pb,ayu);   //�ȸ�B���˺�
    if(trans==pb)   //A����������˺�����b��Ѫ��-->�����ȸ�B ����Bǰ����A ��planD ����ֱ��return maxn
    {
        return 99999999999999999999LL;
    }
    else    //A����������˺���B��Ѫ��С ������ ֱ�Ӱ�trans��һ����ȥ��B�ͺ��ˣ���Ϊ��������������transǰһ����B�ͻ��ֵ���� ���ߴ������trans���˺�
    {
        ans="";
        for(int i=1;i<=trans-1;i++)
        {
            ans+="A";
        }
        ans+="B";
        for(int i=trans+1;i<=adie;i++)
        {
            ans+="A";
        }
        damagehe+=adie*(ab+aa);
        ll bdie=fi(pb-trans,adie+1);
        for(int i=1;i<=bdie;i++)
        {
            ans+="B";
        }
        damagehe+=bdie*ab;
     //   ans+="\0";
        return damagehe;
    }
}

ll planC(string &ans,const ll& pa,const ll& pb,const ll& aa,const ll& ab)
{
    /*
    �ȸ�B ֱ��B�� �ٸ�A
    */
    ll bdie=fi(pb,1);//b������������� ���������Ҫ��֤ b����һ��ʱ����
    ll adie=fi(pa,bdie+1);
    ans="";
    for(int i=1;i<=bdie;i++)
    {
        ans+="B";
    }
    for(int i=1;i<=adie;i++)
    {
        ans+="A";
    }
    ll Da=0;
    Da+=bdie*(aa+ab);
    Da+=adie*aa;
  //  ans+="\0";
    return Da;
}

ll planD(string &ans,const ll& pa,const ll& pb,const ll& aa,const ll& ab)
{
    /*
    �ȸ�B ��B������˺���A
    */
    ll bdie=fi(pb,1);   //b������������� ���������Ҫ��֤ b����һ��ʱ����
    //ll adie=fi(pa,bdie+1);
    ans="";
    ll byu=da(1,bdie)-pb;
    if(byu==0)
        return 999999999999900000LL;//����planC
    else
    {
        ll trans=min(byu,pa);
        if(trans==pa)  //A��B��������˺�����   //����planA
        {
            return 9999999999999999999999LL;
        }
        else//A���� ���ԣ�1. ����ȡǰk����ΪA 2. ��֤B������� ��������a������ʱ�� ���� a������ʱ�������ǰһ�졣��pa>byu>bdie��
        {
            ll adie1=fi(pa,bdie+1);//������ A ����������
            ll adie2=fi(pa-byu,bdie+1);//���ٺ� A ����������  // adie1 >= adie2 >= adie1-1 ����byu>bdie
            ll takedamage=da(bdie+1,adie2);//��������С��ʱ�� ���ܵ��˺�
            ll least=pa-takedamage;//��֤��������С��ʱ��������Ҫ�ȳ������˺� ���� ��least<=0 ��˵��A������ʱ����ٲ��� ��adie1==adie2��

            ll geia=fi(byu+1,1)-1;//�����ǰgeia�������  �ٶ�ͳ�����byu��������b�͸������˺��� ����
            ll dagei=da(1,geia);//��ǰgeia����˺������

            if(dagei>=least) //ǰgeia������������->����a������ʱ�� ���� a������ʱ�䲻��Ҫ���٣�least<0��
            {
                for(int i=1;i<=geia;i++)
                {
                    ans+="A";
                }
                for(int i=geia+1;i<=bdie;i++)
                {
                    ans+="B";
                }
                ll Da=0;
                Da+=bdie*(aa+ab);
                for(int i=1;i<=adie2;i++)
                {
                    ans+="A";
                }
               // ans+="\0";
                Da+=adie2*aa;
                return Da;
            }
            else    //�겻������ ����˵least>0����Ҫ�����˺��������ǰ�geia��һ����������õ���һ�졣����ʱû�뵽������� ���� ��һ�ϴ�ͳ����뵽�� ����
            {
                ll cha=least-dagei;
                for(int i=1;i<geia;i++)
                {
                    ans+="A";
                }
                for(int i=geia;i<geia+cha;i++)
                {
                    ans+="B";
                }
                ans+="A";   //��geia�� ���� �����õ���һ�� //���ᳬ��bdie ����Ҫôleast<=0������� Ҫôtrans>paҲ��������������
                for(int i=geia+cha+1;i<=bdie;i++)
                {
                    ans+="B";
                }
                for(int i=1;i<=adie2;i++)
                {
                    ans+="A";
                }
                //ans+="\0";
                ll Da=0;
                Da+=bdie*(aa+ab);
                Da+=adie2*aa;
                return Da;
            }
        }
    }
}


int main ()
{

    //cout<<fi(3,1);
    ll pa,pb,aa,ab;
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&pa,&pb,&aa,&ab);
        string a[7];
        ll sa[6];
        sa[1]=planA(a[1],pa,pb,aa,ab);
        sa[2]=planB(a[2],pa,pb,aa,ab);
        sa[3]=planC(a[3],pa,pb,aa,ab);
        sa[4]=planD(a[4],pa,pb,aa,ab);
        ll minn=99999999999999999LL;
//        for(int i=1;i<=4;i++)
//        {
//          //  cout<<sa[i]<<" "<<a[i]<<endl;
//            //minn=min(minn,sa[i]);
//        }
        for(int i=1;i<=4;i++)
        {
            minn=min(minn,sa[i]);
        }
        ll th=-1;
        for(int i=1;i<=4;i++)
        {
            if(sa[i]==minn)
            {
                if(th==-1)
                {
                    th=i;
                }
                else
                {
                    if(a[th]>a[i])
                        th=i;
                }
            }
        }
        printf("%lld ",sa[th]); //%s ����
        cout<<a[th];
        printf("\n");
    }
    return 0;
}
