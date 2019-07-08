#include<stdio.h>
#include<stdlib.h>	
#include"LinkStack.h"

Status initStack(LinkStack &s)    
{
	s.top = NULL;
	s.count = 0;
	return OK;
}

Status destroyStack(LinkStack &s)
{
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
	if (stackEmpty(s))
		return ERROR;
	e = s.top->data;
	return OK;
}

Status push(LinkStack &s, int e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!p)
		exit(OVERFLOW);
	if (!s.top)    //第一个入栈元素的指针域为空，不指向任何结点
		p->next = NULL;
	else           //否则新入栈元素的指针域指向前一个结点
		p->next = s.top;
	p->data = e;
	s.top = p;
	s.count++;
	return OK;
}

Status pop(LinkStack &s, int &e)
{
	if (stackEmpty(s))
		return ERROR;
	e = s.top->data;
	LinkStackPtr p = s.top;
	if (p)
	{
		s.top = s.top->next;
		free(p);
		p = s.top;
	}
	s.count--;
	return OK;
}

void visit(int e)
{
	printf("%d ", e);
}

void stackTraverse(LinkStack s, void(*p)(int e))
{
	while (!stackEmpty(s))
	{
		(*p)(s.top->data);
		s.top = s.top->next;
	}
}
