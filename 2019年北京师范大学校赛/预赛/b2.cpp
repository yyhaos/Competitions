
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
	int t,k,i,j,liu,ci;
	char c;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		i=liu=0;
		scanf("%d ",&k);
		scanf("%c",&c);
		//n[i++]=c;
		while(c!='\n' )
		{
			ci=(int)c-'0';//�����ַ�c����ֱ��ת�������֣�Ҫ��ƫ����'0'
			liu=(10*liu+ci)%k;
			scanf("%c",&c);
		}
		if(liu==0)
            printf("Yes\n");//Ҫ�������
		else
            printf("No\n");//ͬ��

	}
}
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t,k,i,j,liu,ci;
	char c;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		i=liu=0;
		scanf("%d ",&k);
		scanf("%c",&c);
		//n[i++]=c;
		while(c!='\n')
		{
			ci=(int)c-'0';//�����ַ�c����ֱ��ת�������֣�Ҫ��ƫ����'0'
			liu=(10*liu+ci)%k;
			scanf("%c",&c);
		}
		if(liu==0)
		printf("Yes\n");//Ҫ�������
		else
		printf("No\n");//Ҫ�������

	}
}
