#include<stdio.h>
int count9(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		/*����ⷨ��
		û�а���9��ʮλ��
		if ((i + 1) % 10 == 0)
		{
			count++;
		}*/
		//��ȷ�ⷨ
		if (i % 10 == 9)
		{
			count++;
		}
		if (i / 10 == 9)
		{
			count++;
		}
		
	}
	return count;
}
int main()
{
	int count = count9(100);
	printf("%d", count);
}