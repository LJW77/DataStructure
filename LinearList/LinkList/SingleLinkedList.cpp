#include<stdio.h>	
#include<stdlib.h>
#include"SingleLinkedList.h"

status initList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if (!L)
		exit(OVERFLOW);
	L->next = NULL;
	return OK;
}

status destroyList(LinkList &L)
{
	LinkList p = L;
	while (p)
	{
		L = L->next;
		free(p);
		p = L;
	}
	return OK;
}

status clearList(LinkList &L)
{
	LinkList p = L->next;
	LinkList q = L;
	while (p)
	{
		L = L->next;
		free(p);
		p = L;
	}
	q->next = NULL;
	return OK;
}

status listEmpty(LinkList L)
{
	if (!L->next)
		return TRUE;
	return FALSE;
}

int listLength(LinkList L)
{
	int length = 0;
	L = L->next;
	while (L)
	{
		++length;
		L = L->next;
	}
	return length;
}

status getElem(LinkList L, int i, ElemType &e)
{
	L = L->next;             //p指向第一个结点
	int j = 0;               //j为计数器
	while (L&&j < i)         //顺指针向后查找，直到p指向第i个元素或p为空
	{
		L = L->next;
		++j;
	}
	if (!L || j > i)         //第i个元素不存在
		return ERROR;
	e = L->data;             //取第i个元素
	return OK;
}

int locateElem(LinkList L, ElemType e)
{
	int index = 1;
	L = L->next;
	while (L)
	{
		if (L->data == e)
			return index;
		++index;
		L = L->next;
	}
	return 0;
}

status priorElem(LinkList L, int cur_e, ElemType &pre_e)
{
	LinkList p = L->next;
	LinkList q = L->next;
	if (cur_e == p->data)
	{
		printf("第一个元素无前驱。\n");
		return ERROR;
	}
	if (locateElem(L, cur_e) == 0)
	{
		printf("该元素不再表中。\n");
		return ERROR;
	}
	p = p->next;
	while (p)
	{
		if (cur_e == p->data)
			pre_e = q->data;
		p = p->next;
		q = q->next;
	}
	return OK;
}

status nextElem(LinkList L, int cur_e, ElemType &next_e)
{
	LinkList p = L->next;
	while (p)
	{
		if (locateElem(L, cur_e) == 0)
		{
			printf("该元素不再表中。\n");
			return ERROR;
		}
		if (p->next == NULL)
		{
			printf("最后一个元素无后继。\n");
			return ERROR;
		}
		if (cur_e == p->data)
			next_e = p->next->data;
		p = p->next;
	}
	return OK;
}

//status listInsert(LinkList &L, int i, ElemType e)
//{
//	if (i<1 || i>listLength(L) + 1)
//		return ERROR;
//	LinkList p = L;
//	L = L->next;
//	while (L)
//	{
//		if (i == locateElem(L, L->data))
//		{
//			LinkList s = (LinkList)malloc(sizeof(LNode));
//			if (!s)
//				exit(OVERFLOW);
//			s->next = p->next;
//			p->next = s;
//			s->data = e;
//			break;
//		}
//		p = p->next;
//		L = L->next;
//	}
//	return OK;
//}

status listInsert(LinkList &L, int i, ElemType e)
{
	LinkList p = L;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//status listDelete(LinkList &L, int i, ElemType &e)
//{
//	LinkList p = L;
//	while (L)
//	{
//		p = p->next;
//		if (i == locateElem(L, L->data))
//		{
//			e = L->data;
//			L->next = L->next->next;
//			free(p);
//		}
//		L = L->next;
//	}
//	return OK;
//}

status listDelete(LinkList &L, int i, ElemType &e)
{
	LinkList p = L;
	int j = 0;
	while (p->next&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)
		return ERROR;
	LinkList q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
}

status createList(LinkList &L, int n)
{
	int i;
	LinkList p;
	for (i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
	return OK;
}

status mergeList(LinkList &La, LinkList &Lb, LinkList &Lc)
{
	LinkList pa = La->next;
	LinkList pb = Lb->next;
	LinkList pc;
	Lc = pc = La;
	while (pa&&pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
	return OK;
}

void listTraverse(LinkList L)
{
	L = L->next;
	while (L)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}