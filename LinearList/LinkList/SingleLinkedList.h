#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1

typedef int ElemType;
typedef int status;

typedef struct LNode       //单链表结点    
{
	ElemType data;         //数据域
	struct LNode *next;    //指针域
}LNode, *LinkList;

//单链表的基本操作
/*操作结果：构造一个带头结点的的空的单链表L。
  */
status initList(LinkList &L);       

/*初始条件：线性表L已存在。
  操作结果：销毁线性表L。
  */
status destroyList(LinkList &L); 

/*初始条件：线性表L已存在。
  操作结果：将L重置为空表。
  */
status clearList(LinkList &L);       

/*初始条件：线性表L已存在。
  操作结果：若L为空表则返回TRUE，否则返回FALSE。
  */
status listEmpty(LinkList L); 

/*初始条件：线性表L已存在。
  操作结果：返回L中数据元素个数。
  */
int listLength(LinkList L); 

/*初始条件：线性表L已存在，0=<i<=ListLength(L)-1。
  操作结果：用e返回L中第i个数据元素的值。
  */
status getElem(LinkList L, int i, ElemType &e);  

/*初始条件：线性表L已存在。
  操作结果：返回L中第一个与e相等的数据元素的位序。若这样的
  数据元素不存在，则返回值为0。
  */
int locateElem(LinkList L, ElemType e);  

/*初始条件：线性表L已存在。
  操作结果：若cur_e是L的数据元素，且不是第一个，
  则用pre_e返回它的前驱，否则操作失败，pre_e无定义。
  */ 
status priorElem(LinkList L, int cur_e, ElemType &pre_e);     

/*初始条件：线性表L已存在。
  操作结果：若cur_e是L的数据元素，且不是最后一个，
  则用next_e返回它的后继，否则操作失败，next_e无定义。
  */
status nextElem(LinkList L, int cur_e, ElemType &next_e);

/*初始条件：线性表L已存在，0=<i<=ListLength(L)。
  操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1。
  */
status listInsert(LinkList &L, int i, ElemType e);

/*初始条件：线性表L已存在且非空，0=<i<=ListLength(L)-1。
  操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1。
  */
status listDelete(LinkList &L, int i, ElemType &e);  

/*构造单链表
  */
status createList(LinkList &L, int n);

/*已知线性表La和Lb中的数据元素按值非递减排列。
  归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列。
  */
status mergeList(LinkList &La, LinkList &Lb, LinkList &Lc);   
//status mergeList(LinkList &La, LinkList &Lb);    

/*遍历单链表L中的元素，并将其打印
  */
void listTraverse(LinkList L);                                
