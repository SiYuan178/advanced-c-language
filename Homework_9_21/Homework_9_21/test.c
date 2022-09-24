#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
int atoi(const char* str)
{
	int sum = 0;
	int k = 0;
	if (str[0] != '-')
	{
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				k++;
			}
			else
			{
				break;
			}
		}
		for (int i = 0; i < k; i++)
		{
			
			sum = sum * 10 + (str[i]-48);
			
		}

	}
	else
	{
		for (int i = 1; i < strlen(str); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				k++;
			}
			else
			{
				break;
			}
		}
		for (int i = 1; i <= k; i++)
		{
			sum = sum * 10 + (str[i] - 48);
		}
		sum = -sum;
	}
	return sum;
}
char* my_strncat(char* str1, const char* str2, size_t n)
{
	assert(str1);
	assert(str2);
	int i = 0;
	char* p = str1;
	while (*str1!='\0')
	{
		str1++;
		
	}
	while (i < n && *str2!='\0')
	{
		*str1++= *str2++;
		i++;
	}
	if (*str2 == '0')
	{
		for (int j = i; j < n; j++)
		{
			*str1++ = '\0';
		}
	}
	if (i >= n) 
	{
	*str1++ = '\0';
	}
	
	return p;
}
char* my_strncpy(char* str1, const char* str2, size_t n)
{
	assert(str1);
	assert(str2);
	int i = 0;
	char* s =str1;
	while (i < n && *str2!='\0')
	{
		*str1++ = *str2++;
		i++;
	}
	if (i >= n)
	{
		*str1++ = '\0';
	}
	if (*str2=='\0')
	{
		for (int j = i; j < n; j++)
		{
			*str1++ = '\0';
		}
	}
	return s;
}
int appears_once(int num[], int n)
{
	
	for (int i = 0; i < n ; i++)
	{
		int flag = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (num[i] == num[j])
			{
				flag = 1;
			}
		}
		if (flag==0)
		{
			printf("%d %d\n", num[i],flag);
		}
	}
	return 0;
}
int main()
{
	int num[10] = { 1,2,3,2,3,5,5,6,6,7 };
	 appears_once(num, 10);
	
	return 0;
}