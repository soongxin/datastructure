#include <stdio.h>
#include "main.h"

void printList(list *L);
Status insertElem(list *L, int i, ElemType e);
Status getElem(list L, int i, ElemType *e);
Status removeElem(list *L, int i);

int main(void) {
  list myList;
  myList.length = 0;
  printf("初始化: ");
  printList(&myList);
  int i;
  for (i = 0; i < 20; i++) {
    insertElem(&myList, i, i);
  }
  printf("插入后: ");
  printList(&myList);
  removeElem(&myList, 10);
  printf("删除后: ");
  printList(&myList);
  return 0;
}


/* 打印列表 */
void printList(list *L) {
  printf("[");
  for (int i = 0; i < L->length; i++) {
    printf("%i", L->data[i]);
    if (i < L->length -1)
      printf(", ");
  }
  printf("]\n");
  printf("长度: %i\n", L->length);
}


/* Status 是函数的类型, 其值是函数结果状态码, 如OK等 */
/* 初始条件, 顺序线性表L已存在, 1 <= i <= ListLength(L) */
/* 操作结果: 用e返回L中第i个数据元素的值 */
Status getElem(list L, int i, ElemType *e) {
  if (L.length == 0 || i < 1 || i > L.length)
    return ERROR;
  *e = L.data[i-1];
  return OK;
}


/* 初始条件: 顺序线性表L已存在, 1 <= ListLength(L) */
/* 操作结果: 在L中第i个位置之前插入新的数据元素e, L的长度加1 */
Status insertElem(list *L, int i, ElemType e) {
  int k;
  if (L->length == MAXSIZE)  /* 顺序线性表已满 */
    return ERROR;
  if (i < 0 || i > L->length)  /* 当i不在范围内 */
    return ERROR;
  if (i < L->length) {
    /* 若加入位置不在表尾 */
    for (k = L->length; k >= i; k--) {
      L -> data[k+1] = L->data[k];
    }
    L -> data[i-1] = e;  /* 将新元素插入 */
    L -> length++;
    return OK;
  } else {
    /* 插入位置在表尾 */
    L->data[i] = e;
    L->length++;
    return OK;
  }
}


/* 删除操作 */
/* 操作结果: 删除线性表中第i个元素 */
Status removeElem(list *L, int i) {
  int k;
  if (i < 0 || i > L->length-1)
    return ERROR;                 //  删除下标不在范围内
  if (i < L->length) {
    for (k = i; i < L->length; i ++) {
      L->data[i] = L->data[i+1];
    }
    L->length--;
    return OK;
  } else {
    L->length--;
    return OK;
  }
}