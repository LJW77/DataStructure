#include<stdio.h>
#include<stdlib.h>
#include"SequenceStack.h"

status initStack(SqStack &S)//测试完成
{
	//构造一个空栈
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

status destroyStack(SqStack &S)//测试完成
{
	//销毁栈S，S不再存在
	free(S.base);
	return OK;
}

status clearStack(SqStack &S)//测试完成
{
	//把S置为空栈
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

status stackEmpty(SqStack S)//测试完成
{
	//若栈S为空栈，则返回TRUE，否则返回FALSE
	if (S.base == S.top)
		return TRUE;
	return FALSE;
}

int stackLength(SqStack S)//测试完成
{
	//返回S的元素个数，即栈的长度
	int length = S.top - S.base;
	return length;
}

status getTop(SqStack S, SElemType &e)//测试完成
{
	//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
	if (S.base == S.top)
		return ERROR;
	e = *(S.top - 1);
	return OK;
}

status push(SqStack &S, SElemType e)//测试完成
{
	//插入元素e为新的栈顶元素
	if (S.top - S.base >= S.stacksize)    //栈满，追加空间
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base)                      //存储分配失败
			exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

status pop(SqStack &S, SElemType &e)//测试完成
{
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
	if (S.top == S.base)    //栈空
		return ERROR;
	e = *--S.top;
	return OK;
}

void stackTraverse(SqStack S)//测试完成
{
	//遍历栈中元素，并将其打印
	SElemType *p = S.base;
	while (p < S.top)
	{
		printf("%d ", *p);
		p++;
	}
}