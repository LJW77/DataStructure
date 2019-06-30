#include<stdio.h>
#include<stdlib.h>	
#include"SqLinearList.h"

status initList(SqList *L)
{
	(*L).elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(*L).elem)                    //�洢�ռ����ʧ��
		exit(OVERFLOW);
	(*L).length = 0;                   //�ձ���Ϊ0
	(*L).listsize = LIST_INIT_SIZE;    //��ʼ�洢����
	return OK;
}

status destroyList(SqList *L)
{
	if ((*L).elem)
		free((*L).elem);
	(*L).elem = NULL;
	(*L).length = 0;
	(*L).listsize = 0;
	return OK;
}

status clearList(SqList *L)
{
	int i;
	for (i = 0; i < (*L).length; ++i)
	{
		if (!(*L).elem[i])
			(*L).elem[i] = NULL;
	}
	(*L).length = 0;
	return OK;
}

status listEmpty(SqList L)
{
	if (L.length == 0)
		return OK;
	return ERROR;
}

int listLength(SqList L)
{
	return L.length;
}

status getElem(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i<0 || i>listLength(L) - 1)
		return ERROR;
	*e = L.elem[i];
	return OK;
}

int locateElem(SqList L, ElemType e)
{
	int i = 0;
	ElemType *p = L.elem;
	while (i < L.length && (*p++ != e))
		++i;
	if (i < L.length)
		return i;
	else
		return 0;
}

status priorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{
	int i = locateElem(L, cur_e);
	if (i == 0 || cur_e == L.elem[0])
		return ERROR;
	*pre_e = L.elem[i - 1];
	return OK;
}

status nextElem(SqList L, ElemType cur_e, ElemType *next_e)
{
	int i = locateElem(L, cur_e);
	if (i == 0 || cur_e == L.elem[L.length - 1])
		return ERROR;
	*next_e = L.elem[i + 1];
	return OK;
}

status listInsert(SqList *L, int i, ElemType e)
{
	ElemType *newbase;                   //�»�ַ
	ElemType *q;                         //qΪ����λ��
	ElemType *p;
	if (i<0 || i>(*L).length)            //����λ�ô���
		return ERROR;
	if ((*L).length >= (*L).listsize)    //���Ա������������·���ռ�
	{
		newbase = (ElemType*)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);
		(*L).elem = newbase;
		(*L).listsize += LISTINCREMENT;
	}
	q = &((*L).elem[i]);                 //����λ�ü�֮���Ԫ������
	for (p = &((*L).elem[(*L).length - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;                              //����e
	++(*L).length;                       //����1
	return OK;
}

status listDelete(SqList *L, int i, ElemType *e)
{
	if ((*L).length == 0 || i<0 || i>(*L).length - 1)
		return ERROR;
	ElemType *p, *q;
	p = &((*L).elem[i]);
	*e = *p;
	q = &((*L).elem[(*L).length - 1]);
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--(*L).length;
	return OK;
}

status createList(SqList *L)
{
	initList(L);
	int i, elem;
	for (i = 0; i < 5; ++i)
	{
		scanf_s("%d", &elem);
		listInsert(L, i, elem);
	}
	return OK;
}

void listTraverse(SqList L)
{
	ElemType *p;
	for (p = L.elem; p < L.elem + L.length; ++p)
		printf("%d ", *p);
}

void unionList(SqList *La, SqList Lb)
{
	int La_len = listLength(*La);
	int Lb_Len = listLength(Lb);
	int elem;
	for (int i = 0; i < Lb_Len; ++i)
	{
		getElem(Lb, i, &elem);
		if (!locateElem(*La, elem))
			listInsert(La, i, elem);
	}
}

//void mergeList(SqList La, SqList Lb, SqList &Lc)
//{
//	//��֪���Ա�La��Lb�е�����Ԫ�ذ�ֵ�ǵݼ�����
//	//�鲢La��Lb�õ��µ����Ա�Lc��Lc������Ԫ��Ҳ��ֵ�ǵݼ�����
//	initList(Lc);
//	int La_Len = listLength(La);
//	int Lb_Len = listLength(Lb);
//	int i, j;
//	int k = 0;
//	for (i = 0; i < La_Len; ++i)
//	{
//		for (j = 0; j < Lb_Len; ++j)
//		{
//			if (La.elem[i] > Lb.elem[j])
//			{
//				listInsert(Lc, k++, Lb.elem[j]);
//				break;
//			}
//			else
//			{
//				listInsert(Lc, k++, La.elem[i]);
//				break;
//			} 
//		}
//	}
//	while (i < La_Len)
//		listInsert(Lc, k++, La.elem[i++]);
//	while (j < Lb_Len)
//		listInsert(Lc, k++, Lb.elem[j++]);
//}

void mergeList(SqList La, SqList Lb, SqList *Lc)
{
	initList(Lc);
	int i = 0;
	int j = 0;
	int k = 0;
	int La_Len = listLength(La);
	int Lb_Len = listLength(Lb);
	int La_elem;
	int Lb_elem;
	while (i < La_Len&&j < Lb_Len)//La��Lb���ǿ�
	{
		getElem(La, i, &La_elem);
		getElem(Lb, j, &Lb_elem);
		if (La_elem <= Lb_elem)
		{
			listInsert(Lc, k++, La_elem);
			++i;
		}
		else
		{
			listInsert(Lc, k++, Lb_elem);
			++j;
		}
	}
	while (i < La_Len)
	{
		getElem(La, i++, &La_elem);
		listInsert(Lc, k++, La_elem);
	}
	while (j < Lb_Len)
	{
		getElem(Lb, j++, &Lb_elem);
		listInsert(Lc, k++, Lb_elem);
	}
}