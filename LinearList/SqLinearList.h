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
	ElemType *elem;    //存储空间基址
	int length;        //当前长度
	int listsize;      //当前分配的存储容量
}SqList;

//线性表的基本操作
/*操作结果：构造一个空的线性表L。
  */
status initList(SqList *L);        

/*初始条件：线性表L已存在。
  操作结果：销毁线性表L。
  */					
status destroyList(SqList *L);  

/*初始条件：线性表L已存在。
  操作结果：将L重置为空表。*/
status clearList(SqList *L);       

/*初始条件：线性表L已存在。
  操作结果：若L为空表则返回TRUE，否则返回FALSE。
  */
status listEmpty(SqList L);                                    

/*初始条件：线性表L已存在。
  操作结果：返回L中数据元素个数。
  */
int listLength(SqList L);                                       

/*初始条件：线性表L已存在，0=<i<=ListLength(L)-1。
  操作结果：用e返回L中第i个数据元素的值。
  */
status getElem(SqList L, int i, ElemType *e);   

/*初始条件：线性表L已存在。
  操作结果：返回L中第一个与e相等的数据元素的位序。若这样的
  数据元素不存在，则返回值为0。
  */
int locateElem(SqList L, ElemType e); 

/*初始条件：线性表L已存在。
  操作结果：若cur_e是L的数据元素，且不是第一个，
  则用pre_e返回它的前驱，否则操作失败，pre_e无定义。
  */
status priorElem(SqList L, ElemType cur_e, ElemType *pre_e);   

/*初始条件：线性表L已存在。
  操作结果：若cur_e是L的数据元素，且不是最后一个，
  则用next_e返回它的后继，否则操作失败，next_e无定义。
  */
status nextElem(SqList L, ElemType cur_e, ElemType *next_e);

/*初始条件：线性表L已存在，0=<i<=ListLength(L)。
  操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1。
  */
status listInsert(SqList *L, int i, ElemType e);   

/*初始条件：线性表L已存在且非空，0=<i<=ListLength(L)-1。
  操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1。
  */
status listDelete(SqList *L, int i, ElemType *e);  

/*构造线性表
  */
status createList(SqList *L);

/*初始条件：线性表L已存在。
  操作结果：遍历线性表L，并打印其元素。
  */
void listTraverse(SqList L);        

/*将所有在线性表Lb中但不在La中的数据元素插入到La中。
  */
void unionList(SqList *La, SqList Lb);       

/*已知线性表La和Lb中的数据元素按值非递减排列。
  归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列。
  */
void mergeList(SqList La, SqList Lb, SqList *Lc);               
