#include<stdio.h>
#include<stdlib.h>
#include"SequenceStack.h"

status initStack(SqStack &S)//�������
{
	//����һ����ջ
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

status destroyStack(SqStack &S)//�������
{
	//����ջS��S���ٴ���
	free(S.base);
	return OK;
}

status clearStack(SqStack &S)//�������
{
	//��S��Ϊ��ջ
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

status stackEmpty(SqStack S)//�������
{
	//��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
	if (S.base == S.top)
		return TRUE;
	return FALSE;
}

int stackLength(SqStack S)//�������
{
	//����S��Ԫ�ظ�������ջ�ĳ���
	int length = S.top - S.base;
	return length;
}

status getTop(SqStack S, SElemType &e)//�������
{
	//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if (S.base == S.top)
		return ERROR;
	e = *(S.top - 1);
	return OK;
}

status push(SqStack &S, SElemType e)//�������
{
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base >= S.stacksize)    //ջ����׷�ӿռ�
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base)                      //�洢����ʧ��
			exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

status pop(SqStack &S, SElemType &e)//�������
{
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if (S.top == S.base)    //ջ��
		return ERROR;
	e = *--S.top;
	return OK;
}

void stackTraverse(SqStack S)//�������
{
	//����ջ��Ԫ�أ��������ӡ
	SElemType *p = S.base;
	while (p < S.top)
	{
		printf("%d ", *p);
		p++;
	}
}