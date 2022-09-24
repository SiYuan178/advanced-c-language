#include<stdio.h>
void find_once(int num[],int n,int* p1,int* p2)
{
	int dog=0;
	int pos=0;
	for(int i=0;i<n;i++)
	{
		dog^=num[i];
	}
	for(pos=0;pos<32;pos++ )
	{
		if(((dog>>pos)&1)==1)
		{
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(((num[i]>>pos)&1)==1)
		{
			*p1^=num[i];
		}
		else
		{
			*p2^=num[i];
		}
	}
}
int main() 
{
	int num[6]={1,3,4,3,4,5};
	int p1=0;
	int p2=0;
	find_once(num,6,&p1,&p2);
	printf("单身狗1：%d\n单身狗2：%d",p1,p2);
	return 0;
}
