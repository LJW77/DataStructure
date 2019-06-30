#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;
typedef int status;

typedef struct
{
	ElemType *elem;    //�洢�ռ��ַ
	int length;        //��ǰ����
	int listsize;      //��ǰ����Ĵ洢����
}SqList;

//���Ա�Ļ�������
/*�������������һ���յ����Ա�L��
  */
status initList(SqList *L);        

/*��ʼ���������Ա�L�Ѵ��ڡ�
  ����������������Ա�L��
  */					
status destroyList(SqList *L);  

/*��ʼ���������Ա�L�Ѵ��ڡ�
  �����������L����Ϊ�ձ�*/
status clearList(SqList *L);       

/*��ʼ���������Ա�L�Ѵ��ڡ�
  �����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE��
  */
status listEmpty(SqList L);                                    

/*��ʼ���������Ա�L�Ѵ��ڡ�
  �������������L������Ԫ�ظ�����
  */
int listLength(SqList L);                                       

/*��ʼ���������Ա�L�Ѵ��ڣ�0=<i<=ListLength(L)-1��
  �����������e����L�е�i������Ԫ�ص�ֵ��
  */
status getElem(SqList L, int i, ElemType *e);   

/*��ʼ���������Ա�L�Ѵ��ڡ�
  �������������L�е�һ����e��ȵ�����Ԫ�ص�λ����������
  ����Ԫ�ز����ڣ��򷵻�ֵΪ0��
  */
int locateElem(SqList L, ElemType e); 

/*��ʼ���������Ա�L�Ѵ��ڡ�
  �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ����
  ����pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣
  */
status priorElem(SqList L, ElemType cur_e, ElemType *pre_e);   

/*��ʼ���������Ա�L�Ѵ��ڡ�
  �����������cur_e��L������Ԫ�أ��Ҳ������һ����
  ����next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣
  */
status nextElem(SqList L, ElemType cur_e, ElemType *next_e);

/*��ʼ���������Ա�L�Ѵ��ڣ�0=<i<=ListLength(L)��
  �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1��
  */
status listInsert(SqList *L, int i, ElemType e);   

/*��ʼ���������Ա�L�Ѵ����ҷǿգ�0=<i<=ListLength(L)-1��
  ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1��
  */
status listDelete(SqList *L, int i, ElemType *e);  

/*�������Ա�
  */
status createList(SqList *L);

/*��ʼ���������Ա�L�Ѵ��ڡ�
  ����������������Ա�L������ӡ��Ԫ�ء�
  */
void listTraverse(SqList L);        

/*�����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La�С�
  */
void unionList(SqList *La, SqList Lb);       

/*��֪���Ա�La��Lb�е�����Ԫ�ذ�ֵ�ǵݼ����С�
  �鲢La��Lb�õ��µ����Ա�Lc��Lc������Ԫ��Ҳ��ֵ�ǵݼ����С�
  */
void mergeList(SqList La, SqList Lb, SqList *Lc);               
