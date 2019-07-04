#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1

typedef int ElemType;
typedef int status;

typedef struct LNode       //��������    
{
	ElemType data;         //������
	struct LNode *next;    //ָ����
}LNode, *LinkList;

//������Ļ�������
/*�������������һ����ͷ���ĵĿյĵ�����L��
  */
status initList(LinkList &L);       

/*��ʼ���������Ա�L�Ѵ��ڡ�
  ����������������Ա�L��
  */
status destroyList(LinkList &L); 

/*��ʼ���������Ա�L�Ѵ��ڡ�
  �����������L����Ϊ�ձ�
  */
status clearList(LinkList &L);       

/*��ʼ���������Ա�L�Ѵ��ڡ�
  �����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE��
  */
status listEmpty(LinkList L); 

/*��ʼ���������Ա�L�Ѵ��ڡ�
  �������������L������Ԫ�ظ�����
  */
int listLength(LinkList L); 

/*��ʼ���������Ա�L�Ѵ��ڣ�0=<i<=ListLength(L)-1��
  �����������e����L�е�i������Ԫ�ص�ֵ��
  */
status getElem(LinkList L, int i, ElemType &e);  

/*��ʼ���������Ա�L�Ѵ��ڡ�
  �������������L�е�һ����e��ȵ�����Ԫ�ص�λ����������
  ����Ԫ�ز����ڣ��򷵻�ֵΪ0��
  */
int locateElem(LinkList L, ElemType e);  

/*��ʼ���������Ա�L�Ѵ��ڡ�
  �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ����
  ����pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣
  */ 
status priorElem(LinkList L, int cur_e, ElemType &pre_e);     

/*��ʼ���������Ա�L�Ѵ��ڡ�
  �����������cur_e��L������Ԫ�أ��Ҳ������һ����
  ����next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣
  */
status nextElem(LinkList L, int cur_e, ElemType &next_e);

/*��ʼ���������Ա�L�Ѵ��ڣ�0=<i<=ListLength(L)��
  �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1��
  */
status listInsert(LinkList &L, int i, ElemType e);

/*��ʼ���������Ա�L�Ѵ����ҷǿգ�0=<i<=ListLength(L)-1��
  ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1��
  */
status listDelete(LinkList &L, int i, ElemType &e);  

/*���쵥����
  */
status createList(LinkList &L, int n);

/*��֪���Ա�La��Lb�е�����Ԫ�ذ�ֵ�ǵݼ����С�
  �鲢La��Lb�õ��µ����Ա�Lc��Lc������Ԫ��Ҳ��ֵ�ǵݼ����С�
  */
status mergeList(LinkList &La, LinkList &Lb, LinkList &Lc);   
//status mergeList(LinkList &La, LinkList &Lb);    

/*����������L�е�Ԫ�أ��������ӡ
  */
void listTraverse(LinkList L);                                
