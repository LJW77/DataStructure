#include<stdio.h>
#include<stdlib.h>	
#include"LinkStack.h"

Status initStack(LinkStack &s)    
{
	//构造一个空栈
	s.top = NULL;
	s.count = 0;
	return OK;
}

Status destroyStack(LinkStack &s)
{
	//销毁栈
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
	//将栈重置为空
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
	//判断栈是否为空
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
	//用e返回栈顶元素
	e = s.top->data;
	return OK;
}

Status push(LinkStack &s, int e)
{
	//入栈
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
	//用e返回出栈元素
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
	//遍历栈中元素，并将其打印
	while (!stackEmpty(s))
	{
		printf("%d ", s.top->data);
		s.top = s.top->next;
	}
}