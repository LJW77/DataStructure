#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1

typedef int SElemType;
typedef int Status;

/*链栈结点结构定义*/
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

/*链栈定义*/
typedef struct
{
	LinkStackPtr top;
	int count;
}LinkStack;

/*栈的基本操作*/
Status initStack(LinkStack &s);        //构造一个空栈
Status destroyStack(LinkStack &s);     //销毁栈
Status clearStack(LinkStack &s);       //将栈重置为空
Status stackEmpty(LinkStack s);        //判断栈是否为空
int stackLength(LinkStack s);          //计算栈的长度
Status getTop(LinkStack s, int &e);    //用e返回栈顶元素
Status push(LinkStack &s, int e);      //入栈
Status pop(LinkStack &s, int &e);      //用e返回出栈元素
void stackTraverse(LinkStack s);       //遍历栈中元素，并将其打印