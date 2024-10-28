#ifndef SQlist_H
#define SQlist_H

#define MAXSIZE 255

typedef int ElemType;

//定义顺序表的结构（静态）
typedef struct {
    ElemType data[MAXSIZE];
    int length; //顺序表的长度
}SqList;

//初始化表，构造一个空的顺序表
void InitList(SqList& L);

//求表长，返回顺序表L的长度，即L中的数据元素个数
int get_length(SqList L);

//在顺序表中查找第一个元素值为e的元素，并返回其位序(不是下标！是第几个)
int LocateElem(SqList L, ElemType e);

//按位序查找操作，获取表中第pos个位置的元素的值
ElemType get_element(SqList L, int pos);

//插入操作，在L中第pos个位置插入指定元素e
bool Insert(SqList& L, int pos, ElemType e);

//删除操作，删除pos处的元素，并用e返回元素
bool Delete(SqList& L, int pos, ElemType e);

//输出表中元素
void Print(SqList L);

//计算平均值并插入
void Average(SqList& L);

//选做题：向右移动n位
void Move(SqList& L,int n);

#endif