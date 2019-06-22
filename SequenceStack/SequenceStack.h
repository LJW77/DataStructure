#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define STACK_INIT_SIZE 100     //�洢�ռ��ʼ������
#define STACKINCREMENT 10       //�洢�ռ��������

typedef int SElemType;
typedef int status; 

typedef struct
{
	SElemType *base;            //ջ��ָ�룬��ջ����֮ǰ������֮��base��ֵΪNULL
	SElemType *top;             //ջ��ָ��
	int stacksize;              //��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;

/*ջ�Ļ��������ĺ���ԭ������*/
status initStack(SqStack &S);              //����һ����ջ
status destroyStack(SqStack &S);           //����ջS��S���ٴ���
status clearStack(SqStack &S);             //��S��Ϊ��ջ
int stackEmpty(SqStack S);                 //��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
int stackLength(SqStack S);                //����S��Ԫ�ظ�������ջ�ĳ���
status getTop(SqStack S, SElemType &e);    //��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
status push(SqStack &S, SElemType e);      //����Ԫ��eΪ�µ�ջ��Ԫ��
status pop(SqStack &S, SElemType &e);      //��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
void stackTraverse(SqStack S);             //����ջ��Ԫ�أ��������ӡ