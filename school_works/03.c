#include <stdio.h>
#include <stdlib.h>

// 单链表结点结构体定义
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 尾插法创建带头结点的单链表
void createList(LinkList *L, int arr[], int n) {
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    LNode *r = *L;
    for (int i = 0; i < n; i++) {
        LNode *p = (LNode*)malloc(sizeof(LNode));
        p->data = arr[i];
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

// 核心算法：查找并输出最小值
void findMin(LinkList L) {
    if (L->next == NULL) {
        printf("链表为空，无法查找最小值。\n");
        return;
    }
    
    LNode *p = L->next;       // 从第一个实际结点开始
    int min = p->data;        // 假设第一个结点是最小的
    
    while (p != NULL) {
        if (p->data < min) {
            min = p->data;    // 更新最小值
        }
        p = p->next;
    }
    
    printf("链表中的最小值是：%d\n", min);
}

int main() {
    LinkList L;
    // 测试数据：无序正整数
    int arr[] = {15, 3, 28, 7, 10, 2, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    createList(&L, arr, n);
    printf("链表创建完毕。\n");
    findMin(L);
    
    return 0;
}