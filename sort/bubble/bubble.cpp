// bubble.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "assert.h"
#include <iostream>
using namespace std;

void bubble_sort(int *a, int len)
{
	int i, j, t;
	//����һ��ȷ��һ��ѭ���ҳ���Сֵ�ŵ���Ӧλ��
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

