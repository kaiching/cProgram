// secondtest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"


int strcmp(char *src, char *dst) //�Ƚ������ַ����Ƿ����
{
	while (*src==*dst && *src!='\0' && *dst!='\0')
	{
		++src;
		++dst;
	}
	if (*src=='\0' && *dst=='\0')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int func(char *str)  //�ж�һ���ַ����Ƿ��ǻ���
{
	if (NULL == str)
	{
		return -1;
	}
	int len = strlen(str);
	for (int i=0; i<len/2; i++)
	{
		if (str[i]==str[len-1-i])
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
char *strcat(char *src, char *dst) //��src��ָ�ַ�����ӵ�dst��β��
{
	char *cp = dst;
	while (*cp!='\0')
	{
		cp++;
	}
	while (*src!='\0')
	{
		*cp++=*src++;
	}
	*cp = '\0';
	return dst;
}
int _tmain(int argc, _TCHAR* argv[])
{
// 	char a[] = "123321";
// 	int c = func(a);
// 	printf("%d\n", c);
	char a[] = "123";
	char b[256] = "67809";
	char *s = strcat(a,b);
	printf(s);
 	return 0;
}

