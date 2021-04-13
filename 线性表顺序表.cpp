#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 100   //初始分配容量
#define LISTINCREMENT 10     //增量
typedef int Elemtype;
typedef int status;
//结构体
typedef struct {
    Elemtype* elem;//空间基址
    int length;//线性表长度
    int listsize;
}sqlist;
//建立线性表
status Initlist(sqlist& L) {
    L.elem = (Elemtype*)malloc(LIST_INIT_SIZE * sizeof(Elemtype));//开辟新的存储空间
    if (!L.elem)exit(OVERFLOW);//创建错误返回OVERFLOW
    L.length = 0;//线性表初始长度
    L.listsize = LIST_INIT_SIZE;
    return OK;//创建成功返回OK
}
//插入
status ListInsrt(sqlist& L, int i, Elemtype e) {
    //在顺序表L中第i个位置之前插入新的元素
    if (i<1 || i>L.length + 1) return ERROR;
    if (L.length > L.listsize) {
        // Elemtype*newbase= (Elemtype*)malloc(L.listsize + LISTINCREMENT * sizeof(Elemtype));
        // if (!newbase)exit(OVERFLOW);//存储空间增加失败退出
        L.listsize = L.listsize + LISTINCREMENT;//成功则增加增量
    }
    Elemtype* p = &(L.elem[i - 1]);//p为插入位置
    for (Elemtype* q = &(L.elem[L.length - 1]);q >= p;--q) {
        *(q + 1) = *q;
    }
    *p = e;
    ++L.length;
    return OK;
}
//删除
status Listdelete(sqlist& L, int i) {
    if (i<1 || i>L.length + 1)return ERROR;//判断是否在长度范围之内
    int e;
    int* x, * y;
    x = &(L.elem[i]);//删除元素的地址
    e = *x;
    y = L.elem + L.length - 1;//线性表尾的地址
    for (++x;x <= y;++x) {
        *(x - 1) = *x; //前移
    }
    L.length = L.length - 1;//线性表长度减一
    printf("删除的值为%d\n", e);
}
int main(void) {
    sqlist L2;
    int i, n;
    if (Initlist(L2)) {
        printf("请输入数据表的长度:\n");
        scanf_s("%d", &n);
        printf("请输入线性表的元素：\n");
        for (i = 0;i < n;i++) {
            scanf_s("%d", L2.elem + i);
        }
        L2.length = n;
        printf("数据表中的元素有");
        for (i = 0;i < n;i++) {
            printf("%2d", L2.elem[i]);
        }
        printf("\n");
    }
    Elemtype x, a, z;
    x = 0;a = 0;
    printf("输入插入位置");
    scanf_s("%d", &a);
    printf("\n");
    printf("输入插入元素的值");
    scanf_s("%d", &x);
    printf("在第%d位插入数据表的元素后数据表中的元素有\n", a);
    ListInsrt(L2, a, x);//调用插入函数
    for (int i = 0;i < L2.length;i++) {
        printf("%2d", L2.elem[i]);
    }
    printf("\n");
    printf("输入删除线性表的项");
    scanf_s("%d", &z);
    Listdelete(L2, z);//调用删除函数
    printf("在第%d位删除数据表的元素后数据表中的元素有\n", z);
    for (int i = 0;i < L2.length;i++) {
        printf("%2d", L2.elem[i]);
    }

}