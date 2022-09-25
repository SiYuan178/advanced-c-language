#include<stdio.h>
int count9(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		/*错误解法：
		没有包含9在十位：
		if ((i + 1) % 10 == 0)
		{
			count++;
		}*/
		//正确解法
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