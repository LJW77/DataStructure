#include<stdio.h>
#include<stdlib.h>	
#include"LinkStack.h"

Status initStack(LinkStack &s)    
{
	//����һ����ջ
	s.top = NULL;
	s.count = 0;
	return OK;
}

Status destroyStack(LinkStack &s)
{
	//����ջ
	LinkStackPtr p = s.top;
	while (p)
	{
		s.top = s.top->next;
		free(p);
		p = s.top;
	}
	return OK;
}

Status clearStack(LinkStack &s)
{
	//��ջ����Ϊ��
	LinkStackPtr p = s.top;
	while (p)
	{
		s.top = s.top->next;
		free(p);
		p = s.top;
	}
	s.top = NULL;
	s.count = 0;
	return OK;
}

Status stackEmpty(LinkStack s)
{
	//�ж�ջ�Ƿ�Ϊ��
	if (!s.top)
		return TRUE;
	return FALSE;
}

int stackLength(LinkStack s)
{
	return s.count;
}

Status getTop(LinkStack s, int &e)
{
	//��e����ջ��Ԫ��
	e = s.top->data;
	return OK;
}

Status push(LinkStack &s, int e)
{
	//��ջ
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!p)
		exit(OVERFLOW);
	if (!s.top)    //��һ����ջԪ�ص�ָ����Ϊ�գ���ָ���κν��
		p->next = NULL;
	else           //��������ջԪ�ص�ָ����ָ��ǰһ�����
		p->next = s.top;
	p->data = e;
	s.top = p;
	s.count++;
	return OK;
}

Status pop(LinkStack &s, int &e)
{
	//��e���س�ջԪ��
	if (stackEmpty(s))
		return ERROR;
	e = s.top->data;
	LinkStackPtr p = s.top;
	if (s.top->next)
	{
		s.top = s.top->next;
		free(p);
	}
	else
		free(s.top);
	s.count--;
	return OK;
}

void stackTraverse(LinkStack s)
{
	//����ջ��Ԫ�أ��������ӡ
	while (!stackEmpty(s))
	{
		printf("%d ", s.top->data);
		s.top = s.top->next;
	}
}