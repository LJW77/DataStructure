#include<stdio.h>
#include"SqLinearList.h"

void printMenu();

int main()
{
	SqList La, Lb, Lc;
	int runFlag = 1;
	int num;
	while (runFlag)
	{
		do
		{
			printMenu();
			scanf_s("%d", &num);
			if (num < 0 || num>15)
				printf("菜单号输入错误，请重新输入。\n");
		} while (num < 0 || num>15);

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
			if (initList(&La))
				printf("构造空线性表成功。\n");
			else
				printf("构造空线性表失败。\n");
			break;
		}
		case 2:
		{
			if (destroyList(&La))
				printf("销毁线性表成功。\n");
			else
				printf("销毁线性表失败。\n");
			break;
		}
		case 3:
		{
			if (clearList(&La))
				printf("线性表L已清空。\n");
			else
				printf("清空失败。\n");
			break;
		}
		case 4:
		{
			if (listEmpty(La))
				printf("线性表为空。\n");
			else
				printf("线性表非空。\n");
			break;
		}
		case 5:
		{
			int length = listLength(La);
			printf("线性表L的长度为：%d\n", length);
			break;
		}
		case 6:
		{
			printf("请输入表的位置：");
			int i, elem;
			scanf_s("%d", &i);
			if (getElem(La, i, &elem))
				printf("第%d号元素为：%d\n", i, elem);
			else
				printf("线性表为空或是索引越界。\n");
			break;
		}
		case 7:
		{
			printf("请输入想要查询的元素。\n");
			int elem;
			scanf_s("%d", &elem);
			int index = locateElem(La, elem);
			printf("%d在表中的位置为：%d\n", elem, index);
			break;
		}
		case 8:
		{
			printf("请输入想要查询的元素。\n");
			int cur_e;
			scanf_s("%d", &cur_e);
			int pre_e;
			if (priorElem(La, cur_e, &pre_e))
				printf("%d的前驱元素为：%d\n", cur_e, pre_e);
			else
				printf("线性表为空或第一个元素没有前驱。\n");
			break;
		}
		case 9:
		{
			printf("请输入想要查询的元素。\n");
			int cur_e;
			scanf_s("%d", &cur_e);
			int next_e;
			if (nextElem(La, cur_e, &next_e))
				printf("%d的后继元素为：%d\n", cur_e, next_e);
			else
				printf("线性表为空或最后一个元素没有后继。\n");
			break;
		}
		case 10:
		{
			printf("请输入插入位置：\n");
			int i;
			scanf_s("%d", &i);
			printf("请输入插入元素：\n");
			int elem;
			scanf_s("%d", &elem);
			if (listInsert(&La, i, elem))
				printf("插入元素成功。\n");
			else
				printf("插入位置错误。\n");
			break;
		}
		case 11:
		{
			printf("请输入想要删除的位置：\n");
			int i;
			scanf_s("%d", &i);
			int elem;
			if (listDelete(&La, i, &elem))
				printf("删除的元素为%d：\n", elem);
			else
				printf("线性表为空或删除位置错误。\n");
			break;
		}
		case 12:
		{
			printf("请输入La中元素：");
			if (createList(&La))
				printf("创建线性表La成功。\n");
			else
				printf("创建失败。\n");
			printf("请输入Lb中元素：");
			if (createList(&Lb))
				printf("创建线性表Lb成功。\n");
			else
				printf("创建失败。\n");
			break;
		}
		case 13:
		{
			int n;
			printf("遍历La请输入1，遍历Lb请输入2，遍历Lc请输入3：");
			scanf_s("%d", &n);
			switch (n)
			{
			case 1:
			{
				printf("线性表La中的元素为：");
				listTraverse(La);
				printf("\n");
				break;
			}
			case 2:
			{
				printf("线性表Lb中的元素为：");
				listTraverse(Lb);
				printf("\n");
				break;
			}
			case 3:
			{
				printf("线性表Lc中的元素为：");
				listTraverse(Lc);
				printf("\n");
				break;
			}
			}
			break;
		}
		case 14:
		{
			unionList(&La, Lb);
			break;
		}
		case 15:
		{
			mergeList(La, Lb, &Lc);
			break;
		}
		}
	}
	return 0;
}

void printMenu()
{
	printf("---------线性表的基本操作---------\n");
	printf("---------1-构造空线性表-----------\n");
	printf("---------2-销毁线性表-------------\n");
	printf("---------3-清空线性表-------------\n");
	printf("---------4-判断线性表是否为空-----\n");
	printf("---------5-计算线性表中元素个数---\n");
	printf("---------6-获取线性表中元素-------\n");
	printf("---------7-定位元素在表中的位置---\n");
	printf("---------8-获取当前元素的前驱-----\n");
	printf("---------9-获取当前元素的后继-----\n");
	printf("---------10-插入元素--------------\n");
	printf("---------11-删除元素--------------\n");
	printf("---------12-创建线性表------------\n");
	printf("---------13-遍历线性表------------\n");
	printf("---------14-合并线性表(无序)------\n");
	printf("---------15-归并线性表(有序)------\n");
	printf("---------0-退出程序---------------\n");
	printf("---------请选择菜单号(0-15)-------\n");
}