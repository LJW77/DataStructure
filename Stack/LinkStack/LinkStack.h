#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1

typedef int SElemType;
typedef int Status;

/*��ջ���ṹ����*/
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

/*��ջ����*/
typedef struct
{
	LinkStackPtr top;
	int count;
}LinkStack;

/*ջ�Ļ�������*/
Status initStack(LinkStack &s);        //����һ����ջ
Status destroyStack(LinkStack &s);     //����ջ
Status clearStack(LinkStack &s);       //��ջ����Ϊ��
Status stackEmpty(LinkStack s);        //�ж�ջ�Ƿ�Ϊ��
int stackLength(LinkStack s);          //����ջ�ĳ���
Status getTop(LinkStack s, int &e);    //��e����ջ��Ԫ��
Status push(LinkStack &s, int e);      //��ջ
Status pop(LinkStack &s, int &e);      //��e���س�ջԪ��
void stackTraverse(LinkStack s);       //����ջ��Ԫ�أ��������ӡ