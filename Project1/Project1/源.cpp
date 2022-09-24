#include<stdio.h>
#include<assert.h>
char* my_strncpy(char* str1, const char* str2, size_t n)
{
	assert(str1);
	assert(str2);
	int i = 0;
	char* s = str1;
	while (i < n && *str2 != '\0')
	{
		*str1++ = *str2++;
		i++;
	}
	if (i >= n)
	{
		*str1++ = '\0';
	}
	if (*str2 == '\0')
	{
		for (int j = i; j < n; j++)
		{
			*str1++ = '\0';
		}
	}
	return s;
}
int main()
{
	char str[20] = "-12390.3";
	char str1[9] = "ios";
	printf("%s", my_strncpy(str1, str, 2));
	return 0;
}