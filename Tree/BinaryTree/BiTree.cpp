#include<stdio.h>
#include<stdlib.h>
#include"BiTree.h"

status createBiTree(BiTree &T)
{
	char ch = getchar();
	if (ch == ' ')
		T = NULL;
	else
	{
		if (!(T = (BiTree)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		T->data = ch;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
	return OK;
}

status visit(char elem)
{
	printf("%c", elem);
	return OK;
}

status preOrderTraverse(BiTree T, status(*p)(char elem))
{
	if (T)
	{
		if ((*p)(T->data))
			if (preOrderTraverse(T->lchild, visit))
				if (preOrderTraverse(T->rchild, visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}

status inOrderTraverse(BiTree T, status(*p)(char elem))
{
	if (T)
	{
		if (inOrderTraverse(T->lchild, visit))
			if ((*p)(T->data))
				if (inOrderTraverse(T->rchild, visit))
					return OK;
		return ERROR;
	}
	return OK;
}

status postOrderTraverse(BiTree T, status(*p)(char elem))
{
	if (T)
	{
		if (postOrderTraverse(T->lchild, visit))
			if (postOrderTraverse(T->rchild, visit))
				if ((*p)(T->data))
					return OK;
		return ERROR;
	}
	return OK;
}