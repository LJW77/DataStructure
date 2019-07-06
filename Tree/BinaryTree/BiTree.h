#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1

typedef int status;
typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild;    //左孩子指针
	struct BiTNode *rchild;    //有孩子指针
}BiTNode, *BiTree;

//----------二叉树的基本操作函数原型说明(部分)----------
/*按先序次序输入二叉树中结点的值(一个字符)，空格字符表示空树，
  构造二叉链表表示的二叉树T。
  */
status createBiTree(BiTree &T);

/*打印结点值
  */
status visit(char elem);

/*采用二叉链表表示存储结构，visit是对结点操作的应用函数。
  先序遍历二叉树T，对每个结点调用函数visit一次且仅一次。
  一旦visit()失败，则操作失败。
  */
status preOrderTraverse(BiTree T, status(*p)(char elem));

/*采用二叉链表表示存储结构，visit是对结点操作的应用函数。
  中序遍历二叉树T，对每个结点调用函数visit一次且仅一次。
  一旦visit()失败，则操作失败。
  */
status inOrderTraverse(BiTree T, status(*p)(char elem));

/*采用二叉链表表示存储结构，visit是对结点操作的应用函数。
  后序遍历二叉树T，对每个结点调用函数visit一次且仅一次。
  一旦visit()失败，则操作失败。
  */
status postOrderTraverse(BiTree T, status(*p)(char elem));