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
	struct BiTNode *lchild;    //����ָ��
	struct BiTNode *rchild;    //�к���ָ��
}BiTNode, *BiTree;

//----------�������Ļ�����������ԭ��˵��(����)----------
/*�������������������н���ֵ(һ���ַ�)���ո��ַ���ʾ������
  ������������ʾ�Ķ�����T��
  */
status createBiTree(BiTree &T);

/*��ӡ���ֵ
  */
status visit(char elem);

/*���ö��������ʾ�洢�ṹ��visit�ǶԽ�������Ӧ�ú�����
  �������������T����ÿ�������ú���visitһ���ҽ�һ�Ρ�
  һ��visit()ʧ�ܣ������ʧ�ܡ�
  */
status preOrderTraverse(BiTree T, status(*p)(char elem));

/*���ö��������ʾ�洢�ṹ��visit�ǶԽ�������Ӧ�ú�����
  �������������T����ÿ�������ú���visitһ���ҽ�һ�Ρ�
  һ��visit()ʧ�ܣ������ʧ�ܡ�
  */
status inOrderTraverse(BiTree T, status(*p)(char elem));

/*���ö��������ʾ�洢�ṹ��visit�ǶԽ�������Ӧ�ú�����
  �������������T����ÿ�������ú���visitһ���ҽ�һ�Ρ�
  һ��visit()ʧ�ܣ������ʧ�ܡ�
  */
status postOrderTraverse(BiTree T, status(*p)(char elem));