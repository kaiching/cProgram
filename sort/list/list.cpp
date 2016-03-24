// list.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "assert.h"
#include <iostream>
using namespace std;

typedef struct List
{
	int data;
	struct List *pNext;
}Node, *pNode;

pNode CreateList()
{
	int len, val;

	printf("��������Ҫ���ɵ������ȣ�");
	scanf("%d",&len);

	pNode pHead = (pNode)malloc(sizeof(Node));//����һ����Ч��ͷָ��
	assert(NULL!=pHead);

	pNode pNail = pHead; //����һ��������ͷ�ڵ�Ϊ�գ�������ֵ��������ı�pHead��ֵ
	pNail->pNext = NULL;  //��ʼ��

	for (int i=0; i<len; i++)
	{
		pNode pNew = (pNode)malloc(sizeof(Node));  //Ϊÿ���ڵ�����ڴ�
		assert(NULL!=pNew);

		printf("��%d���ڵ��ֵ�ǣ�",i+1);
		scanf("%d",&val);
		
		pNew->data = val;
		pNail->pNext = pNew;
		pNew->pNext = NULL;  //��ʼ��
		pNail = pNew;
	}

	return pHead;
}
void TraversList(pNode pHead)
{
	pNode p = pHead->pNext;  //�ж��Ƿ��ǿ�����
	while(NULL!=p)
	{
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
}

bool EmptyList(pNode pHead)
{
	if (NULL == pHead->pNext)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LengthList(pNode pHead)
{
	int len=0;
	pNode p = pHead->pNext;
	while(p)
	{
		++len;
		p = p->pNext;
	}
	return len;
}

void SortList(pNode pHead)
{
	int i, j, t;
	pNode p, q;
	/************************************************************************/
	/* ð�ݷ�һ                                                                     */
	/************************************************************************/
// 	for (i=0, p=pHead->pNext; i<LengthList(pHead)-1; i++, p=p->pNext)
// 	{
// 		for (j=i+1, q=p->pNext; j<LengthList(pHead); j++, q=q->pNext)
// 		{
// 			if (p->data>q->data)
// 			{
// 				t = p->data;
// 				p->data = q->data;
// 				q->data = t;
// 			}
// 		}
// 	}
	/************************************************************************/
	/* ð�ݷ���                                                                     */
	/************************************************************************/
	for (i=0; i<LengthList(pHead)-1;i++)
	{
		for (j=0, p=pHead->pNext; j<LengthList(pHead)-1-i; j++, p=p->pNext)
		{
			if (p->data>p->pNext->data)
			{
				t = p->data;
				p->data = p->pNext->data;
				p->pNext->data = t;
			}
		}
	}
}

/************************************************************************/
/* ��pHead��ָ������ĵ�pos���ڵ��ǰ�����һ���µĽڵ㣬�ýڵ�
��ֵΪval������pos��ֵ��1��ʼ*/
/************************************************************************/
bool InsertList(pNode pHead, int pos, int val)  
{
	int i=0;
	pNode p = pHead;

	while(NULL!=p && i<pos-1)
	{
		++i;
		p = p->pNext;
	}

	if (NULL==p || i >pos-1)
	{
		return false;
	}

	pNode pNew = (pNode)malloc(sizeof(Node));
	assert(NULL!=pNew);

	pNew->data = val;
	pNew->pNext = p->pNext;
	p->pNext = pNew;

	return true;
}

bool DeleteList(pNode pHead, int pos, int *val)
{
	int i=0;
	pNode p = pHead;

	while(NULL!=p && i<pos-1)
	{
		++i;
		p = p->pNext;
	}

	if (NULL==p->pNext || i >pos-1)
	{
		return false;
	}

	pNode r = p->pNext;
	*val = r->data;
	p->pNext = p->pNext->pNext;
	free(r);
	r = NULL;
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	pNode pHead = NULL;
	pHead = CreateList();  //��������
	TraversList(pHead); //���������� 

// 	if (EmptyList(pHead))
// 	{
// 		printf("����Ϊ�գ�\n");
// 	}
// 	else
// 	{
// 		printf("����Ϊ�գ�\n");
// 	}

	int len = LengthList(pHead); //������
	printf("����ĳ���Ϊ��%d\n", len);

// 	SortList(pHead); //����ð�ݷ�����
// 	TraversList(pHead);

// 	InsertList(pHead,4,8);
// 	TraversList(pHead);
	int val;
	if (DeleteList(pHead,3,&val))
	{
		printf("delete success!\n");
	}
	else
	{
		printf("delete failed!\n");
	}
	TraversList(pHead);
	return 0;
}

