#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define STACK_INIT_SIZE 100     //存储空间初始分配量
#define STACKINCREMENT 10       //存储空间分配增量

typedef int SElemType;
typedef int status; 

typedef struct
{
	SElemType *base;            //栈底指针，在栈构造之前和销毁之后，base的值为NULL
	SElemType *top;             //栈顶指针
	int stacksize;              //当前已分配的存储空间，以元素为单位
}SqStack;

/*栈的基本操作的函数原型声明*/
status initStack(SqStack &S);              //构造一个空栈
status destroyStack(SqStack &S);           //销毁栈S，S不再存在
status clearStack(SqStack &S);             //把S置为空栈
int stackEmpty(SqStack S);                 //若栈S为空栈，则返回TRUE，否则返回FALSE
int stackLength(SqStack S);                //返回S的元素个数，即栈的长度
status getTop(SqStack S, SElemType &e);    //若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
status push(SqStack &S, SElemType e);      //插入元素e为新的栈顶元素
status pop(SqStack &S, SElemType &e);      //若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
void stackTraverse(SqStack S);             //遍历栈中元素，并将其打印