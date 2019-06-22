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
				printf("�˵�������������������룡\n");
		} while (num < 0 || num>9);
		switch (num)
		{
		case 0:    //�˳�����
		{
			printf("�����Ѿ��˳���\n");
			runFlag = 0;
			break;
		}
		case 1:    //����ջ
		{
			if (initStack(s))
				printf("����ջ�ɹ���\n");
			break;
		}
		case 2:    //����ջ
		{
			if (destroyStack(s))
				printf("ջ�����١�\n");
			break;
		}
		case 3:    //���ջ
		{
			if (clearStack(s))
				printf("ջ����ա�\n");
			break;
		}
		case 4:    //�ж�ջ�Ƿ�Ϊ��
		{
			if (stackEmpty(s))
				printf("ջΪ�ա�\n");
			else
				printf("ջ�ǿա�\n");
			break;
		}
		case 5:    //����ջ�ĳ���
		{
			int len = stackLength(s);
			printf("ջ�ĳ���Ϊ��%d\n", len);
			break;
		}
		case 6:    //��ȡջ��Ԫ��
		{
			int e;
			getTop(s, e);
			printf("ջ��Ԫ��Ϊ:%d\n", e);
			break;
		}
		case 7:    //Ԫ����ջ
		{
			int i;
			for (i = 0; i < 10; ++i)
				push(s, i);
			break;
		}
		case 8:    //Ԫ�س�ջ
		{
			int i, e;
			printf("��ջԪ��Ϊ��");
			for (i = 0; i < 5; ++i)
			{ 
				pop(s, e);
				printf("%d ", e);
			}
			printf("\n");
			break;
		}
		case 9:    //����ջ��Ԫ��
		{
			if (stackEmpty(s))
				printf("ջΪ�ա�\n");
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
	printf("         ջ�Ļ�������         \n");
	printf("------------------------------\n");
	printf("*        1-����ջ            *\n");
	printf("*        2-����ջ            *\n");
	printf("*        3-���ջ            *\n");
	printf("*        4-�ж�ջ�Ƿ�Ϊ��    *\n");
	printf("*        5-����ջ�ĳ���      *\n");
	printf("*        6-��ȡջ��Ԫ��      *\n");
	printf("*        7-��ջ              *\n");
	printf("*        8-��ջ              *\n");
	printf("*        9-����ջ            *\n");
	printf("*        0-�˳�              *\n");
	printf("------------------------------\n");
	printf("      ��ѡ��˵���(0-9):      \n");
}