// list.cpp : 定义控制台应用程序的入口点。
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

	printf("请输入你要生成的链表长度：");
	scanf("%d",&len);

	pNode pHead = (pNode)malloc(sizeof(Node));//创建一个有效的头指针
	assert(NULL!=pHead);

	pNode pNail = pHead; //建立一个空链表，头节点为空，这样赋值操作不会改变pHead的值
	pNail->pNext = NULL;  //初始化

	for (int i=0; i<len; i++)
	{
		pNode pNew = (pNode)malloc(sizeof(Node));  //为每个节点分配内存
		assert(NULL!=pNew);

		printf("第%d个节点的值是：",i+1);
		scanf("%d",&val);
		
		pNew->data = val;
		pNail->pNext = pNew;
		pNew->pNext = NULL;  //初始化
		pNail = pNew;
	}

	return pHead;
}
void TraversList(pNode pHead)
{
	pNode p = pHead->pNext;  //判断是否是空链表
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
	/* 冒泡法一                                                                     */
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
	/* 冒泡法二                                                                     */
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
/* 在pHead所指向链表的第pos个节点的前面插入一个新的节点，该节点
的值为val，并且pos的值从1开始*/
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
	pHead = CreateList();  //创建链表
	TraversList(pHead); //链表遍历输出 

// 	if (EmptyList(pHead))
// 	{
// 		printf("链表为空！\n");
// 	}
// 	else
// 	{
// 		printf("链表不为空！\n");
// 	}

	int len = LengthList(pHead); //链表长度
	printf("链表的长度为：%d\n", len);

// 	SortList(pHead); //链表冒泡法排序
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

