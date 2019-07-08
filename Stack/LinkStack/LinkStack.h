#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1

typedef int SElemType;
typedef int Status;

typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct
{
	LinkStackPtr top;
	int count;
}LinkStack;

//----------栈的基本操作----------//
/*操作结果：构造一个空栈S。
  */
Status initStack(LinkStack &s);

/*初始条件：栈S已存在。
  操作结果：栈S被销毁。
  */
Status destroyStack(LinkStack &s);    

/*初始条件：栈S已存在。
  操作结果：将S清为空栈。
  */
Status clearStack(LinkStack &s); 

/*初始条件：栈S已存在。
  操作结果：若栈S为空栈，则返回TRUE，否则返回FALSE。
  */
Status stackEmpty(LinkStack s); 

/*初始条件：栈S已存在。
  操作结果：返回S的元素个数，即栈的长度。
  */
int stackLength(LinkStack s);  

/*初始条件：栈S已存在且非空。
  操作结果：用e返回S的栈顶元素。
  */
Status getTop(LinkStack s, int &e);  

/*初始条件：栈S已存在。
  操作结果：插入元素e为新的栈顶元素。
  */
Status push(LinkStack &s, int e);    

/*初始条件：栈S已存在且非空。
  操作结果：删除S的栈顶元素，并用e返回其值。
  */
Status pop(LinkStack &s, int &e);      

/*打印元素值。
  */
void visit(int e);

/*初始条件：栈S已存在且非空。
  操作结果：从栈底到栈顶依次对S的每个数据元素调用函数visit()。一旦visit()失败，则操作失败。
  */
void stackTraverse(LinkStack s, void(*p)(int e));
