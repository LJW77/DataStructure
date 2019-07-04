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
				printf("�˵�������������������롣\n");
		} while (num < 0 || num>14);

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
			if (initList(La))
				printf("���������La�ɹ���\n");
			else
				printf("���������Laʧ�ܡ�\n");
			if (initList(Lb))
				printf("���������Lb�ɹ���\n");
			else
				printf("���������Lbʧ�ܡ�\n");
			if (initList(Lb))
				printf("���������Lc�ɹ���\n");
			else
				printf("���������Lcʧ�ܡ�\n");
			break;
		}
		case 2:
		{
			if (destroyList(La))
				printf("������La�����١�\n");
			else
				printf("������La����ʧ�ܡ�\n");
			if (destroyList(La))
				printf("������Lb�����١�\n");
			else
				printf("������Lb����ʧ�ܡ�\n");
			if (destroyList(Lc))
				printf("������Lc�����١�\n");
			else
				printf("������Lc����ʧ�ܡ�\n");
			break;
		}
		case 3:
		{
			if (clearList(La))
				printf("������La����ա�\n");
			else
				printf("������Laδ��ա�\n");
			break;
		}
		case 4:
		{
			if (listEmpty(La))
				printf("������LaΪ�ա�\n");
			else
				printf("������La�ǿա�\n");
			break;
		}
		case 5:
		{
			int length = listLength(La);
			printf("������La�ĳ���Ϊ��%d\n", length);
			break;
		}
		case 6:
		{
			printf("������Ԫ����La�е�λ�ã�");
			int i, elem;
			scanf_s("%d", &i);
			if (getElem(La, i, elem))
				printf("��%d��Ԫ��Ϊ��%d\n", i, elem);
			else
				printf("��Ԫ�ز���La�С�\n");
			break;
		}
		case 7:
		{
			printf("��������Ҫ��ѯ��Ԫ�أ�");
			int elem;
			scanf_s("%d", &elem);
			int index = locateElem(La, elem);
			printf("��Ԫ����La�е�λ��Ϊ��%d\n", index);
			break;
		}
		case 8:
		{
			int cur_e, pre_e;
			printf("��������Ҫ��ѯ��Ԫ�أ�");
			scanf_s("%d", &cur_e);
			if (priorElem(La, cur_e, pre_e))
				printf("%d��ǰ��Ԫ��Ϊ��%d\n", cur_e, pre_e);
			break;
		}
		case 9:
		{
			int cur_e, next_e;
			printf("��������Ҫ��ѯ��Ԫ�أ�");
			scanf_s("%d", &cur_e);
			if (nextElem(La, cur_e, next_e))
				printf("%d�ĺ��Ԫ��Ϊ��%d\n", cur_e, next_e);
			break;
		}
		case 10:
		{
			int i, elem;
			printf("������Ԫ�صĲ���λ�á�");
			scanf_s("%d", &i);
			printf("���������Ԫ�أ�");
			scanf_s("%d", &elem);
			if (listInsert(La, i, elem))
				printf("����ɹ���\n");
			else
				printf("����λ�ô���\n");
			break;
		}
		case 11:
		{
			printf("��������Ҫɾ����λ�ã�");
			int i;
			scanf_s("%d", &i);
			int elem;
			if (listDelete(La, i, elem))
				printf("ɾ����Ԫ��Ϊ��%d\n", elem);
			else
				printf("������LaΪ�ջ�ɾ��λ�ô���\n");
			break;
		}
		case 12:
		{
			printf("������La��Ԫ�أ�");
			if (createList(La, 5))
				printf("����������La�ɹ���\n");
			else
				printf("����ʧ�ܡ�\n");
			printf("������Lb��Ԫ�أ�");
			if (createList(Lb, 5))
				printf("����������Lb�ɹ���\n");
			else
				printf("����������Lbʧ�ܡ�\n");
			break;
		}
		case 13:
		{
			int n;
			printf("����La������1��\n����Lb������2��\n����Lc������3��\n");
			scanf_s("%d", &n);
			switch (n)
			{
			case 1:
			{
				printf("������La�е�Ԫ��Ϊ��");
				listTraverse(La);
				printf("\n");
				break;
			}
			case 2:
			{
				printf("������Lb�е�Ԫ��Ϊ��");
				listTraverse(Lb);
				printf("\n");
				break;
			}
			case 3:
			{
				printf("������Lc�е�Ԫ��Ϊ��");
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
				printf("�鲢������ɹ���\n");
			else
				printf("�鲢������ʧ�ܡ�\n");
			break;
		}
		}
	}
	return 0;
}

void printMenu()
{
	printf("---------������Ļ�������---------\n");
	printf("---------1-����յ�����-----------\n");
	printf("---------2-���ٵ�����-------------\n");
	printf("---------3-��յ�����-------------\n");
	printf("---------4-�жϵ������Ƿ�Ϊ��-----\n");
	printf("---------5-���㵥������Ԫ�ظ���---\n");
	printf("---------6-��ȡ��������Ԫ��-------\n");
	printf("---------7-��λԪ���ڱ��е�λ��---\n");
	printf("---------8-��ȡ��ǰԪ�ص�ǰ��-----\n");
	printf("---------9-��ȡ��ǰԪ�صĺ��-----\n");
	printf("---------10-����Ԫ��--------------\n");
	printf("---------11-ɾ��Ԫ��--------------\n");
	printf("---------12-����������------------\n");
	printf("---------13-����������------------\n");
	printf("---------14-�鲢������(����)------\n");
	printf("---------0-�˳�����---------------\n");
	printf("---------��ѡ��˵���(0-14)-------\n");
}