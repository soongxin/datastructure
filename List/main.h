#define MAXSIZE 20  /* 存储空间初始分配量 */
typedef int ElemType;  /* ElemeType 类型根据实际情况而定, 这里假定为int */

typedef struct {
  ElemType data[MAXSIZE];  /* 数组存储数据元素, 最大值为MAXSIZE */
  int length;  /* 线性表的当前长度 */
}list;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;