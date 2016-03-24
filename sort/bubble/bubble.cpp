// bubble.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "assert.h"
#include <iostream>
using namespace std;

void bubble_sort(int *a, int len)
{
	int i, j, t;
	//方法一，确保一次循环找出最小值放到对应位置
	// 	for (i=0; i<len-1; i++)
	// 	{
	// 		for (j=i+1; j<len; j++)
	// 		{
	// 			if (a[i]>a[j])
	// 			{
	// 				t = a[i];
	// 				a[i] = a[j];
	// 				a[j] = t;
	// 			}
	// 		}
	// 	}

	for (i=0; i<len-1; i++)
	{
		for (j=0; j<len-1-i; j++)
		{
			if (a[j]>a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int src[] = {7,3,1,0,4,2};
	bubble_sort(src,6);
	for (int i=0; i<6; i++)
	{
		printf("%d ",src[i]);
	}
	return 0;
}

