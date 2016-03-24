// select.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "assert.h"
#include <iostream>
using namespace std;

void select_sort(int *a, int len)
{
	int i, j, min, t;
	for (i=0; i<len-1; ++i)
	{
		min = i;
		for (j=i+1; j<len; ++j)
		{
			if (a[min]>a[j])  //每次找出最小值存在a[min]中
			{
				min = j;
			}
		}

		if (min!=i)  //判断最小值的位置和当前的位置是否一样
		{
			t = a[min];
			a[min] = a[i];
			a[i] = t;
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int src[] = {7,3,1,0,4,2};
	select_sort(src,6);
	for (int i=0; i<6; i++)
	{
		printf("%d ",src[i]);
	}
	return 0;
}

