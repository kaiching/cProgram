// thread.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>

DWORD WINAPI funA(LPVOID lp)
{
	int i = 1;
	int sum = 0;

	for (i=1; i<100; i++)
	{
		sum +=i;
	}

	printf("ID��Ϊ%d���߳�֮��Ϊ��%d\n", GetCurrentThreadId(), sum);

	return 0;
}

DWORD WINAPI funB(LPVOID lp)
{
	int i = 1;
	int sum = 0;

	for (i=1; i<500; i++)
	{
		sum +=i;
	}

	printf("ID��Ϊ%d���߳�֮��Ϊ��%d\n", GetCurrentThreadId(), sum);

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE a[2];
	DWORD dwT,dwY;
	a[0] = CreateThread(NULL, 0, funA, 0, 0, &dwT);
	a[1] = CreateThread(NULL, 0, funB, 0, 0, &dwY);
	WaitForMultipleObjects(2,a,true,5000);
	CloseHandle(a);
	return 0;
}

