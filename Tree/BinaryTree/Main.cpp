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
				printf("�˵�������������������롣\n");
		} while (num < 0 || num>4);

		switch (num)
		{
		case 0:
		{
			runFlag = 0;
			printf("�������˳���\n");
			break;
		}
		case 1:
		{
			printf("��������������ֵ��");
			if (createBiTree(T))
				printf("�����������ɹ���\n");
			else
				printf("����������ʧ�ܡ�\n");
			break;
		}
		case 2:
		{
			printf("��������������Ľ��Ϊ��");
			if (preOrderTraverse(T, visit))
				printf("\n");
			else
				printf("�������������ʧ�ܡ�\n");
			break;
		}
		case 3:
		{
			printf("��������������Ľ��Ϊ��");
			if (inOrderTraverse(T, visit))
				;
			else
				printf("�������������ʧ�ܡ�\n");
			break;
		}
		case 4:
		{
			printf("��������������Ľ��Ϊ��");
			if (postOrderTraverse(T, visit))
				;
			else
				printf("�������������ʧ�ܡ�\n");
			break;
		}
		}
	}
	return 0;
}

void printMenu()
{
	printf("----------�������Ļ�������(����)----------\n");
	printf("----------1-����������--------------------\n");
	printf("----------2-�������������----------------\n");
	printf("----------3-�������������----------------\n");
	printf("----------4-�������������----------------\n");
	printf("----------0-�˳�����----------------------\n");
	printf("----------��ѡ��˵���(0-4)---------------\n");
}