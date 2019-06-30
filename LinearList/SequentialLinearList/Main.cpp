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
				printf("�˵�������������������롣\n");
		} while (num < 0 || num>15);

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
			if (initList(&La))
				printf("��������Ա�ɹ���\n");
			else
				printf("��������Ա�ʧ�ܡ�\n");
			break;
		}
		case 2:
		{
			if (destroyList(&La))
				printf("�������Ա�ɹ���\n");
			else
				printf("�������Ա�ʧ�ܡ�\n");
			break;
		}
		case 3:
		{
			if (clearList(&La))
				printf("���Ա�L����ա�\n");
			else
				printf("���ʧ�ܡ�\n");
			break;
		}
		case 4:
		{
			if (listEmpty(La))
				printf("���Ա�Ϊ�ա�\n");
			else
				printf("���Ա�ǿա�\n");
			break;
		}
		case 5:
		{
			int length = listLength(La);
			printf("���Ա�L�ĳ���Ϊ��%d\n", length);
			break;
		}
		case 6:
		{
			printf("��������λ�ã�");
			int i, elem;
			scanf_s("%d", &i);
			if (getElem(La, i, &elem))
				printf("��%d��Ԫ��Ϊ��%d\n", i, elem);
			else
				printf("���Ա�Ϊ�ջ�������Խ�硣\n");
			break;
		}
		case 7:
		{
			printf("��������Ҫ��ѯ��Ԫ�ء�\n");
			int elem;
			scanf_s("%d", &elem);
			int index = locateElem(La, elem);
			printf("%d�ڱ��е�λ��Ϊ��%d\n", elem, index);
			break;
		}
		case 8:
		{
			printf("��������Ҫ��ѯ��Ԫ�ء�\n");
			int cur_e;
			scanf_s("%d", &cur_e);
			int pre_e;
			if (priorElem(La, cur_e, &pre_e))
				printf("%d��ǰ��Ԫ��Ϊ��%d\n", cur_e, pre_e);
			else
				printf("���Ա�Ϊ�ջ��һ��Ԫ��û��ǰ����\n");
			break;
		}
		case 9:
		{
			printf("��������Ҫ��ѯ��Ԫ�ء�\n");
			int cur_e;
			scanf_s("%d", &cur_e);
			int next_e;
			if (nextElem(La, cur_e, &next_e))
				printf("%d�ĺ��Ԫ��Ϊ��%d\n", cur_e, next_e);
			else
				printf("���Ա�Ϊ�ջ����һ��Ԫ��û�к�̡�\n");
			break;
		}
		case 10:
		{
			printf("���������λ�ã�\n");
			int i;
			scanf_s("%d", &i);
			printf("���������Ԫ�أ�\n");
			int elem;
			scanf_s("%d", &elem);
			if (listInsert(&La, i, elem))
				printf("����Ԫ�سɹ���\n");
			else
				printf("����λ�ô���\n");
			break;
		}
		case 11:
		{
			printf("��������Ҫɾ����λ�ã�\n");
			int i;
			scanf_s("%d", &i);
			int elem;
			if (listDelete(&La, i, &elem))
				printf("ɾ����Ԫ��Ϊ%d��\n", elem);
			else
				printf("���Ա�Ϊ�ջ�ɾ��λ�ô���\n");
			break;
		}
		case 12:
		{
			printf("������La��Ԫ�أ�");
			if (createList(&La))
				printf("�������Ա�La�ɹ���\n");
			else
				printf("����ʧ�ܡ�\n");
			printf("������Lb��Ԫ�أ�");
			if (createList(&Lb))
				printf("�������Ա�Lb�ɹ���\n");
			else
				printf("����ʧ�ܡ�\n");
			break;
		}
		case 13:
		{
			int n;
			printf("����La������1������Lb������2������Lc������3��");
			scanf_s("%d", &n);
			switch (n)
			{
			case 1:
			{
				printf("���Ա�La�е�Ԫ��Ϊ��");
				listTraverse(La);
				printf("\n");
				break;
			}
			case 2:
			{
				printf("���Ա�Lb�е�Ԫ��Ϊ��");
				listTraverse(Lb);
				printf("\n");
				break;
			}
			case 3:
			{
				printf("���Ա�Lc�е�Ԫ��Ϊ��");
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
	printf("---------���Ա�Ļ�������---------\n");
	printf("---------1-��������Ա�-----------\n");
	printf("---------2-�������Ա�-------------\n");
	printf("---------3-������Ա�-------------\n");
	printf("---------4-�ж����Ա��Ƿ�Ϊ��-----\n");
	printf("---------5-�������Ա���Ԫ�ظ���---\n");
	printf("---------6-��ȡ���Ա���Ԫ��-------\n");
	printf("---------7-��λԪ���ڱ��е�λ��---\n");
	printf("---------8-��ȡ��ǰԪ�ص�ǰ��-----\n");
	printf("---------9-��ȡ��ǰԪ�صĺ��-----\n");
	printf("---------10-����Ԫ��--------------\n");
	printf("---------11-ɾ��Ԫ��--------------\n");
	printf("---------12-�������Ա�------------\n");
	printf("---------13-�������Ա�------------\n");
	printf("---------14-�ϲ����Ա�(����)------\n");
	printf("---------15-�鲢���Ա�(����)------\n");
	printf("---------0-�˳�����---------------\n");
	printf("---------��ѡ��˵���(0-15)-------\n");
}