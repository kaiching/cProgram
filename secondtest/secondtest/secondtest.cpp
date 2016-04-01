// secondtest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

struct node
{
	int a;
	int b;
	int c;
};


int strcmp(char *src, char *dst) //比较两个字符串是否相等
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

int func(char *str)  //判断一个字符串是否是回文
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
char *strcat(char *src, char *dst) //把src所指字符串添加到dst结尾处
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

char *invstr(char *src)  //字符串反转
{
	char *p = src;
	char t;
	int len = strlen(p);
	for (int i=0; i<len/2; i++)
	{
		t = p[i];
		p[i] = p[len-1-i];
		p[len-1-i] = t;
	}
	return src;
}

int foo ( int x , int n)
{
	int val;
	val =1;
	if (n>0)
	{
		if (n%2 == 1) 
		val = val *x;

		val = val * foo(x*x , n/2);
	}
	return val;
}

void foo( int b[][3])
{
	++ b;
	b[1][1] =9;
}

void e(int n)
{
	if(n>0)
	{
		e(--n);
		printf("%d" , n);
		e(--n);
	}
}

void f( char **p )
{
	char* t;
	t= (p+= sizeof(int))[-1];
	printf( "%s" , t);
}

int main()
{
// 	char a[] = "123321";
// 	int c = func(a);
// 	printf("%d\n", c);

// 	char a[] = "123";
// 	char b[256] = "67809";
// 	char *s = strcat(a,b);
// 	printf(s);

// 	char a[] = "helloworld";
// 	char *s = invstr(a);
// 	printf(s);

// 	struct node s = {3, 5, 6};
// 	struct node *pt =&s;
// 	printf("%d", *((int*)pt+1));

// 	int val = foo(6,5);
// 	printf("%d", val

// 	int a [3][3]= { { 1,2,3} , { 4,5,6},{7,8,9}};
// 	foo(a);
// 	printf("%d" , a[2][1]);

// 	int i=3;
// 	int j=(++i)+(++i);

// 	int a;
// 	a=3;
// 	e(a);

	char * argv[] = { "ab" ,"cd" , "ef" ,"gh", "ij" ,"kl" };
	f( argv );

 	return 0;
}

