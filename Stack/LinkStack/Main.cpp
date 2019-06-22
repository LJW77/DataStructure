#include<stdio.h>
#include"LinkStack.h"

void printMenu();

int main()
{
	LinkStack s;
	int runFlag = 1;
	int num;
	while (runFlag)
	{
		do
		{
			printMenu();
			scanf_s("%d", &num);
			if (num < 0 || num>9)
				printf("菜单号输入错误，请重新输入！\n");
		} while (num < 0 || num>9);
		switch (num)
		{
		case 0:    //退出程序
		{
			printf("程序已经退出。\n");
			runFlag = 0;
			break;
		}
		case 1:    //构造栈
		{
			if (initStack(s))
				printf("构造栈成功。\n");
			break;
		}
		case 2:    //销毁栈
		{
			if (destroyStack(s))
				printf("栈已销毁。\n");
			break;
		}
		case 3:    //清空栈
		{
			if (clearStack(s))
				printf("栈已清空。\n");
			break;
		}
		case 4:    //判断栈是否为空
		{
			if (stackEmpty(s))
				printf("栈为空。\n");
			else
				printf("栈非空。\n");
			break;
		}
		case 5:    //计算栈的长度
		{
			int len = stackLength(s);
			printf("栈的长度为：%d\n", len);
			break;
		}
		case 6:    //获取栈顶元素
		{
			int e;
			getTop(s, e);
			printf("栈顶元素为:%d\n", e);
			break;
		}
		case 7:    //元素入栈
		{
			int i;
			for (i = 0; i < 10; ++i)
				push(s, i);
			break;
		}
		case 8:    //元素出栈
		{
			int i, e;
			printf("出栈元素为：");
			for (i = 0; i < 5; ++i)
			{ 
				pop(s, e);
				printf("%d ", e);
			}
			printf("\n");
			break;
		}
		case 9:    //遍历栈中元素
		{
			if (stackEmpty(s))
				printf("栈为空。\n");
			else
				stackTraverse(s);
			printf("\n");
			break;
		}
		}
	}
	return 0;
}

void printMenu()
{
	printf("         栈的基本操作         \n");
	printf("------------------------------\n");
	printf("*        1-构造栈            *\n");
	printf("*        2-销毁栈            *\n");
	printf("*        3-清空栈            *\n");
	printf("*        4-判断栈是否为空    *\n");
	printf("*        5-计算栈的长度      *\n");
	printf("*        6-获取栈顶元素      *\n");
	printf("*        7-入栈              *\n");
	printf("*        8-出栈              *\n");
	printf("*        9-遍历栈            *\n");
	printf("*        0-退出              *\n");
	printf("------------------------------\n");
	printf("      请选择菜单号(0-9):      \n");
}