// select.cpp : �������̨Ӧ�ó������ڵ㡣
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
			if (a[min]>a[j])  //ÿ���ҳ���Сֵ����a[min]��
			{
				min = j;
			}
		}

		if (min!=i)  //�ж���Сֵ��λ�ú͵�ǰ��λ���Ƿ�һ��
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

