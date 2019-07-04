#include<stdio.h>
#include<stdlib.h>
#include"SingleLinkedList.h"

void printMenu();

int main()
{
	LinkList La = NULL;
	LinkList Lb = NULL;
	LinkList Lc = NULL;
	int runFlag = 1;
	int num;
	while (runFlag)
	{
		do
		{
			printMenu();
			scanf_s("%d", &num);
			if (num < 0 || num>14)
				printf("菜单号输入错误，请重新输入。\n");
		} while (num < 0 || num>14);

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
			if (initList(La))
				printf("构造空链表La成功。\n");
			else
				printf("构造空链表La失败。\n");
			if (initList(Lb))
				printf("构造空链表Lb成功。\n");
			else
				printf("构造空链表Lb失败。\n");
			if (initList(Lb))
				printf("构造空链表Lc成功。\n");
			else
				printf("构造空链表Lc失败。\n");
			break;
		}
		case 2:
		{
			if (destroyList(La))
				printf("单链表La已销毁。\n");
			else
				printf("单链表La销毁失败。\n");
			if (destroyList(La))
				printf("单链表Lb已销毁。\n");
			else
				printf("单链表Lb销毁失败。\n");
			if (destroyList(Lc))
				printf("单链表Lc已销毁。\n");
			else
				printf("单链表Lc销毁失败。\n");
			break;
		}
		case 3:
		{
			if (clearList(La))
				printf("单链表La已清空。\n");
			else
				printf("单链表La未清空。\n");
			break;
		}
		case 4:
		{
			if (listEmpty(La))
				printf("单链表La为空。\n");
			else
				printf("单链表La非空。\n");
			break;
		}
		case 5:
		{
			int length = listLength(La);
			printf("单链表La的长度为：%d\n", length);
			break;
		}
		case 6:
		{
			printf("请输入元素在La中的位置：");
			int i, elem;
			scanf_s("%d", &i);
			if (getElem(La, i, elem))
				printf("第%d号元素为：%d\n", i, elem);
			else
				printf("此元素不在La中。\n");
			break;
		}
		case 7:
		{
			printf("请输入想要查询的元素：");
			int elem;
			scanf_s("%d", &elem);
			int index = locateElem(La, elem);
			printf("该元素在La中的位置为：%d\n", index);
			break;
		}
		case 8:
		{
			int cur_e, pre_e;
			printf("请输入想要查询的元素：");
			scanf_s("%d", &cur_e);
			if (priorElem(La, cur_e, pre_e))
				printf("%d的前驱元素为：%d\n", cur_e, pre_e);
			break;
		}
		case 9:
		{
			int cur_e, next_e;
			printf("请输入想要查询的元素：");
			scanf_s("%d", &cur_e);
			if (nextElem(La, cur_e, next_e))
				printf("%d的后继元素为：%d\n", cur_e, next_e);
			break;
		}
		case 10:
		{
			int i, elem;
			printf("请输入元素的插入位置。");
			scanf_s("%d", &i);
			printf("请输入插入元素：");
			scanf_s("%d", &elem);
			if (listInsert(La, i, elem))
				printf("插入成功。\n");
			else
				printf("插入位置错误。\n");
			break;
		}
		case 11:
		{
			printf("请输入想要删除的位置：");
			int i;
			scanf_s("%d", &i);
			int elem;
			if (listDelete(La, i, elem))
				printf("删除的元素为：%d\n", elem);
			else
				printf("单链表La为空或删除位置错误。\n");
			break;
		}
		case 12:
		{
			printf("请输入La中元素：");
			if (createList(La, 5))
				printf("创建单链表La成功。\n");
			else
				printf("创建失败。\n");
			printf("请输入Lb中元素：");
			if (createList(Lb, 5))
				printf("创建单链表Lb成功。\n");
			else
				printf("创建单链表Lb失败。\n");
			break;
		}
		case 13:
		{
			int n;
			printf("遍历La请输入1，\n遍历Lb请输入2，\n遍历Lc请输入3：\n");
			scanf_s("%d", &n);
			switch (n)
			{
			case 1:
			{
				printf("单链表La中的元素为：");
				listTraverse(La);
				printf("\n");
				break;
			}
			case 2:
			{
				printf("单链表Lb中的元素为：");
				listTraverse(Lb);
				printf("\n");
				break;
			}
			case 3:
			{
				printf("单链表Lc中的元素为：");
				listTraverse(Lc);
				printf("\n");
				break;
			}
			}
			break;
		}
		case 14:
		{
			if (mergeList(La, Lb, Lc))
				printf("归并单链表成功。\n");
			else
				printf("归并单链表失败。\n");
			break;
		}
		}
	}
	return 0;
}

void printMenu()
{
	printf("---------单链表的基本操作---------\n");
	printf("---------1-构造空单链表-----------\n");
	printf("---------2-销毁单链表-------------\n");
	printf("---------3-清空单链表-------------\n");
	printf("---------4-判断单链表是否为空-----\n");
	printf("---------5-计算单链表中元素个数---\n");
	printf("---------6-获取单链表中元素-------\n");
	printf("---------7-定位元素在表中的位置---\n");
	printf("---------8-获取当前元素的前驱-----\n");
	printf("---------9-获取当前元素的后继-----\n");
	printf("---------10-插入元素--------------\n");
	printf("---------11-删除元素--------------\n");
	printf("---------12-创建单链表------------\n");
	printf("---------13-遍历单链表------------\n");
	printf("---------14-归并单链表(有序)------\n");
	printf("---------0-退出程序---------------\n");
	printf("---------请选择菜单号(0-14)-------\n");
}