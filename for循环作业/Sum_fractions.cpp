#include<stdio.h>
double sum(int n)
{
	//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值，打印出结果
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 != 0)
		{
			sum += 1.0 / i;
		}
		else
		{
			sum -= 1.0 / i;
		}

	}
	return sum;
}
//int main()
//{
//	double count = sum(100);
//	printf("%f", count);
//	return 0;
//}