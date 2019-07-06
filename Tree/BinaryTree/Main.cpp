#include<stdio.h>
#include"BiTree.h"

void printMenu();

int main()
{
	BiTree T = NULL;
	int runFlag = 1;
	int num;
	while (runFlag)
	{
		do
		{
			printMenu();
			scanf_s("%d", &num);
			if (num < 0 || num>4)
				printf("菜单号输入错误，请重新输入。\n");
		} while (num < 0 || num>4);

		switch (num)
		{
		case 0:
		{
			runFlag = 0;
			printf("程序已退出。\n");
			break;
		}
		case 1:
		{
			printf("请输入二叉树结点值：");
			if (createBiTree(T))
				printf("创建二叉树成功。\n");
			else
				printf("创建二叉树失败。\n");
			break;
		}
		case 2:
		{
			printf("先序遍历二叉树的结果为：");
			if (preOrderTraverse(T, visit))
				printf("\n");
			else
				printf("先序遍历二叉树失败。\n");
			break;
		}
		case 3:
		{
			printf("中序遍历二叉树的结果为：");
			if (inOrderTraverse(T, visit))
				;
			else
				printf("中序遍历二叉树失败。\n");
			break;
		}
		case 4:
		{
			printf("后序遍历二叉树的结果为：");
			if (postOrderTraverse(T, visit))
				;
			else
				printf("后序遍历二叉树失败。\n");
			break;
		}
		}
	}
	return 0;
}

void printMenu()
{
	printf("----------二叉树的基本操作(部分)----------\n");
	printf("----------1-创建二叉树--------------------\n");
	printf("----------2-先序遍历二叉树----------------\n");
	printf("----------3-中序遍历二叉树----------------\n");
	printf("----------4-后序遍历二叉树----------------\n");
	printf("----------0-退出程序----------------------\n");
	printf("----------请选择菜单号(0-4)---------------\n");
}